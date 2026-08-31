// notification 

class Inotification{
public :
  virtual void send(int userId,string&message) = 0;
  virtual ~Inotification(){}
};

class Email : public Inotification{
  public:
  void send(int userId,string&message)override{
      
  }
};

class NotificationEngine{
 vector<Inotification*>observers;
public:
   void add(Inotification*observer){
       observers.push_back(observer);
   }
   void Remove(Inotification*observer){
       observers.erase( remove(observers.begin(),observers.end(),observer),observers.end());
   }
  void notify(int userId,string&message){
    for(auto observer : observers){
        observer->send(userId,message);
    }
  }
};

class Ipayment{
public:
  virtual bool pay(double amount) = 0;
  virtual ~Ipayment(){}
};



class UPIpayment:public Ipayment{
public:
  bool pay(double amount) override{}
};

class Payment{
Ipayment*obj;
public:
  Payment(Ipayment* obj){
      this->obj = obj;
  }
  bool makePayment(double amount){
      return obj->pay(amount);
  }
};

class Isearch{
public :
  virtual vector<string>searchstrategy(){
     
  }
};




