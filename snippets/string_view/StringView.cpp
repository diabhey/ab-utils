/**
 * @file StringView.cpp
 * @author bigillu
 * @brief Demonstration of std::string_view performance.
 * Compilation: g++-7 -Wall -Wextra -Werror -std=c++17 StringView.cpp
 * Execution: ./a.out
 * @version 0.1
 * @date 2019-02-02
 *
 * @copyright Copyright (c) 2019
 *
 */
#include <algorithm>
#include <iostream>
#include <string_view>
#include <vector>

void* operator new(std::size_t n) {
  std::cout << "[allocating " << n << " bytes]\n";
  return malloc(n);
}

std::vector<std::string> extract(const std::string& str,
                                 const std::string& delims = " ") {
  std::vector<std::string> output;
  auto first = std::cbegin(str);

  while (first != std::cend(str)) {
    const auto second = std::find_first_of(
        first, std::cend(str), std::cbegin(delims), std::cend(delims));

    if (first != second) {
      output.emplace_back(first, second);
    }

    if (second == std::cend(str)) {
      break;
    }
    first = std::next(second);
  }

  return output;
}

std::vector<std::string_view> extractSV(std::string_view strv,
                                        std::string_view delims = " ") {
  std::vector<std::string_view> output;

  size_t first = 0;

  while (first < strv.size()) {
    const auto second = strv.find_first_of(delims, first);

    if (first != second) {
      output.emplace_back(strv.substr(first, second - first));
    }

    if (second == std::string_view::npos) break;
    first = second + 1;
  }

  return output;
}

int main() {
  std::string txt{
      "A) In recent years we have all been exposed to dire media reports "
      "concerning the impending demise of global coal and oil reserves, but "
      "the depletion of another key non-renewable resource continues without "
      "receiving much press at all. Helium – an inert, odourless, monatomic "
      "element known to lay people as the substance that makes balloons float "
      "and voices squeak when inhaled – could be gone from this planet within "
      "a generation."};

  std::cout << "*********std::string**********" << std::endl;
  auto s = extract(txt);
  std::cout << "*********std::string_view**********" << std::endl;
  auto sv = extractSV(txt);

  return EXIT_SUCCESS;
}
