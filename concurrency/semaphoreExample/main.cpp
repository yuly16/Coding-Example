#include <iostream>
#include <thread>
#include <chrono>
#include <semaphore.h>


sem_t sema1;
sem_t sema2;
void printA() {
    for(int i = 0; i < 100; i++) {
        sem_wait(&sema1);
        std::cout<<"A";
        sem_post(&sema2);
    }
    
}

void printB() {
    for(int i = 0; i < 100; i++) {
        sem_wait(&sema2);
        std::cout<<"B";
        sem_post(&sema1);
    }
    
}

void go() {
    // this code prints "ABABAB..."
    sem_post(&sema1);
    
    // this code prints "BABABA..."
    // sem_post(&sema2);
}
int main() {
    sem_init(&sema1, 0, 0);
    sem_init(&sema2, 0, 0);
    std::thread A(printA), B(printB);

    go();
    A.join();
    B.join();
    std::cout<<"\n";
    return 0;
}