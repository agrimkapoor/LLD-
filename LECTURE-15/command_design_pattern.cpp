// source -> command ->receiver

#include <iostream>
using namespace std;

// Receiver
class Light {
public:
    void turnOn() {
        cout << "Light ON\n";
    }

    void turnOff() {
        cout << "Light OFF\n";
    }
};

// Command
class Command {
public:
    virtual void execute() = 0;
    virtual ~Command() = default;
};

// Concrete Command
class TurnOnCommand : public Command {
private:
    Light* light;

public:
    TurnOnCommand(Light* light)
        : light(light) {}

    void execute() override {
        light->turnOn();
    }
};

// Another Concrete Command
class TurnOffCommand : public Command {
private:
    Light* light;

public:
    TurnOffCommand(Light* light)
        : light(light) {}

    void execute() override {
        light->turnOff();
    }
};

// Invoker
class Remote {
private:
    Command* command;

public:
    void setCommand(Command* command) {
        this->command = command;
    }

    void pressButton() {
        command->execute();
    }
};

int main() {
    Light light;

    TurnOnCommand turnOn(&light);
    TurnOffCommand turnOff(&light);

    Remote remote;

    remote.setCommand(&turnOn);
    remote.pressButton();

    remote.setCommand(&turnOff);
    remote.pressButton();
}
