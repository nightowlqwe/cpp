#include<bits/stdc++.h>
using namespace std;

struct product{
    int id;
    string name;
    string brand;
    float price;
    int quantity;
};

bool isDuplicate(int id){
    ifstream file("inventory.txt");

    if(!file) return false;

    product p;

    while(file >> p.id){
        file.ignore();
        getline(file, p.name);
        getline(file, p.brand);
        file >> p.price >> p.quantity;
        if(p.id == id){
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

void addProduct(){
    ofstream file("inventory.txt", ios::app);

    if(!file){
        cout << "Error opening file!" << endl;
        return;
    }

    product p;

    cout << "Enter product id: ";
    cin >> p.id;
    cin.ignore();

    if(isDuplicate(p.id)){
        cout << "Product id already exists!" << endl;
        return;
    }

    cout << "Enter Product Name: ";
    getline(cin, p.name);
    cout << "Enter Brand Name: ";
    getline(cin, p.brand);
    cout << "Enter Price: ";
    cin >> p.price;
    cout << "Enter Quantity: ";
    cin >> p.quantity;

    file << p.id << "\n" << p.name << "\n" << p.brand << "\n" << p.price << " " << p.quantity << endl;
    file.close();
    cout << "Product added successfully!" << endl;
}

void display(){
    ifstream file("inventory.txt");
    if (!file) {
        cout << "No records found!" << endl;
        return;
    }
    cout << "\n--- Inventory List ---" << endl;
    product p;
    while(file >> p.id){
        file.ignore();
        getline(file, p.name);
        getline(file, p.brand);
        file >> p.price >> p.quantity;
        cout << "ID: " << p.id << " | Name: " << p.name << " | Brand: " << p.brand
             << " | Price: " << p.price << " | Quantity: " << p.quantity << endl;
    }
    file.close();
}

void searchProducts(){
    ifstream file("inventory.txt");
    if (!file) {
        cout << "No records found!" << endl;
        return;
    }

    int searchId;
    cout << "Enter Product ID to search: ";
    cin >> searchId;

    product p;
    bool found = false;

    while(file >> p.id){
        file.ignore();
        getline(file, p.name);
        getline(file, p.brand);
        file >> p.price >> p.quantity;

        if(p.id == searchId){
            cout << "Product Found" << endl;
            cout << "ID: " << p.id << " | Name: " << p.name << " | Brand: " << p.brand
                 << " | Price: " << p.price << " | Quantity: " << p.quantity << endl;
            found = true;
            break;
        }
    }
    if(!found) cout << "Product not found." << endl;
    file.close();
}

void deleteProduct(){
    ifstream file("inventory.txt");
    if (!file) {
        cout << "No records found!" << endl;
        return;
    }

    int deleteID;
    cout << "Enter Product ID to delete: ";
    cin >> deleteID;

    vector<product> products;

    product p;
    bool found = false;

    while(file >> p.id){
        file.ignore();
        getline(file, p.name);
        getline(file, p.brand);
        file >> p.price >> p.quantity;

        if (p.id == deleteID) {
            cout << "Product deleted successfully." << endl;
            found = true;  // Mark as found but do not save to vector
        } else {
            products.push_back(p);  // Keep all other products
        }
    }
    file.close();

    if (!found) {
        cout << "Product not found." << endl;
        return;
    }

    // Rewrite updated product list back to the file
    ofstream outFile("inventory.txt", ios::trunc);
    for (const auto &prod : products) {
        outFile << prod.id << "\n" << prod.name << "\n" << prod.brand
                << "\n" << prod.price << " " << prod.quantity << endl;
    }
    outFile.close();
}

void deleteAllProducts() {
    ofstream file("inventory.txt", ios::trunc);
    file.close();
    cout << "All products deleted successfully." << endl;
}

int main() {
    int choice;
    do {
        cout << "\n1. Add Product\n2. Display Products\n3. Search Product\n4. Delete Product\n5. Delete All Products\n6. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addProduct(); break;
            case 2: display(); break;
            case 3: searchProducts(); break;
            case 4: deleteProduct(); break;
            case 5: deleteAllProducts(); break;
            case 6: cout << "Exiting program." << endl; break;
            default: cout << "Invalid choice!" << endl;
        }
    } while (choice != 6);

    return 0;
}
