# How to use
```c++
#include "GettopHook.hpp"

int main() {
  uintptr_t RState{};
  
  printf("RState: %08X\n", RState); //value of rstate before we hook gettop
  
  RState = Gettop::GetRState();
  
  printf("RState: %08X\n", RState); //value of after after we hook gettop
  
  return true;
}
```
