#include <iostream>
#include <sstream>

struct IVirtualMachine {
  virtual std::string config() const = 0;
};

template <typename T> struct NameConfig : T {

private:
  std::string _name;

public:
  static_assert(std::is_base_of<IVirtualMachine, T>::value,
                "Template argument must be a IVirtualMachine");
  template <typename... Args>
  NameConfig(const std::string &name, Args... args)
      : _name(name), T(std::forward<Args>(args)...) {}

  std::string config() const override {
    std::ostringstream oss;
    oss << "**VM Configuration**\n"
        << "name: " << _name;
    return oss.str();
  }

  std::string rename(const std::string &newName) {
    _name = newName;
    std::ostringstream oss;
    oss << "**VM Configuration**\n"
        << "name: " << newName;
    return oss.str();
  }
};

template <typename T> struct CPUConfig : T {

private:
  int _cpus;

public:
  static_assert(std::is_base_of<IVirtualMachine, T>::value,
                "Template argument must be a IVirtualMachine");

  template <typename... Args>
  CPUConfig(const int cpu, Args... args)
      : _cpus(cpu), T(std::forward<Args>(args)...) {}

  std::string config() const override {
    std::ostringstream oss;
    oss << T::config() << "\ncpus: " << _cpus;
    return oss.str();
  }
};

template <typename T> struct MemoryConfig : T {

private:
  int _mem;

public:
  static_assert(std::is_base_of<IVirtualMachine, T>::value,
                "Template argument must be a IVirtualMachine");

  template <typename... Args>
  MemoryConfig(const int mem, Args... args)
      : _mem(mem), T(std::forward<Args>(args)...) {}

  std::string config() const override {
    std::ostringstream oss;
    oss << T::config() << "\nmemory: " << _mem;
    return oss.str();
  }
};

int main() {
  // With static decorator the limitation we faced in dynamic decorator where
  // rename() was inaccessible is now resolved.
  MemoryConfig<CPUConfig<NameConfig<IVirtualMachine>>> vm{16000, 4, "ubuntu"};
  std::cout << vm.config() << std::endl;
  vm.rename("centos");
  std::cout << vm.config() << std::endl;
}