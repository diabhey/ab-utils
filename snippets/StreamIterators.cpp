/**
 * @file StreamIterators.cpp
 * @author bigillu
 * @brief Test application to demonstrate the use of stream iterators.
 * The application copies unique contents from src file to destination file
 * @version 0.1
 * @date 2019-01-23
 *
 * @copyright Copyright (c) 2019
 *
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <set>

bool UniqueFileCopy(const std::string& src, const std::string& dst) {
  std::ifstream is{src};
  std::ofstream os{dst};

  std::istream_iterator<std::string> isItr{is};
  std::istream_iterator<std::string> eos{};
  std::ostream_iterator<std::string> osItr{os, "\n"};
  std::set<std::string> set{isItr, eos};
  std::copy(std::begin(set), std::end(set), osItr);

  return !is.eof() || !os;
}

int main() {
  std::string src, dst;
  std::cin >> src >> dst;
  if (not UniqueFileCopy(src, dst)) {
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}