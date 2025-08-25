#include <iostream>
#include <string>
#include <vector>

struct Item{
    std::string name;
    int quantity;
};
void showInventory(const std::vector<Item>& store){
    std::cout << "\nCurrent Inventory:\n";
    for (const auto& item : store){
        std::cout << "-" << item.name << ": " << item.quantity << "\n";
    }
}

int main(){
    std::vector<Item> store;
    int choice;

    do{
        std::cout << "\n1. Add Item\n2. View Inventory\n3. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

        if (choice == 1){
            Item newItem;
            std::cout << "Enter item name: ";
            std::cin >> newItem.name;
            std::cout << "Enter quantity: ";
            std::cin >> newItem.quantity;
            store.push_back(newItem);
        } else if (choice == 2){
            showInventory(store);
        }
    } while (choice != 3); 

    return 0;
}
    