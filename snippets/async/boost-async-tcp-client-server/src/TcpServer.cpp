/**
 * @file TcpServer.cpp
 * @author Abhimanyu Selvan
 * @brief Server Application
 * @version 0.1
 * @date 2019-03-09
 *
 * @copyright Copyright (c) 2019
 *
 */

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <iostream>
#include <memory>
#include <utility>

using boost::asio::ip::tcp;

class TcpConnection : public std::enable_shared_from_this<TcpConnection> {
 public:
  typedef std::shared_ptr<TcpConnection> sPointer;

  /**
   * @brief Static factory function that creates a new TcpConnection
   * by forwarding the arguments to a private TcpConnection constructor.
   *
   * Note: std::shared_ptr object must be created before shared_from_this() is
   * used. Using std::forward in the factory allows you to have multiple
   *  constructor prototypes while using a single Create function.
   *
   * @return std::shared_ptr<TcpConnection>
   */
  template <typename... T>
  static std::shared_ptr<TcpConnection> Create(T&&... t) {
    return std::shared_ptr<TcpConnection>(
        new TcpConnection(std::forward<T>(t)...));
  }

  /**
   * @brief Get the tcp::socket object
   *
   * @return Reference to tcp::socket
   */
  tcp::socket& GetSocket() { return mSocket; }

  /**
   * @brief Starts the asynchronous read and write operations.
   *
   */
  void Start() {
    // shared_from_this() safely creates shared pointers to "this".
    // class must inherit from std::enable_shared_from_this<T>
    auto self(shared_from_this());
    mSocket.async_read_some(
        boost::asio::buffer(mData, mData.size()),
        [this, self](boost::system::error_code ec, std::size_t /*length*/) {
          if (!ec) {
            boost::asio::async_write(
                mSocket, boost::asio::buffer(mData, mData.size()),
                [this, self](boost::system::error_code ec,
                             std::size_t /*length*/) {
                  if (!ec) {
                    std::cout << mData.data() << " received from the client"
                              << std::endl;
                  }
                });
          }
        });
  }

 private:
  TcpConnection(boost::asio::io_context& ioContext) : mSocket(ioContext) {}
  tcp::socket mSocket;
  std::array<char, 32> mData;
};

class TcpServer {
 public:
  /**
   * @brief Construct a new Tcp Server object
   *
   * @param io_context Reference to  boost io_context class
   * @param port port id
   */
  TcpServer(boost::asio::io_context& io_context, int port)
      : mAcceptor(io_context, tcp::endpoint(tcp::v4(), port)) {
    AcceptConnection();
  }

 private:
  /**
   * @brief Starts to accept new connections
   *
   */
  void AcceptConnection() {
    TcpConnection::sPointer newConnection =
        TcpConnection::Create(mAcceptor.get_executor().context());

    mAcceptor.async_accept(
        newConnection->GetSocket(),
        boost::bind(&TcpServer::HandleConnection, this, newConnection,
                    boost::asio::placeholders::error));
  }
  /**
   * @brief New connections handler.
   *
   */
  void HandleConnection(TcpConnection::sPointer newConnection,
                        const boost::system::error_code& error) {
    if (!error) {
      newConnection->Start();
    }

    AcceptConnection();
  }

  tcp::acceptor mAcceptor;
};

/**
 * @brief Entry point into the TcpServer Application
 *
 */
int main(int argc, char* argv[]) {
  try {
    if (argc != 2) {
      std::cerr << "Usage: ./server <port>" << std::endl;
      return EXIT_FAILURE;
    }
    boost::asio::io_context ioContext;
    TcpServer server(ioContext, std::stoi(argv[1]));
    ioContext.run();
  } catch (std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }
  return EXIT_SUCCESS;
}