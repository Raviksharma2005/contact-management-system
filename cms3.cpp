#include <iostream>
#include <cstring>
using namespace std;


class Person {
protected:
    char fName[50], lName[50], address[50];
public:
    virtual void inputDetails() { 
        cout << "Enter your first name: ";
        cin.getline(fName, 50); 
        cout << "Enter your last name: ";
        cin.getline(lName, 50);
        cout << "Enter address: ";
        cin.getline(address, 50);
    }

    virtual void displayInfo() const {
        cout << "Name: " << fName << " " << lName << endl;
        cout << "Address: " << address << endl;
    }

    
    bool operator==(const Person& other) const {
        return strcmp(fName, other.fName) == 0 && strcmp(lName, other.lName) == 0;
    }
};


class Contact : public Person {
private:
    long long phNo;
    char email[50];
public:
    
    void inputDetails() override {
        Person::inputDetails(); 
        cout << "Enter phone: ";
        cin >> phNo;
        cin.ignore(); 
        cout << "Enter email: ";
        cin.getline(email, 50); 
    }

    
    void displayInfo() const override {
        Person::displayInfo(); 
        cout << "Phone: " << phNo << endl;
        cout << "Email: " << email << endl;
    }

    
    bool operator==(const Contact& other) const {
        return phNo == other.phNo;
    }
    
    long long getPhone() const { 
        return phNo;
    }
};


class ContactManagementSystem {
private:
    Contact contacts[100]; 
    int contactCount = 0;  
public:
   
    void addContact() {
        char choice;
        do {
            if (contactCount < 100) {
                contacts[contactCount].inputDetails();
                contactCount++;
                cout << "Contact has been successfully created...\n";
            } else {
                cout << "Contact list is full!\n";
                return;
            }

            cout << "Do you want to add another contact? (y/n): "<<endl;
            cin >> choice;
            cin.ignore(); 
        } while (choice == 'y' || choice == 'Y');
    }

    
    void listContacts() const {
        if (contactCount == 0) {
            cout << "No contacts found!\n";
            return;
        }

        cout << "\n================================\n";
        cout << "LIST OF CONTACTS\n";
        cout << "================================\n";

        for (int i = 0; i < contactCount; i++) {
            contacts[i].displayInfo();
            cout << "================================\n";
        }
    }

    
    void findContact() const {
        long long phone;
        cout << "Enter phone number to search: ";
        cin >> phone;

        for (int i = 0; i < contactCount; i++) {
            if (contacts[i].getPhone() == phone) {
                contacts[i].displayInfo();
                return;
            }
        }

        cout << "\n\nContact not found!\n";
    }

   
    void removeContact() {
        long long phone;
        cout << "Enter phone number to delete: ";
        cin >> phone;

        for (int i = 0; i < contactCount; i++) {
            if (contacts[i].getPhone() == phone) {
                
                for (int j = i; j < contactCount - 1; j++) {
                    contacts[j] = contacts[j + 1];
                }
                contactCount--; // Decrease contact count
                cout << "\n\nContact Deleted...\n";
                return;
            }
        }

        cout << "\n\nContact Not Found...\n";
    }

    
    void updateContact() {
        long long phone;
        cout << "Enter the phone number to edit: ";
        cin >> phone;
        cin.ignore(); 

        for (int i = 0; i < contactCount; i++) {
            if (contacts[i].getPhone() == phone) {
                cout << "Enter new details:\n";
                contacts[i].inputDetails();
                cout << "\n\nContact Successfully Updated...\n";
                return;
            }
        }

        cout << "\n\nContact not found!\n";
    }
};


int main() {
    system("cls");
    system("Color 7F"); 

    cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t * WELCOME TO CONTACT MANAGEMENT SYSTEM *\n\n\n";

    ContactManagementSystem cms; 
    int choice;

    while (true) {
        cout << "\nChoose an option \n" << endl;
        cout << "[1] Add a new Contact\n";
        cout << "[2] List all Contacts\n";
        cout << "[3] Search for contact\n";
        cout << "[4] Delete a Contact\n";
        cout << "[5] Edit a Contact\n";
        cout << "[0] Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1:
                cms.addContact();
                break;
            case 2:
                cms.listContacts();
                break;
            case 3:
                cms.findContact();
                break;
            case 4:
                cms.removeContact();
                break;
            case 5:
                cms.updateContact();
                break;
            case 0:
                cout << "\nThank you for using the Contact Management System!\n";
                return 0;
            default:
                cout << "\nInvalid choice! Please try again.\n";
        }
    }

    return 0;
}
