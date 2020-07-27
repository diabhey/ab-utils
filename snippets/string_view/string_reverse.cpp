#include <algorithm>
#include <cassert>
#include <iostream>
#include <string.h>
#include <string>
#include <string_view>

void *operator new(std::size_t count) {
  std::cout << count << " bytes allocated" << std::endl;
  return malloc(count);
}

void reverseCString(char *str, int len) {
  std::cout << "reverseCString: ";
  for (int i = 0; i < len / 2; i++) {
    std::swap(str[i], str[len - i - 1]);
  }

  for (int i = 0; i <= len; i++) {
    std::cout << str[i];
  }
  std::cout << "\n";
}

void reverseString(std::string &str) {
  int n = str.length();
  // Swap character starting from two
  for (int i = 0; i < n / 2; i++) {
    std::swap(str[i], str[n - i - 1]);
  }

  std::cout << "reverseString: " << str << "\n";
}

void reverse(std::string &str) {
  std::reverse(str.begin(), str.end());
  std::cout << "reverse: " << str << "\n";
}

int main() {

  std::string one = "12345678910111213141516";
  std::string two = "12345678910111213141516";
  auto cstr = two.c_str();
  char buf[] = "12345678910111213141516";
  reverseCString(buf, strlen(buf));
  reverseString(one);
  reverse(two);
  // On Construction
  std::string test = "12345678910111213141516";
  std::string rev(test.rbegin(), test.rend());
  std::cout << "reverse: " << rev << "\n";

  std::string_view view = "12345678910111213141516";
  std::string revView(view.rbegin(), view.rend());

}
