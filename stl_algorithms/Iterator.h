/**
 * @brief Custom Iterator Implementation
 *
 * @tparam T value type
 */
template <typename T> class Iterator {
public:
  typedef Iterator self_type;
  typedef T value_type;
  typedef T &reference;
  typedef T *pointer;
  /**
   * @brief Construct a new Iterator object
   *
   * @param ptr
   */
  Iterator(reference ptr) : mPtr(ptr) {}
  /**
   * @brief
   *
   * @return const reference
   */
  const reference operator*() { return *mPtr; }
  /**
   * @brief
   *
   * @return const pointer
   */
  const pointer operator->() { return mPtr; }
  /**
   * @brief prefix operator
   *
   * @return self_type
   */
  self_type operator++() {
    mPtr++;
    return *this;
  }
  /**
   * @brief post-fix operator
   *
   * @return self_type
   */
  self_type operator++(int) {
    self_type i = *this;
    mPtr++;
    return i;
  }
  /**
   * @brief
   *
   * @param rhs
   * @return self_type
   */
  self_type operator=(const self_type &rhs) {
    mPtr = rhs.mPtr;
    return *this;
  }
  /**
   * @brief
   *
   * @param rhs
   * @return true
   * @return false
   */
  bool operator==(const self_type &rhs) { return mPtr == rhs.mPtr; }
  /**
   * @brief
   *
   * @param rhs
   * @return true
   * @return false
   */
  bool operator!=(const self_type &rhs) { return mPtr != rhs.mPtr; }

private:
  pointer mPtr;
};