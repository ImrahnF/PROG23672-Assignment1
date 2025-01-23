//
//  main.cpp
//  Assignment1
//
//  Created by Imrahn Faqiri on 2025-01-18.
//

#include <iostream>

#include "Item.hpp"
#include "PerishableItem.hpp"
#include "NonPerishableItem.hpp"
#include "Inventory.hpp"

using namespace std;

int menu_state; // 0 = menu, 1 = add, 2 = remove, 3 = display, 4 = save, 5 = load
int running = true;

void display_intro() {
    cout << "-------------------------------------------" << endl;
    cout << "Welcome to the Inventory Management System!\nHere are your options:" << endl;
    cout << "- Add [1]\n- Remove [2]\n- Display [3]\n- Save [4]\n- Load [5]" << endl;
    cout << "- [6] to exit." << endl;
    cout << "-------------------------------------------" << endl;
}

void main_loop() {
    display_intro();
    int choice = 0;
    
    // Main method loop
    while (choice != 6) { // 6 is the exit code/choice
        cout << "// Please enter your choice: \\\\" << endl;
        cin >> choice;
        
        switch (choice) {
            case 1: // Add
                cout << "Selected 'Add'" << endl;
                break;
            case 6:
                break;
            default:
                cout << "Please enter a valid input." << endl;
                break;
        }
    }
    
    cout << "Thank you for using the Inventory Mangement System!" << endl;
}


int main() {
    main_loop();
    
    return 0;
}
