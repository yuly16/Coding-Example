#include <iostream>
#include "include/add.h"
#include "sub.h"
extern "C" {
    int add(int a, int b) {
        std::cout << "now you are calling add function. " << std::endl;
        int d = sub(1,2);
        return a + b;
    }
}