/**
 * @file FileOperator.cpp
 * @author bigillu
 * @brief Threaded file operator using std::condition_variable
 * event handling mechanism
 * Code compilation:
 * @version 0.1
 * @date 2019-03-14
 *
 * @copyright Copyright (c) 2019
 *
 */
#include <chrono>
#include <condition_variable>
#include <fstream>
#include <iostream>
#include <mutex>
#include <thread>

class FileOperator {
 public:
  FileOperator(std::string& filename)
      : mFileHandler(filename, std::ios::in | std::ios::out | std::ios::trunc |
                                   std::ios::binary) {
    if (not mFileHandler.is_open()) {
      throw std::runtime_error("Failed to open the file \n");
    }
  }

  void Read() {
    std::unique_lock<std::mutex> guard(mMutex);
    while (mCondVar.wait_for(guard, std::chrono::seconds(5)) ==
           std::cv_status::timeout) {
      mFileHandler.seekg(0, std::ios::beg);
      std::cout << "File contains: " << mFileHandler.rdbuf() << std::endl;
    }
    exit(0);
  }

  void Write() {
    std::cout << "Writing contents to a file" << std::endl;
    std::lock_guard<std::mutex> lock(mMutex);
    for (uint i = 0; i < 100000; ++i) {
      std::string word = "Hi, there! ";
      mFileHandler.write(word.c_str(), sizeof(word));
    }
  }

 private:
  std::condition_variable mCondVar;
  std::fstream mFileHandler;
  std::mutex mMutex;
};

/**
 * @brief Entry point into FileOperator
 */
int main(int argc, char* argv[]) {
  try {
    if (argc != 2) {
      std::cerr << "Usage: ./FileOperator <file>" << std::endl;
    }

    std::string filename(argv[1]);
    FileOperator rw(filename);

    std::thread writeThread(&FileOperator::Write, &rw);
    std::thread readThread(&FileOperator::Read, &rw);

    writeThread.join();
    readThread.join();

  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  return EXIT_SUCCESS;
}
