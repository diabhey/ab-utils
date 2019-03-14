/**
 * @file ReadWrite.cpp
 * @author bigillu
 * @brief Threaded reader-writer using std::condition_variable
 * event handling mechanism
 * Code compilation:
 * @version 0.1
 * @date 2019-03-14
 *
 * @copyright Copyright (c) 2019
 *
 */
#include <algorithm>
#include <atomic>
#include <condition_variable>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <mutex>
#include <thread>

class ReadWrite {
 public:
  ReadWrite(std::string& src, std::string& dst)
      : mDataRead(false), mIs{src}, mOs{dst} {}

  void Validate() {
    if (not mIs.is_open()) {
      std::cerr << "File not found\n";
      exit(1); // TODO: Gracefully exit the thread.
    }
    std::lock_guard<std::mutex> guard(mMutex);
    mDataRead = true;
    mCondVar.notify_one();
  }

  void Write() {
    std::unique_lock<std::mutex> lock(mMutex);
    mCondVar.wait(lock, std::bind(&ReadWrite::IsDataRead, this));
    std::copy(std::istreambuf_iterator<char>(mIs),
              std::istreambuf_iterator<char>(),
              std::ostream_iterator<char>(mOs));
  }

 private:
  bool IsDataRead() { return mDataRead; }
  std::atomic<bool> mDataRead;
  std::ifstream mIs;
  std::ofstream mOs;
  std::mutex mMutex;
  std::condition_variable mCondVar;
};

/**
 * @brief Entry point into ReadWrite
 */
int main(int argc, char* argv[]) {
  try {
    if (argc != 3) {
      std::cerr << "Usage: ./ReadWrite <src> <dst>" << std::endl;
    }

    std::string readFile(argv[1]);
    std::string writeFile(argv[2]);
    ReadWrite rw(readFile, writeFile);

    std::thread readThread(&ReadWrite::Validate, &rw);
    std::thread writeThread(&ReadWrite::Write, &rw);
    readThread.join();
    writeThread.join();

  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  return EXIT_SUCCESS;
}