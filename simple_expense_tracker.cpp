#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

struct Expense{
    std::string category;
    std::string date;
    double amount;
};

void addExpense(std::vector<Expense>& expense){
    Expense e;
    std::cout << "Enter category (e.g., food, transport): ";
    std::cin >> e.category;
    std::cout << "Enter date (YYYY-MM-DD): ";
    std::cin >> e.date;
    std::cout << "Enter amount: ";
    std::cin >> e.amount;

    expense.push_back(e);
    std::cout << "Expense added!\n";
}

void saveExpenses(const std::vector<Expense>& expenses, const std::string& filename){
    std::ofstream file(filename);
    for (const auto& e : expenses){
        file << e.category << " " << e.date << " " << e.amount << "\n";
    }
    file.close();
    std::cout << "Expenses saved to " << filename << "\n";
}

void loadExpenses(std::vector<Expense>& expenses, const std::string& filename){
    std::ifstream file(filename);
    Expense e;
    while (file >> e.category >> e.date >> e.amount){
        expenses.push_back(e);
    }
    file.close();
}

void showSummary(const std::vector<Expense>& expenses){
    double total = 0;
    std::cout << "\nExpense Summary:\n";
    std::cout << std::left << std::setw(15) << "Category"
    << std::setw(12) << "Date"
    << std::setw(10) << "Amount\n";

    for (const auto& e : expenses){
        std::cout << std::left << std::setw(15) << e.category 
        << std::setw(12) << e.date 
        << std::setw(10) << e.amount << "\n";
        total += e.amount;
    }
    std::cout << "-----------------------\n";
    std::cout << "Total: " << total << "\n";
}

int main (){
    std::vector<Expense> expenses;
    std::string filename = "expenses.txt";
    loadExpenses(expenses, filename);

    int choice;
    do{
        std::cout << "\nExpense Tracker Menu:\n";
        std::cout << "1. Add expense\n";
        std::cout << "2. Show Summary\n";
        std::cout << "3. Save & Exit\n";
        std::cout << "Choose: ";
        std::cin >> choice;

        switch (choice){
            case 1: addExpense(expenses); break;
            case 2: showSummary(expenses); break;
            case 3: saveExpenses(expenses, filename); break;
            default: std::cout << "Invalid Choice.\n";
        }
    } while (choice != 3);

    return 0;
}