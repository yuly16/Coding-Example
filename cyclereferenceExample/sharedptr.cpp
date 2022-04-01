#include <iostream>
#include <memory>
using namespace std;

class A {
public:
    A() {
        
    };
    ~A() {
        cout<<"delete A."<<endl;        
    };
    shared_ptr<A> friends;
};

int main ()
{
    cout<<"--------------------"<<endl;
    // example 1
    {
        cout<<"example 1:"<<endl;
        shared_ptr<A> a = make_shared<A>();
        shared_ptr<A> b = make_shared<A>();
    }
    cout<<"--------------------"<<endl;
    {
        cout<<"example 2:"<<endl;
        shared_ptr<A> a = make_shared<A>();
        shared_ptr<A> b = make_shared<A>();
        a->friends = b;
        b->friends = a;
    }
    cout<<"--------------------"<<endl;
    return 0;
}