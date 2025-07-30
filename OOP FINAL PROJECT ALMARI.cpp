#include <iostream>
#include <string>
using namespace std;

const int MAX_PRODUCTS = 5;

class Product{
public:
    string name;
    float price;
    int stock;

    static int totalStock;

    Product() {
        name = "";
        price = 0;
        stock = 0;
    }

    Product(string name, float price, int stock) {
       this->name = name;
       this->price = price;
       this->stock = stock;
        totalStock += stock;
    }

    void display(int index) {
        cout << index + 1 << ". " << name << " - Rs. " << price << " (" << stock << " in stock)" << endl;
    }

    void reduceStock(int qty) {
        if (qty <= stock) {
            stock -= qty;
            totalStock -= qty;
        }
    }
};

// Static variable definition
int Product::totalStock = 0;

class Almari{
private:
    Product catalog[MAX_PRODUCTS];    // Almari has a Product array which can store 5 Products(OBJECTS).
    float cartTotal = 0;

public:
    Almari() {
        // Initial product catalog by default contructor
        catalog[0] = Product("T-shirt", 1200, 10);          // First object of Product in first Index and So on.
        catalog[1] = Product("Jeans", 2500, 5);
        catalog[2] = Product("Sneakers", 4000, 8);
        catalog[3] = Product("Watch", 3500, 6);
        catalog[4] = Product("Backpack", 2200, 4);
    }

    void showCatalog() {
        cout << "\nProduct Catalog:\n";
        for (int i = 0; i < MAX_PRODUCTS; i++) {
            catalog[i].display(i);
        }
    }

    void purchaseMenu() {
        int choice, qty;
        char action;

        showCatalog();
        cout << "\nEnter product number to select: ";
        cin >> choice;

        if (choice < 1 || choice > MAX_PRODUCTS) {
            cout << "Invalid product selection!" << endl;
            return;
        }

        Product &selected = catalog[choice - 1];
        cout << "Selected: " << selected.name << " (Rs. " << selected.price << ")" << endl;
        cout << "Enter quantity: ";
        cin >> qty;

        if (qty > selected.stock) {
            cout << "Not enough stock available!" << endl;
            return;
        }

        cout << "Choose action: (B)uy Now or (A)dd to Cart: ";
        cin >> action;

        float total = selected.price * qty;

        if (action == 'B' || action == 'b') {
            selected.reduceStock(qty);
            cout << "You bought " << qty << " x " << selected.name << " for Rs. " << total << endl;
        } else if (action == 'A' || action == 'a') {
            selected.reduceStock(qty);
            cartTotal += total;
            cout << "Item added to cart. Current cart total: Rs. " << cartTotal << endl;
        } else {
            cout << "Invalid action." << endl;
        }
    }

    void viewCart() {
        cout << "\nYour cart total: Rs. " << cartTotal << endl;
    }

    void menu() {
        int option;
        do {
            cout << "\n======= ALMARI MENU =======\n";
            cout << "1. View Catalog\n";
            cout << "2. Buy/Add to Cart\n";
            cout << "3. View Cart Total\n";
            cout << "4. Exit\n";
            cout << "Select an option: ";
            cin >> option;

            switch (option) {                    // Switch According to Manu Above.
                case 1: showCatalog(); break;
                case 2: purchaseMenu(); break;
                case 3: viewCart(); break;
                case 4: cout << "Thank you for visiting Almari!" << endl; break;
                default: cout << "Invalid option!" << endl;
            }
        } while (option != 4);
    }
};

int main()
{
    Almari store;
    store.menu();
    return 0;
}


