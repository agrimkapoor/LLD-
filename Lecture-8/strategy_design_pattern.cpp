#include <bits/stdc++.h>
using namespace std;

// robot ke walk talk fly behavior can change 
// toh make independent class for that

class WalkableRobot{
    public:
    virtual void walk() = 0;
};

class NormalWalk : public WalkableRobot{
    public :
    void walk() override {
        cout<< "Can walk";
    }
};

class NoWalk : public WalkableRobot{
    public :
    void walk() override {
        cout<<" cant walk ";
    }
};


// --- Strategy Interface for Talk ---
class TalkableRobot {
public:
    virtual void talk() = 0;
};

// --- Concrete Strategies for Talk ---
class NormalTalk : public TalkableRobot {
public:
    void talk() override { 
        cout << "Talking normally..." << endl; 
    }
};

class NoTalk : public TalkableRobot {
public:
    void talk() override { 
        cout << "Cannot talk." << endl; 
    }
};

// --- Strategy Interface for Fly ---
class FlyableRobot {
public:
    virtual void fly() = 0;
};

class NormalFly : public FlyableRobot {
public:
    void fly() override { 
        cout << "Flying normally..." << endl; 
    }
};

class NoFly : public FlyableRobot {
public:
    void fly() override { 
        cout << "Cannot fly." << endl; 
    }
};

class Robot{
    protected:
    WalkableRobot* walkBehavior;
    TalkableRobot* talkBehavior;
    FlyableRobot* flyBehavior;

    public:

     Robot(WalkableRobot* w, TalkableRobot* t, FlyableRobot* f) {
        this->walkBehavior = w;
        this->talkBehavior = t;
        this->flyBehavior = f;
    }
       
    void walk() { 
        walkBehavior->walk(); 
    }
    void talk() { 
        talkBehavior->talk(); 
    }
    void fly() { 
        flyBehavior->fly(); 
    }
};

int main() {
    Robot* robot1 = new Robot(new NormalWalk(),new NormalTalk(),new NoFly());
    
    robot1->walk();
    robot1->talk();
    robot1->fly();
    cout << "--------------------" << endl;

    return 0;
}





