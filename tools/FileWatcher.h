/**
 * @file FileWatcher.h
 * @author bigillu
 * @brief A tool to monitor the status of a file
 * using std::filesystem(C++17 onwards)
 * @version 0.1
 * @date 2019-01-18
 *
 * @copyright Copyright (c) 2019
 *
 */
#pragma once

#include <chrono>
#include <experimental/filesystem>
#include <string>
#include <unordered_map>

class FileWatcher {
 public:
  FileWatcher(const std::string& pathToWatch,
              std::chrono::duration<unsigned int, std::milli> delay)
      : mPathToWatch(pathToWatch), mDelay(delay) {
    for (auto& file :
         std::experimental::filesystem::recursive_directory_iterator(
             mPathToWatch)) {
      mFilePaths[file.path()] =
          std::experimental::filesystem::last_write_time(file.path());
    }
  }

 private:
  std::string mPathToWatch;
  std::chrono::duration<unsigned int, std::milli> mDelay;
  std::unordered_map<std::string, std::experimental::filesystem::file_time_type>
      mFilePaths;
};