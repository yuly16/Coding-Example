//
// Created by yuliangyong on 2022-04-03.
//

#include <iostream>
#include <thread>
#include <chrono>
#define NUM 1000000000
using namespace std;
using namespace chrono;
struct Arr {
    int a;
    int b;
    int c;
};

Arr arr;

struct ArrPad {
    int a;
    int apad[15];
    int b;
    int c;
};

ArrPad arrpad;
void access_array(int loc) {
    if(loc == 0) {
        for(int i = 0; i < NUM; i++) {
            arr.a++;
        }
    } else if(loc == 1) {
        for(int i = 0; i < NUM; i++) {
            arr.b++;
        }
    }
}
void access_array_pad(int loc) {
    if(loc == 0) {
        for(int i = 0; i < NUM; i++) {
            arrpad.a++;
        }
    } else if(loc == 1) {
        for(int i = 0; i < NUM; i++) {
            arrpad.b++;
        }
    }
}
int main() {
    arr.a = 1;
    arr.b = 2;
    arr.c = 3;
    arrpad.a = 1;
    arrpad.b = 2;
    arrpad.c = 3;

    {
        auto begin = steady_clock::now();
        auto th1 = thread(access_array, 0);
        auto th2 = thread(access_array, 1);
        th1.join();
        th2.join();
        auto end = steady_clock::now();
        nanoseconds elapse = duration_cast<nanoseconds>(end - begin);
        std::cout<<"Time cost: "
                 <<elapse.count()<<endl;        
    }
    {
        auto begin = steady_clock::now();
        auto th1 = thread(access_array_pad, 0);
        auto th2 = thread(access_array_pad, 1);
        th1.join();
        th2.join();
        auto end = steady_clock::now();
        nanoseconds elapse = duration_cast<nanoseconds>(end - begin);
        std::cout<<"Time cost after padding: "
                 <<elapse.count()<<endl;
    }
    return 0;
}