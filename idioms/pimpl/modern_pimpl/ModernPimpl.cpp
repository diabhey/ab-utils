/**
 * @file ModernPimpl.cpp
 * @author bigillu
 * @brief Implementation file of Modern Pimpl Idiom
 * @version 0.1
 * @date 2019-01-10
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "ModernPimpl.h"
#include <iostream>

class ModernPimpl::Impl {
 public:
  Impl() { std::cout << "\nImpl constructor called" << std::endl; }
  ~Impl() { std::cout << "Impl destructor called" << std::endl; }

  void ConstPrint() const {
    std::cout << "Print() const version called" << std::endl;
  }

  void Print() { std::cout << "Print() non-const version called" << std::endl; }
};

ModernPimpl::ModernPimpl() : mImpl(new Impl()) {
  std::cout << "ModernPimpl constructor called" << std::endl;
}

ModernPimpl::~ModernPimpl() {
  std::cout << "ModernPimpl destructor called" << std::endl;
}
ModernPimpl::ModernPimpl(const ModernPimpl &) {}
ModernPimpl &ModernPimpl::operator=(const ModernPimpl &) {}
ModernPimpl::ModernPimpl(ModernPimpl &&) noexcept = default;
ModernPimpl &ModernPimpl::operator=(ModernPimpl &&) noexcept = default;

void ModernPimpl::Print() const { GetImpl()->ConstPrint(); }

void ModernPimpl::Print() { GetImpl()->Print(); }