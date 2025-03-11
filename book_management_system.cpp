#include<bits/stdc++.h>
using namespace std;

struct book{
    int id;
    string name;
    string author;
    double price;
};

void addBook(){
    book newBook;
    cout<<"Enter book details."<<endl;

    cout<<"ID: ";
    cin>>newBook.id;
    cin.ignore();

    cout<<"Name: ";
    getline(cin,newBook.name);

    cout<<"Author: ";
    getline(cin,newBook.author);

    cout<<"Price: ";
    cin>>newBook.price;

    ofstream bookFile("book.txt",ios::app);

    if(!bookFile){
        cout<<"Error opening file"<<endl;
        return ;
    }
    bookFile<<newBook.id<<","
            <<newBook.name<<","
            <<newBook.author<<","
            <<newBook.price<<endl;

    bookFile.close();
    cout<<"Book added successfully!"<<endl;
}

void display(){

    ifstream obj("book.txt");

    if(obj.is_open()){
        cout<<"All books."<<endl;
        string arr;
        int i=1;

        while(getline(obj,arr)){
            cout<<i<<". "<<arr<<endl;
            i++;
        }
        cout<<endl;
        obj.close();
    }
    else{
        cout<<"Error reading file!"<<endl;
        return ;
    }
}

void searchByID(){

    int searchID;
    cout<<"Enter search ID: ";
    cin>>searchID;

    ifstream obj("book.txt");

    if(obj.is_open()){
        string line;
        bool found = false;

        while(getline(obj,line)){
            stringstream ss(line);
            int id;
            string name, author;
            double price;

            ss>>id;
            ss.ignore(1,',');

            getline(ss,name,',');
            getline(ss,author,',');
            ss>>price;

            if(id==searchID){
                cout << "Book found!" << endl;
                cout << "ID: " << id << endl;
                cout << "Name: " << name << endl;
                cout << "Author: " << author << endl;
                cout << "Price: " << price << endl;
                found = true;
                break;
            }
        }
        if(!found){
            cout<<"Book with ID "<<searchID<<" not found!"<<endl;
        }
        obj.close();
    }
    else{
        cout<<"Error opening file!"<<endl;
    }

}


int main(){
    while (true) {
        cout << "\n===== Book Management System =====" << endl;
        cout << "1. Add New Book" << endl;
        cout << "2. Display All Books" << endl;
        cout << "3. Search for a Book by ID" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                display();
                break;
            case 3:
                searchByID();
                break;
            case 4:
                cout << "Exiting program. Goodbye!" << endl;
                return 0; // Exit the program
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
