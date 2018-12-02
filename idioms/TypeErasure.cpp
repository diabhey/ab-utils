#include <iostream>
#include <vector>
#include "TypeErasure.h"

struct anything {
  void exists() const { std::cout << "anything" << std::endl; }
};

struct something {
  void exists() const { std::cout << "something" << std::endl; }
};

int main() {
  std::vector<TypeErasure> te;

  te.push_back(anything());
  te.push_back(something());
  te.push_back(std::move(anything()));
  for (const auto& itr : te) {
    itr.exists();
  }
  return 0;
}
