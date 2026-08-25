// open closed principle

//WITHOUT O
// class Payment {
// public:
//     void pay(string type) {
//         if (type == "card") {
//             // Card payment logic
//         }
//         else if (type == "upi") {
//             // UPI payment logic
//         }
           // IF WE WANT TO ADD CASH PAYMENT WE MODIFY EXISTING CLASS
//         else if (type == "cash") {
//             // Cash payment logic
//         }
//     }
// };

//WITH O
class Payment {
public:
    virtual void pay() = 0;
};

class CardPayment : public Payment {
public:
    void pay() override {
        // card
    }
};

class UPIPayment : public Payment {
public:
    void pay() override {
        // UPI
    }
};

//now adding
class WalletPayment : public Payment {
    // ...
};

// Add new behavior by adding new classes, not by constantly modifying existing classes.
