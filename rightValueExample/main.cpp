//
// Created by yuliangyong on 2022-01-28.
//

#include <iostream>
#include <vector>
#include <chrono>
#include <time.h>
using namespace std;
using namespace chrono;
#define MAX_SIZE 1000000000

enum copyType {
    SHALLOW,
    DEEP
};

class Array {
    public:
        Array() {
            data = new int[MAX_SIZE];
            for (int i = 0; i < MAX_SIZE; i++) {
                data[i] = 1;
            }
        }
        Array(Array const &arr, copyType cop) {
            if (cop == SHALLOW) {
                data = arr.data;
            } else {
                data = new int[MAX_SIZE];
                *data = *arr.data;
            }
        }
        Array(Array && arr) noexcept {
            data = arr.data;
            arr.data = nullptr;
        }
        ~Array() {
            if (data != nullptr) {
                delete data;
                data = nullptr;
            }
        }
    private:
        int* data;
};

int main() {
    Array a;
    auto start = steady_clock::now();
    Array b(a, SHALLOW);
    auto stage1 = steady_clock::now();
    nanoseconds elapse1 = duration_cast<nanoseconds>(stage1 - start);
    Array c(a, DEEP);
    auto stage2 = steady_clock::now();
    nanoseconds elapse2 = duration_cast<nanoseconds>(stage2 - stage1);
    Array d(std::move(a));
    auto stage3 = steady_clock::now();
    nanoseconds elapse3 = duration_cast<nanoseconds>(stage3 - stage2);
    std::cout<<"Time cost of left reference shallow copy: "
             <<elapse1.count()<<endl;
    std::cout<<"Time cost of left reference deep copy: "
        <<elapse2.count()<<endl;
    std::cout<<"Time cost of right reference deep copy: "
        <<elapse3.count()<<endl;
    return 0;
}