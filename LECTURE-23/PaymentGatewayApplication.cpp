#include <bits/stdc++.h>
using namespace std;

// data structure for payment details 
class PaymentRequest{
    public:
    string sender;
    string receiver;
    double amount;
    string currency;

    PaymentRequest(const string& sender, const string& reciever, double amt, const string& curr) {
        this->sender = sender;
        this->reciever = reciever;
        this->amount = amt;
        this->currency = curr;
    }
  
};

class BankingSystem{
public:
    virtual bool processPayment(double amount)=0;
};

class PaytmBankingSystem : public BankingSystem{
  public:
  PaytmBankingSystem(){}
  bool processPayment(double amount)override{
      //simulate 80% success
      int r = rand() %100; // 0 se 99 mei integer dega
      return r<80;
  }
};

class RazorpayBankingSystem : public BankingSystem {
public:
    RazorpayBankingSystem() {}
    bool processPayment(double amount) override {
        // Simulate 90% success
        int r = rand() % 100;
        return r < 90;
    }
};

class PaymentGateway{
  protected:
    BankingSystem* bankingSystem;
  public:
    PaymentGateway(){
      bankingSystem = nullptr;
    }
    // Steps to be implemented by concrete gateways
    // har gatweay ka ye hi flow hoga : pehle payment validate karo phir initiate phir confirm
    virtual bool validatePayment(PaymentRequest* request) = 0;
    virtual bool initiatePayment(PaymentRequest* request) = 0;
    virtual bool confirmPayment(PaymentRequest* request) = 0;

    // isse virtual karo tab hi child class can override
    virtual bool processPayment(PaymentRequest* request){ // this processPayment has nothing to do with banking system ka processPayment
         if (!validatePayment(request)) {
            cout << "[PaymentGateway] Validation failed for " << request->sender << ".\n";
            return false;
        }
        if (!initiatePayment(request)) {
            cout << "[PaymentGateway] Initiation failed for " << request->sender << ".\n";
            return false;
        }
        if (!confirmPayment(request)) {
            cout << "[PaymentGateway] Confirmation failed for " << request->sender << ".\n";
            return false;
        }
        return true;
    }

};

class PaytmGateway : public PaymentGateway {
public:
    PaytmGateway() {
        bankingSystem = new PaytmBankingSystem();
    }
    bool validatePayment(PaymentRequest* request) override {
        cout << "[Paytm] Validating payment for " << request->sender << ".\n";

        if (request->amount <= 0 || request->currency != "INR") {
            return false;
        }
        return true;
    }
    bool initiatePayment(PaymentRequest* request) override {
        cout << "[Paytm] Initiating payment of " << request->amount 
                  << " " << request->currency << " for " << request->sender << ".\n";

        return bankingSystem->processPayment(request->amount);
    }
    bool confirmPayment(PaymentRequest* request) override {
        cout << "[Paytm] Confirming payment for " << request->sender << ".\n";

        // Confirmation always succeeds in this simulation
        return true;
    }
};

class RazorpayGateway : public PaymentGateway {
public:
    RazorpayGateway() {
        bankingSystem = new RazorpayBankingSystem();
    }
    bool validatePayment(PaymentRequest* request) override {
        cout << "[Razorpay] Validating payment for " << request->sender << ".\n";

        if (request->amount <= 0) {
            return false;
        }
        return true;
    }
    bool initiatePayment(PaymentRequest* request) override {
        cout << "[Razorpay] Initiating payment of " << request->amount 
                  << " " << request->currency << " for " << request->sender << ".\n";

        return bankingSystem->processPayment(request->amount);
       
    }
    bool confirmPayment(PaymentRequest* request) override {
        cout << "[Razorpay] Confirming payment for " << request->sender << ".\n";

        // Confirmation always succeeds in this simulation
        return true;
    }
};

// retry functionality : payment fail hoye toh khud kar try waapis thodi baar
class PaymentGatewayProxy : public PaymentGateway{
    PaymentGateway* realGateway;
    int retries;
    public:
    PaymentGatewayProxy(PaymentGateway*gateway,int maxRetries){
        realGateway = gateway;
        retries = maxRetries;
    }
    bool processPayment(PaymentRequest*request)override{
        bool result = false;
        for(int attempt = 0;attempt < retries;attempt++){
            if (attempt > 0) {
                cout << "[Proxy] Retrying payment (attempt " << (attempt+1)
                          << ") for " << request->sender << ".\n";
            }
            result = realGateway ->processPayment(request);
            if(result)break;
        }
        if (!result) {
            cout << "[Proxy] Payment failed after " << (retries)<< " attempts for " << request->sender << ".\n";
        }
        return result;
    }
    bool validatePayment(PaymentRequest* request) override {
        return realGateway->validatePayment(request);
    }
    bool initiatePayment(PaymentRequest* request) override {
        return realGateway->initiatePayment(request);
    }
    bool confirmPayment(PaymentRequest* request) override {
        return realGateway->confirmPayment(request);
    }
};

int main(){
  return 0;
}
