#include "FileStorage.hpp"
#include <iostream>
#include <memory>

FileStorage::FileStorage(){
    std::cerr << "[LOG] FileStorage created. ok.\n";
};

FileStorage::~FileStorage(){
    std::cerr << "[LOG] FileStorage deleted. ok.\n";
}

auto FileStorage::getInstance() -> FileStorage&{
    static auto instance = std::unique_ptr<FileStorage>{nullptr};

    if(not instance){
        instance.reset(new FileStorage);
    }
    return *instance.get();
}

auto FileStorage::AddFile(const std::string& file) -> void{
    _files.push_back(file);
}

auto FileStorage::ClearFiles() -> void{
    _files.clear();
}

auto FileStorage::ShowFiles() const -> void{
    for(const auto& file : _files){
        std::cout << "File= " << file << '\n';
    }
}

// Compile and Run: g++-7 -std=c++17 -o file FileStorage.cpp && ./file
int main(){
    FileStorage& store = FileStorage::getInstance();
    store.AddFile("debug.log");
    store.AddFile("test.log");
    store.AddFile("sim.log");
    FileStorage& storeClone = FileStorage::getInstance(); 
    storeClone.ShowFiles();
    storeClone.ClearFiles();
    return 0;
}