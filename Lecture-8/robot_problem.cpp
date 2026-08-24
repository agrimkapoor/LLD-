// robot problem 

// har robot ke kuch behaviors hote hai walk() talk() fly() : ab woh isme se kuch kar sakta hai kuch nhi

class Robot{
    public:
    // class ka dynamic hissa ( change ho rha hai)
    virtual void talk() = 0;
    virtual void walk() = 0;
    virtual void fly() = 0;

    // class ka static hissa
    virtual void projection() = 0;
};

// agar inheritance se kare toh combinations explode
// hamari class mei 3 fn change ho sakte toh uski alag se class banani hogi 
// dynamic hissa ko nikal ke alag classes mei daalna hoga

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

    void projection() override{
        cout<<" Companion ka projec";
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
    void projection() override{
        cout<<" worker ka projec";
    }
};

// problem : ham har combination ke liye class nhi bana sakte

#include <bits/stdc++.h>
using namespace std;



int main(){
  return 0;
}
