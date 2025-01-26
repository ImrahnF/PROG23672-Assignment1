//
//  PerishableItem.hpp
//  Assignment1
//
//  Created by Imrahn Faqiri on 2025-01-21.
//

#ifndef PerishableItem_hpp
#define PerishableItem_hpp

#include <iostream>

class PerishableItem : public Item {
private:
    string expirationDate;
public:
    // Constructor
    PerishableItem(int id, const string& name, int quantity, double price, const string& expirationDate)
        : Item(id, name, quantity, price), expirationDate(expirationDate) {
    }
    const string& getExpirationDate() const { return expirationDate; }

    // Display method including exp date
    void display() override {
        cout << "[" << getId() << "] " << getName() << " | Qty: " << getQty() << "x @$" << getPrice() <<
            " (Expires on " << getExpirationDate() << ")" << endl;
    }

    int getPerishability() override { return 1; }
    string getSpecificAttribute() override { return expirationDate; }
};

#endif /* PerishableItem_hpp */
