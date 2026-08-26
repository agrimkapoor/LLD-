// lld problem we care about ki konsi classes hogi unme kya data hoga aur ye classes kaise interact karegi



/*
STEP 1 : WHAT ARE WE BUILDING : ZEPTO --> ISKA EK ROUGH FLOW SOCHO
A customer:

1.Opens the app
2.Searches for a product
3.Adds products to cart
4.Places an order
5.Pays
6.A delivery partner gets assigned
7.Order is delivered

*/

/*
  STEP 2 : IDENTIFY KI KAUNSI CLASSES/ENTITIES HONGI
  Customer
  Product
  Cart
  Order
  Payment
  Store
  Inventory
  DeliveryPartner
*/

#include <bits/stdc++.h>
using namespace std;

// 1.CUSTOMER
class Customer {
private:
    int id;
    string name;
    string address;

public:
    Customer(int id, string name, string address) {
        this->id = id;
        this->name = name;
        this->address = address;
    }
    int getId() {
        return id;
    }

    string getName() {
        return name;
    }

    string getAddress() {
        return address;
    }
};

//2.PRODUCT
class Product{//product konsa hai uski kitni quantity hai woh isme store nhi hogi as it varies from user to user
  int id;
  string name;
  double price;
  public:
  Product(int id,string name,double price){
      this->id = id;
      this->name = name;
      this->price = price;
  }
  int getId() {
      return id;
  }

  string getName() {
      return name;
  }

  double getPrice() {
      return price;
  }
};

//3.CART
/*
  Milk    → 2
  Bread   → 1
  Apple   → 3

  KONSE ITEMS HAI KITNI QUANTITY HAI

  CART KA KAAM HOGA
    1.PRODUCT ADD KARNA
    2.PRODUCT REMOVE KARNA
    3.TOTAL PRICE CALCULATE
    4.CART KE SAARE ITEMS DEKHNA
    5.ORDER PLACE HONE KE BAAD CART EMPTY KARNA
*/

class Cart{
  unordered_map<Product*,int>items; // Product*product, freq
  public:
  void addProduct(Product*product,int quantity){
      items[product]+=quantity;
  }
  void removeProduct(Product*product,int quantity){
      items[product]-=quantity;
      if(items[product]==0)items.erase(product);
  }
  double getTotal() {

      double total = 0;

      for (auto& item : items) {

          Product* product = item.first;
          int quantity = item.second;

          total += product->getPrice() * quantity;
      }

      return total;
    }
  unordered_map<Product*, int> getItems() {
      return items;
  }
  void clear() {
      items.clear();
  }
};

//4.ORDER
class Order{
  public:
  
};

int main(){
  return 0;
}
