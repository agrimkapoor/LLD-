// factory design pattern : object creation ka logic ek alag class mei handle hoga
#include <iostream>
using namespace std;

class Burger{
    public:
      virtual void prepare() = 0;
};

class BasicBurger : public Burger{
    public:
    void prepare() override{
        cout<<"preparing basic burger"<<endl;
    }
};

class StandardBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Standard Burger " << endl;
    }
};

class PremiumBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Premium Burger " << endl;
    }
};

class BurgerFactory{
    public : 
    Burger* createBurger(string &type){
        if (type == "basic") {
            return new BasicBurger();
        } 
        else if (type == "standard") {
            return new StandardBurger();
        } 
        else if (type == "premium") {
            return new PremiumBurger();
        } 
        else {
            cout << "Invalid burger type! " << endl;
            return nullptr;
        }
    }
};

int main(){
  string type = "standard";

  BurgerFactory* myBurgerFactory = new BurgerFactory();
  Burger* burger = myBurgerFactory->createBurger(type);
  burger->prepare();
  return 0;
}
