#include <iostream>

class File{
public:
    ~File(){
        std::cout << "File Destructor\n";
    }
    auto show() const -> void{
        std::cerr << "[LOG] File " << _name << _ext << " created. ok.\n";
    }
    friend class FileBuilder;
private:
    File(){
        std::cout << "File Constructor\n";
    }
    std::string _name;
    std::string _ext;
};

class FileBuilder{
public:
    FileBuilder(){
        std::cout << "FileBuilder Constructor\n";
    }

    ~FileBuilder(){
        std::cout << "FileBuilder Destructor\n";
    }    

    auto setName(const std::string& name) -> FileBuilder&{
        _data._name = name;
        return *this;
    }
    auto setExt(const std::string& ext) -> FileBuilder&{
        _data._ext = ext;
        return *this;
    }
    auto build() -> File{
        return this->_data;
    }    
private:
    File _data{};
};

// Compile and Run: g++-7 -std=c++17 -o file File.cpp && ./file
int main(){
    auto main = FileBuilder().setName("main").setExt(".cpp").build();
    auto debug = FileBuilder().setName("debug").setExt(".log").build();
    main.show();
    debug.show();
    return 0;
}