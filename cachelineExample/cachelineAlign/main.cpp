//
// Created by yuliangyong on 2022-04-03.
//

#include <iostream>
#include <thread>
#include <chrono>
#define NUM 10000000
using namespace std;
using namespace chrono;
struct Arr {
    int a[16];
};



int main() {
    Arr* arr = (Arr*) malloc(sizeof(Arr));

    std::cout<<"the address of arr: "<<arr<<std::endl;
    Arr* arrAligned = (Arr*)_aligned_malloc(sizeof(Arr), 64);
    for(int j = 0; j < 16; j++) {
        arr->a[j] = 0;
        arrAligned->a[j] = 0;
    }
    std::cout<<"the address of arrAligned: "<<arrAligned<<std::endl;
    {
        auto begin = steady_clock::now();
        for(int i = 0; i < NUM; i++) {
            for(int j = 0; j < 16; j++) {
                arr->a[j]++;
            }
        }
        auto end = steady_clock::now();
        nanoseconds elapse = duration_cast<nanoseconds>(end - begin);
        std::cout<<"Time cost: "
                 <<elapse.count()<<endl;        
    }
    {
        auto begin = steady_clock::now();
        for(int i = 0; i < NUM; i++) {
            for(int j = 0; j < 16; j++) {
                arrAligned->a[j]++;
            }
        }
        auto end = steady_clock::now();
        nanoseconds elapse = duration_cast<nanoseconds>(end - begin);
        std::cout<<"Time cost: "
                 <<elapse.count()<<endl;
    }
    return 0;
}