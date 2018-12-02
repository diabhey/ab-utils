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
#include <memory>
#include <type_traits>
#include <typeindex>
#include <typeinfo>
#include <utility>
/**
 * @brief
 *
 */
class AnyContainer {
 public:
  template <typename T>
  AnyContainer(T &&rhs)
      : mImpl(std::make_unique<Type<T>>(std::forward<T>(rhs))) {}
  bool empty() const { return mImpl->empty(); }
 private:
  struct BaseType {
    virtual ~BaseType() {}
    virtual bool empty() const = 0;
  };
  template <typename T>
  struct Type : BaseType {
    Type(const T &value) : mValue(value) {}
    bool empty() const override { return mValue.empty(); }
    T mValue;
  };
  std::unique_ptr<BaseType> mImpl;
};