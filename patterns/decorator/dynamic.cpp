#include <iostream>
#include <sstream>

struct IVirtualMachine {
  virtual std::string config() const = 0;
};

struct VirtualMachine : public IVirtualMachine {
  VirtualMachine(std::string name) : _name(name) {}

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

private:
  std::string _name;
};

struct CPUConfig : IVirtualMachine {
private:
  IVirtualMachine &_vm;
  int _cpus;

public:
  CPUConfig(IVirtualMachine &vm, const int cpu) : _vm(vm), _cpus(cpu) {}

  std::string config() const override {
    std::ostringstream oss;
    oss << _vm.config() << "\ncpus: " << _cpus;
    return oss.str();
  }
};

struct MemoryConfig : IVirtualMachine {
private:
  IVirtualMachine &_vm;
  int _mem;

public:
  MemoryConfig(IVirtualMachine &vm, const int mem) : _vm(vm), _mem(mem) {}

  std::string config() const override {
    std::ostringstream oss;
    oss << _vm.config() << "\nmemory: " << _mem;
    return oss.str();
  }
};

int main() {
  // Note: Downside to this approach is that mem doesn't have access to
  // reconfig() of the VirtualMachine struct as it doesnt implement reconfig()
  // method.
  VirtualMachine vm("ubuntu");
  CPUConfig cpu(vm, 4);
  MemoryConfig mem(cpu, 16000);
  std::cout << mem.config() << std::endl;
  //   mem.rename() // Not possible!!
}