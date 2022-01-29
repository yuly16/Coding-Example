#include <iostream>
#include "add.h"
#include "sub.h"
#include <dlfcn.h>

int main() {
    std::cout<<"I am main!"<<std::endl;
    static auto handle = dlopen(nullptr, 0);

    typedef int (*fp)(int, int);
    auto create = (fp)dlsym(handle, "sub");
    if (create == nullptr) {
        std::cout<<dlerror()<<std::endl;
    } else {
        std::cout<<create(1,2)<<std::endl;
    }

    int c = sub(1,2);
    int d = add(1,2);
    return 0;
}