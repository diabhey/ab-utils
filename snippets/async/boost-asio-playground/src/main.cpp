/**
 * @file main.cpp
 * @author bigillu
 * @brief boost-asio playground
 * @version 0.1
 * @date 2019-07-11
 *
 * @copyright Copyright (c) 2019
 *
 */
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <iostream>

boost::asio::io_service io_service;

void WorkerThread() {
  std::cout << "Start Thread\n";
  io_service.run();
  std::cout << "Finish Thread\n";
}

int main(int argc, char* argv[]) {
  boost::shared_ptr<boost::asio::io_service::work> work(
      boost::make_shared<boost::asio::io_service::work>(io_service));

  std::cout << "Press [return] to exit.\n";
  std::vector<std::thread> worker_threads;
  for (int x = 0; x < 4; ++x) {
    worker_threads.emplace_back(boost::bind(WorkerThread));
  }

  std::cin.get();     // Wait to receive the exit input from the user
  io_service.stop();  // Stopping all the existing running services

  // Joining all the threads
  for (auto& thread : worker_threads) {
    if (thread.joinable()) {
      thread.join();
    }
  }

  return 0;
}