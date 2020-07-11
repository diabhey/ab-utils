# pragma once 
#include <string>
#include <deque>

class FileStorage {
public:
    ~FileStorage();
    FileStorage(const FileStorage&) = delete; // Disallow copy
    static auto getInstance() -> FileStorage&;
    auto AddFile(const std::string& file) -> void;
    auto ClearFiles() -> void;
    auto ShowFiles() const -> void;
private:
    FileStorage();
    std::deque<std::string> _files;
};