/**
 * @file AnyContainer.h
 * @author bigillu
 * @brief Generic Container that can hold any type of STL container.
 * @version 0.1
 * @date 2018-12-02
 *
 * @copyright Copyright (c) 2018
 *
 */
#include <iostream>
#include <memory>
/**
 * @brief Magic Interface that holds any type of STL container
 * or even custom container.
 * hint: As long as the client implements a size() method ;)
 * A glue between runtime and compile time polymorphism
 *
 */
class AnyContainer {
 public:
  template <typename T>
  AnyContainer(T &&rhs)
      : mImpl(std::make_unique<Type<T>>(std::forward<T>(rhs))) {}
  size_t size() const { return mImpl->size(); }

 private:
  struct BaseType {
    virtual ~BaseType() {}
    virtual size_t size() const = 0;
  };
  template <typename T>
  struct Type : BaseType {
    Type(const T &value) : mValue(value) {}
    size_t size() const override { return mValue.size(); }
    T mValue;
  };
  std::unique_ptr<const BaseType> mImpl;
};