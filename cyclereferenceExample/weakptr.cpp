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
    weak_ptr<A> friends;
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
    {
        cout<<"access the value of a.friends:"<<endl;
        shared_ptr<A> a = make_shared<A>();
        shared_ptr<A> b = make_shared<A>();
        a->friends = b;
        b->friends = a;
        shared_ptr<A> c = a->friends.lock();
        if(c) {
            std::cout<<"a.friends is transformed into shared_ptr, the count is ";
            std::cout<<c.use_count()<<std::endl;
        }
        // 这里只有一个reference，因为b的friends是weak ptr，不算进use_count中。
        std::cout<<a.use_count()<<std::endl;
        
    }
    return 0;
}