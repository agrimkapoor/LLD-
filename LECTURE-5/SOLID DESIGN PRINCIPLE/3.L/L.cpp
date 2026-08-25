//liskov subsitution principle
//A derived class should be usable wherever its base class is expected without breaking the program

// WITHOUT L
// class Bird {
// public:
//     virtual void fly() = 0;
// };

// class Sparrow : public Bird {
// public:
//     void fly() override {}
// };

// class Penguin : public Bird {
// public:
//     void fly() override {
//         throw runtime_error("I can't fly!");
//     }
// };// here penguin violates this principle


// WITH L
class Bird {
public:
    virtual void eat() = 0;
};

class FlyingBird : public Bird {
public:
    virtual void fly() = 0;
};

class Sparrow : public FlyingBird {
public:
    void eat() override {}
    
    void fly() override {
        // fly
    }
};

class Penguin : public Bird {
public:
    void eat() override {
        // eat
    }
};
