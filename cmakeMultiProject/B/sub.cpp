//
// Created by yuliangyong on 2021-12-28.
//

#include <iostream>
#include "include/sub.h"

extern "C" {
    int sub(int a, int b) {
        std::cout<<"now you are calling sub function"<<std::endl;
        return a - b;
    }
    void happyBirthday() {
        std::cout<<"happy birthday to you!"<<std::endl;
    }
}
