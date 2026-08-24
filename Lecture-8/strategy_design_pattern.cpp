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
    WalkableRobot* walkBehavior; // Robot HAS-A WalkableRobot
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
    virtual void projection() = 0;
};

class CompanionRobot{
    public: 
    CompanionRobot(WalkableRobot* w, TalkableRobot* t, FlyableRobot* f) : Robot(w, t, f) {}

    void projection () override{
        cout << "Displaying friendly companion features..." << endl;
    }
};

class WorkerRobot{
    public:
    WorkerRobot(WalkableRobot* w, TalkableRobot* t, FlyableRobot* f)
        : Robot(w, t, f) {}

    void projection() override {
        cout << "Displaying worker efficiency stats..." << endl;
    }
};

int main() {
    Robot* robot1 = new CompanionRobot(new NormalWalk(),new NormalTalk(),new NoFly());
    
    robot1->walk();
    robot1->talk();
    robot1->fly();
    robot1->projection();
    cout << "--------------------" << endl;

    Robot* robot2 = new WorkerRobot(new NoWalk(), new NoTalk(), new NormalFly());
    robot2->walk();
    robot2->talk();
    robot2->fly();
    robot2->projection();

    return 0;
}





