//dependency inversion principle : High-level modules should not depend directly on low-level modules. Both should depend on abstractions.

//WITHOUT D

// class Keyboard {
// public:
//     void type() {
//         // typing
//     }
// };

// class Computer { //high level module
//     Keyboard keyboard;  // Computer directly depends on Keyboard

// public:
//     void work() {
//         keyboard.type();
//     }
//};

// agar aur koi i/p device pe depend ho

class InputDevice {
public:
    virtual void input() = 0;
};

class Keyboard : public InputDevice {
public:
    void input() override {
        // typing
    }
};

class TouchScreen : public InputDevice {
public:
    void input() override {
        // touch input
    }
};

class Computer {
    InputDevice* device;
public:
    Computer(InputDevice* device) : device(device) {}

    void work() {
        device->input();
    }
};

int main() {
    InputDevice* device = new Keyboard();

    Computer computer(device);

    computer.work();

    
    return 0;
}
