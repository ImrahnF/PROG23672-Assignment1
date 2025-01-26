//
//  NonPerishableItem.hpp
//  Assignment1
//
//  Created by Imrahn Faqiri on 2025-01-21.
//

#ifndef NonPerishableItem_hpp
#define NonPerishableItem_hpp

#include <iostream>
#include <string>

class NonPerishableItem : public Item {
private:
    int warrantyPeriod;
public:
    // Constructor
    NonPerishableItem(int id, const string& name, int quantity, double price, int warrantyPeriod)
        : Item(id, name, quantity, price), warrantyPeriod(warrantyPeriod) {
    }
    const int getWarrantyPeriod() const { return warrantyPeriod; }

    // Display method including warranty period
    void display() override {
        cout << "[" << getId() << "] " << getName() << " | Qty: " << getQty() << "x @$" << getPrice() <<
            " (Warranty period: " << getWarrantyPeriod() << " days)" << endl;
    }

    int getPerishability() override { return 0; }
    string getSpecificAttribute() override { return to_string(warrantyPeriod); }
};

#endif /* NonPerishableItem_hpp */
