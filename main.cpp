#include <iostream>
#include <string>

using namespace std;

class Contact {
public:
    string name;
    string phone;
    Contact* next;

    Contact(string name, string phone) {
        this->name = name;
        this->phone = phone;
        this->next = nullptr;
    }
};

Contact* head = nullptr;


void addContact();
void searchContact();
void displayContacts();
void deleteContact();

int main() {
    int choice;

    do {
        cout << "\nContact Management System" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. Search Contact" << endl;
        cout << "3. Display All Contacts" << endl;
        cout << "4. Delete Contact" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                searchContact();
                break;
            case 3:
                displayContacts();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                cout << "*****************************Exiting*****************************" << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);

    return 0;
}

void addContact() {
    string name, phone;
    int count=0;
    cout << "Enter name: ";
    cin >> name;
    Contact* current = head;
    while (current != nullptr) {
        if (current->name == name) {
                count++;
        }
        current = current->next;
    }
    if(count==0)
    {
    cout << "Enter phone number: ";
    cin >> phone;
    Contact* newContact = new Contact(name, phone);
    newContact->next = head;
    head = newContact;
    cout << "Contact added successfully!" << endl;
    }
    else
     cout << "Contact name repeated"<<endl;


}

void searchContact() {
    string nameToSearch;
    cout << "Enter name to search: ";
    cin >> nameToSearch;

    Contact* current = head;
    while (current != nullptr) {
        if (current->name == nameToSearch) {
            cout << "*******************Contact found*******************"<<endl <<"Name:  "<< current->name << ", " <<"Phone Number: "<< current->phone << endl;
            return;
        }
        current = current->next;
    }
    cout << "****Contact not found****" << endl;
}

void displayContacts() {
    Contact* current = head;
    if (current == nullptr) {
        cout << "No contacts to display." << endl;
        return;
    }
    cout << "List of contacts:" << endl;
    while (current != nullptr) {
        cout << "Name: " << current->name << ", Phone Number: " << current->phone << endl;
        current = current->next;
    }
}

void deleteContact() {
    string nameToDelete;
    cout << "Enter name to delete: ";
    cin >> nameToDelete;

    Contact* current = head;
    Contact* prev = nullptr;

    while (current != nullptr && current->name != nameToDelete) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Contact not found." << endl;
        return;
    }

    if (prev == nullptr) {
        head = current->next;
    } else {
        prev->next = current->next;
    }

    delete current;
    cout << "Contact deleted successfully." << endl;
}
