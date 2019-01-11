/**
 * @file ModernPimpl.h
 * @author bigillu
 * @brief Modern take on the classic pimpl idiom
 * @version 0.1
 * @date 2019-01-10
 *
 * @copyright Copyright (c) 2019
 *
 */

#include <memory>

/* Forward declaration */
class Impl;

class ModernPimpl {
 public:
  ModernPimpl();
  ~ModernPimpl();

  /* Copyable */
  ModernPimpl(const ModernPimpl& rhs);
  ModernPimpl& operator=(const ModernPimpl& rhs);
  /* Moovable */
  ModernPimpl(ModernPimpl&& rhs) noexcept;
  ModernPimpl& operator=(ModernPimpl&& rhs) noexcept;
  /* Const version of Print() */
  void Print() const;
  /* Non-const version of Print() */
  void Print();

 private:
  Impl* GetImpl() const { mImpl.get(); }
  Impl* GetImpl() { mImpl.get(); }
  /* Unique Pointer to Implementation */
  std::unique_ptr<Impl> mImpl;
};