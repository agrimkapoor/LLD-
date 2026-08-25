// S : Single responsibility principle

//WITHOUT S
// class Invoice {
// public:
//     void calculateTotal(){}
//     void printInvoice(){}
//     void saveToDatabase(){}
// };

//WITH S 
class Invoice {
public:
    void calculateTotal();
};

class InvoicePrinter {
public:
    void print(const Invoice&);
};

class InvoiceRepository {
public:
    void save(const Invoice&);
};

// ab har class ka ek hi kaam hai
