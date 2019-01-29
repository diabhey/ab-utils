/**
 * @file StateComparator.cpp
 * @author bigillu
 * @brief State machine comparator using Curiously Recurring Template Pattern
 * (CRTP)
 * Code compilation: g++-7 -std=c++17 StateComparator.cpp
 * @version 0.1
 * @date 2019-01-29
 *
 * @copyright Copyright (c) 2019
 *
 */
#include <iostream>
#include <utility>

namespace crtp {

template <typename Derived>
struct Comparator {};

template <typename Derived>
bool operator==(const Comparator<Derived>& o1, const Comparator<Derived>& o2) {
  const auto& d1 = static_cast<const Derived&>(o1);
  const auto& d2 = static_cast<const Derived&>(o2);

  return !(d1 < d2) && !(d2 < d1);
}

template <typename Derived>
bool operator!=(const Comparator<Derived>& o1, const Comparator<Derived>& o2) {
  return !(o1 == o2);
}

class StateMachine : public Comparator<StateMachine> {
 public:
  StateMachine(const std::pair<std::string, double>& p) : mPair(p) {}

  friend bool operator<(const StateMachine& s1, const StateMachine& s2);

 private:
  std::pair<std::string, double> mPair;
};

bool operator<(const StateMachine& s1, const StateMachine& s2) {
  return s1.mPair.second < s2.mPair.second;
}
}  // namespace crtp

int main() {
  crtp::StateMachine sm1(std::make_pair("classOne", 12.3));
  crtp::StateMachine sm2(std::make_pair("classOne", 12.4));

  if (not(sm1 == sm2)) {
    std::cout << "State has changed!\n" << std::endl;
  }
  return EXIT_SUCCESS;
}
