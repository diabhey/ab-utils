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
#include <functional>
#include <iomanip>
#include <string>
#include <thread>
#include <unordered_map>
#include <utility>

enum class FileStatus { created, modified, erased };
/**
 * @brief
 *
 */
class FileWatcher {
 public:
  using file_size = uint;
  FileWatcher(const std::string& pathToWatch,
              std::chrono::duration<unsigned int, std::milli> delay)
      : mPathToWatch(pathToWatch), mDelay(delay) {
    for (auto& file :
         std::experimental::filesystem::recursive_directory_iterator(
             mPathToWatch)) {
      mFilePaths[file.path()].first =
          std::experimental::filesystem::last_write_time(file);
      mFilePaths[file.path()].second =
          std::experimental::filesystem::file_size(file);
    }
  }
  /**
   * @brief
   *
   * @param exec
   */
  void start(const std::function<void(std::string, FileStatus)>& exec) {
    while (mRunning) {
      // Wait for the delay
      std::this_thread::sleep_for(mDelay);
      // Check to see if an existing file has been erased.
      for (auto& file : mFilePaths) {
        if (!std::experimental::filesystem::exists(file.first)) {
          std::cout << file.first << " was erased" << std::endl;
          exec(file.first, FileStatus::erased);
          mFilePaths.erase(file.first);
          break;
        }
      }
      // Check to see if a file has been created or modified.
      for (auto& file :
           std::experimental::filesystem::recursive_directory_iterator(
               mPathToWatch)) {
        auto file_latest_write_time =
            std::experimental::filesystem::last_write_time(file);
        auto ftime = decltype(file_latest_write_time)::clock::to_time_t(
            file_latest_write_time);
        auto file_size = std::experimental::filesystem::file_size(file);

        if (not(mFilePaths.find(file.path()) != mFilePaths.end())) {
          mFilePaths[file.path()].first = file_latest_write_time;
          mFilePaths[file.path()].second = file_size;
          std::cout << "Created: " << file.path().filename() << " " << file_size
                    << " " << std::asctime(std::localtime(&ftime)) << std::endl;
          exec(file.path(), FileStatus::created);
        }
        // File modification check
        else {
          if (mFilePaths[file.path()].first != file_latest_write_time) {
            mFilePaths[file.path()].first = file_latest_write_time;
            mFilePaths[file.path()].second = file_size;
            std::cout << "Modified: " << file.path().filename() << " "
                      << file_size << " "
                      << std::asctime(std::localtime(&ftime)) << std::endl;
            exec(file.path(), FileStatus::modified);
          }
        }
      }
    }
  }

 private:
  std::string mPathToWatch;
  bool mRunning = true;
  std::chrono::duration<unsigned int, std::milli> mDelay;
  std::unordered_map<
      std::string,
      std::pair<std::experimental::filesystem::file_time_type, file_size>>
      mFilePaths;
};
