// Interface segregation principle

//WITHOUT I
// class Worker {
// public:
//     virtual void work() = 0;
//     virtual void eat() = 0;
// };

// class Robot : public Worker {
// public:
//     void work() override {}
    
//     void eat() override {
//         // Robot doesn't eat!
//     }
// };


// WITH I
class Workable {
public:
    virtual void work() = 0;
};

class Eatable {
public:
    virtual void eat() = 0;
};

class Human : public Workable, public Eatable {
};

class Robot : public Workable {
};
