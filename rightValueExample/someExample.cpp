#include <iostream>

int *b = new int(2);
int& a1() {
    return *b;
}

// Under the hood the compiler creates an hidden variable for you (i.e. an lvalue)
// where to store the original literal constant, and then bounds that hidden variable
// to your reference.
void a2(const int &b1) {
    std::cout << "I am a2. the parameter is " << b1 << std::endl;
    std::cout << &b1 << std::endl;
}

int main() {
    int a = 1;
    int b = 2;
    int&& aa = std::move(a);
    int&& bb = std::move(b);

    std::cout << &a <<std::endl;
    std::cout << &aa <<std::endl;

    aa = bb;

    std::cout<<a<<std::endl;

    return 0;
}
