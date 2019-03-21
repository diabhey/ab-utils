/**
 * @file CmdLineReader.cpp
 * @author bigillu
 * @brief Command Line Parser using std::variant
 * Code compilation: g++ -std=c++1z -Wall -pedantic CmdLineReader.cpp
 * Code execution: ./a.out -iparam 100 -sparam Value
 * Code can be tested at http://coliru.stacked-crooked.com/
 * @version 0.1
 * @date 2019-02-14
 *
 * @copyright Copyright (c) 2019
 *
 */
#include <charconv>
#include <cstring>
#include <iostream>
#include <map>
#include <optional>
#include <variant>

class CmdLineReader {
 public:
  using Args = std::variant<int, std::string>;

  explicit CmdLineReader(int argc, char** argv) { ParseArgs(argc, argv); }

  std::optional<Args> Find(const std::string& paramType) const {
    auto it = mParsedArgs.find(paramType);

    if (it != mParsedArgs.end()) {
      return it->second;
    }
    return std::nullopt;
  }

 private:
  std::map<std::string, Args> mParsedArgs;

  Args ParseString(char* args) {
    int rVal = 0;
    auto res = std::from_chars(args, args + strlen(args), rVal);
    if (res.ec == std::errc::invalid_argument) {
      return std::string(args);
    }

    return rVal;
  }

  void ParseArgs(int argc, char** argv) {
    for (int i = 1; i < argc; i += 2) {
      if (argv[i][0] != '-') {
        throw std::runtime_error("Invalid command name");
      }
      mParsedArgs[argv[i] + 1] = ParseString(argv[i + 1]);
    }
  }
};

int main(int argc, char** argv) {
  CmdLineReader cmd(argc, argv);

  try {
    auto arg = cmd.Find("iparam");
    if (arg && std::holds_alternative<int>(*arg)) {
      std::cout << "iparam is: " << std::get<int>(*arg) << std::endl;
    }

    arg = cmd.Find("sparam");
    if (arg && std::holds_alternative<std::string>(*arg)) {
      std::cout << "sparam is: " << std::get<std::string>(*arg) << std::endl;
    }
  } catch (std::runtime_error& err) {
    std::cout << err.what() << std::endl;
  }
}
