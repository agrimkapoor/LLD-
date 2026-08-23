// robot problem 

// har robot ke kuch behaviors hote hai walk() talk() fly() : ab woh isme se kuch kar sakta hai kuch nhi

class Robot{
    public:
    virtual void talk() = 0;
    virtual void walk() = 0;
    virtual void fly() = 0;
};

// companion : cant fly baaki sab karega
class CompanionRobot : public Robot{
    public:
    void talk() override{
        cout<<" Can talk";
    }
    void walk() override{
        cout<<"Can walk";
    }
    void fly() override{
        cout<<"Can not fly";
    }
};

// worker robot : can just fly
class WorkerRobot : public Robot {
public:

    void walk() override {
        cout << "Cannot walk";
    }

    void talk() override {
        cout << "Cannot talk";
    }

    void fly() override {
        cout << "Flying";
    }
};

// problem : ham har combination ke liye class nhi bana sakte

#include <bits/stdc++.h>
using namespace std;



int main(){
  return 0;
}
