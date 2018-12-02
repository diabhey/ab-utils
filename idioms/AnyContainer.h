/**
 * @file AnyContainer.h
 * @author your name (you@domain.com)
 * @brief
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
  template <typename T>
  T &get() const{
    if (std::type_index(typeid(T)) == std::type_index(mImpl->type_info())) {
      return static_cast<Type<T> &>(*mImpl).mValue;
    }
    throw std::bad_cast();
  }

 private:
  struct BaseType {
    virtual ~BaseType() {}
    virtual bool empty() const = 0;
    virtual const std::type_info &type_info() const = 0;
  };
  template <typename T>
  struct Type : BaseType {
    Type(const T &value) : mValue(value) {}
    bool empty() const override { return mValue.empty(); }
    const std::type_info &type_info() const override { return typeid(T); }
    T mValue;
  };
  std::unique_ptr<BaseType> mImpl;
};