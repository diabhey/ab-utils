/**
 * @file TcpClient.cpp
 * @author Abhimanyu Selvan
 * @brief Client Application
 * @version 0.1
 * @date 2019-03-03
 *
 * @copyright Copyright (c) 2019
 *
 */

#include <boost/asio.hpp>
#include <iostream>
#include <thread>

using boost::asio::ip::tcp;

class TcpClient {
 public:
  /**
   * @brief Construct a new Tcp Client object
   *
   * @param context Reference to  boost io_context class
   * @param endPoints Reference to resolved endpoints
   */
  TcpClient(boost::asio::io_context& context,
            const tcp::resolver::results_type& endPoints)
      : mIOContext(context), mSocket(context) {
    Connect(endPoints);
  }

  /**
   * @brief Close the socket the client is connected to
   *
   */
  void Disconnect() {
    boost::asio::post(mIOContext, [this]() { mSocket.close(); });
  }

  /**
   * @brief Forward the message to be sent to the server
   *
   * @param msg Contains the message to be sent
   */
  void SendMessage(std::string& msg) {
    boost::asio::async_write(
        mSocket, boost::asio::buffer(msg, msg.size()),
        [this](boost::system::error_code ec, std::size_t /*length*/) {});
  }

 private:
  /**
   * @brief Connect to the resolved endpoint
   *
   * @param endPoints Reference to resolved endpoints
   */
  void Connect(const tcp::resolver::results_type& endPoints) {
    boost::asio::async_connect(
        mSocket, endPoints,
        [this](boost::system::error_code ec, tcp::endpoint) {
          if (!ec) {
            ReadMessage();
          } else {
            std::cout << ec.message() << std::endl;
          }
        });
  }

  /**
   * @brief Read the response from the server
   */
  void ReadMessage() {
    std::array<char, 32> reply;
    boost::system::error_code error;
    size_t length = mSocket.read_some(boost::asio::buffer(reply), error);
    std::array<char, 32> msg = {"Hello world"};
    auto isEqual = std::equal(msg.begin(), msg.end(), reply.begin());
    if (!isEqual) {
      std::cerr << "Incorrect info, \"" << reply.data()
                << "\" was received at the server!\n"
                << "Try again with \"Hello world\"" << std::endl;
      return;
    }
    std::cout << "Correct info, \"" << reply.data()
              << "\" was received at the server!" << std::endl;
  }

 private:
  boost::asio::io_context& mIOContext;
  tcp::socket mSocket;
};

/**
 * @brief Entry point into the TcpClient Application
 *
 */
int main(int argc, char* argv[]) {
  try {
    if (argc != 3) {
      std::cerr << "Usage: ./client <host> <port>" << std::endl;
      return EXIT_FAILURE;
    }

    boost::asio::io_context ioContext;
    tcp::socket socket(ioContext);
    tcp::resolver resolver(ioContext);

    auto endPoints = resolver.resolve(argv[1], argv[2]);
    TcpClient client(ioContext, endPoints);
    std::thread t([&ioContext]() { ioContext.run(); });

    std::cout << "Enter message: ";
    std::string message;
    std::getline(std::cin, message);
    client.SendMessage(message);
    client.Disconnect();
    t.join();

  } catch (std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }
  return EXIT_SUCCESS;
}
