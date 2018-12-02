#pragma once
#include <iostream>
#include <memory>

class TypeErasure {
 public:
  template <typename T>
  TypeErasure(T&& rhs)
      : mImpl(new Type<std::decay_t<T>>(std::forward<T>(rhs))) {}
  void exists() const { mImpl->exists(); }

 private:
  struct BaseType {
    virtual ~BaseType() {}
    virtual void exists() const = 0;
  };
  template <typename T>
  struct Type : BaseType {
    Type(const T& value) : mHoldType(value) {}
    void exists() const override { mHoldType.exists(); }
    T mHoldType;
  };

  std::unique_ptr<BaseType> mImpl;
};