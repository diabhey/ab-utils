/**
 * @file FileWatchTester.cpp
 * @author bigillu
 * @brief File Watcher tester application
 * Code compilation
 *   g++ -std=c++17 -Wall -pedantic FileWatchTester.cpp -lstdc++fs
 *   clang++ -std=c++17 -stdlib=libc++ -Wall -pedantic FileWatchTester.cpp
 * -lc++fs
 * @version 0.1
 * @date 2019-01-21
 *
 * @copyright Copyright (c) 2019
 */

#include <iostream>
#include "FileWatcher.h"

int main() {
  // Create a FileWatcher instance that will check the current folder for
  // changes every 5 seconds
  FileWatcher fw{"./", std::chrono::milliseconds(5000)};

  // Start monitoring a folder for changes and (in case of changes)
  // run a user provided lambda function
  fw.start([](std::string pathToWatch, FileStatus status) -> void {
    // Process only regular files, all other file types are ignored
    if (!std::experimental::filesystem::is_regular_file(
            std::experimental::filesystem::path(pathToWatch)) &&
        status != FileStatus::erased) {
      return;
    }

    switch (status) {
      case FileStatus::created:
        std::cout << "File created: " << pathToWatch << '\n';
        break;
      case FileStatus::modified:
        std::cout << "File modified: " << pathToWatch << '\n';
        break;
      case FileStatus::erased:
        std::cout << "File erased: " << pathToWatch << '\n';
        break;
      default:
        std::cout << "Error! Unknown file status.\n";
    }
  });
}