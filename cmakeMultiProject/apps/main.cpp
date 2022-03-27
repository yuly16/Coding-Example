#include <iostream>
#include "add.h"
#include "sub.h"


int main() {
    std::cout<<"I am main!"<<std::endl;


    int c = sub(1,2);
    int d = add(1,2);
    return 0;
}