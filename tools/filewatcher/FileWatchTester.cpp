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

/**
 * @brief
 *
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char* argv[]) {
  try {
    if (argc != 2) {
      std::cerr << "Usage: ./a.out <directory path to monitor>" << std::endl;
      return EXIT_FAILURE;
    }
    // Create a FileWatcher instance that will check the current diretory for
    // changes every 5 seconds
    FileWatcher fw{std::string(argv[1]), std::chrono::seconds(1)};

    do {
      // Start monitoring the files in a directory.
      fw.start([](const std::string& pathToWatch, FileStatus status) -> void {
        // Process only regular files, all other file types are ignored
        if (!std::experimental::filesystem::is_regular_file(
                std::experimental::filesystem::path(pathToWatch)) &&
            status != FileStatus::erased) {
          return;
        }
      });
    } while (std::cin.get() != '\n');
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  return EXIT_SUCCESS;
}

/**
 * @TODO
 *  1. Use a static map to hold the list of files and counter for the frequency

 */

// Demo of sending data via temporary files.  The default is to send data to
// gnuplot directly through stdin.
//
// Compile it with:
//   g++ -o example-tmpfile example-tmpfile.cc -lboost_iostreams -lboost_system
//   -lboost_filesystem
