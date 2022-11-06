#include <iostream>
#include <iomanip>

using namespace std;

// Class to store basic data 
class Node {
    public:
    string name;
    int age;
    Node *nextName , *nextAge;
};

// Class to perform link list insertion
class insert {
    public:
    // Function to push name data into the linked list at the front
    void pushFrontName(Node **head , string data) {
        Node* newNode = new Node();
        newNode->name = data;
        newNode->nextName = (*head);
        (*head) = newNode;
    }

    // Function to push age data into the linked list at the front
    void pushFrontAge(Node **head , int data) {
        Node* newNode = new Node();
        newNode->age = data;
        newNode->nextAge = (*head);
        (*head) = newNode;
    }

    // Function to push name data into the linked list at the end
    void pushEndName(Node **head , string data) {
        Node *newNode = new Node();
        Node *last = *head;
        newNode->name = data;
        newNode->nextName = NULL;
        if (*head == NULL) {
            *head = newNode;
            return;
        }
        while (last->nextName != NULL) {
            last = last->nextName;
        }
        last->nextName = newNode;
        return;
    }

    // Function to push name data into the linked list at the end
    void pushEndAge(Node **head , int data) {
        Node *newNode = new Node();
        Node *last = *head;
        newNode->age = data;
        newNode->nextAge = NULL;
        if (*head == NULL) {
            *head = newNode;
            return;
        }
        while (last->nextAge != NULL) {
            last = last->nextAge;
        }
        last->nextAge = newNode;
        return;
    }
};

// Class to perform search , find mix / max in link list
class utility {
    public:
    // Function to search if data is in the link list
    bool search(Node* head , string data) {

    }
};

// Class for setting and returning data
class Data {
    private:
    friend class print;
    Node node;
    insert insert;
    Node *head = NULL , *head2 = NULL;
    int mainChoice , addRemoveChoice;

    public:
    // Function to set main menu choice
    void setMainMenu() {
        cout << "Choice: ";
        cin >> mainChoice;
    }

    // Function to set add / remove menu choice
    void setAddRemoveMenu() {
        cout << "Choice: ";
        cin >> addRemoveChoice;
    }

    // Function to set Name Age at the front of link list
    void setNameAgeFront() {
        cout << "\nInput Name: " ;
        cin >> node.name;
        cout << "Input Age: ";
        cin >> node.age;
        insert.pushFrontName(&head , node.name);
        insert.pushFrontAge(&head2 , node.age);
    }

    // Function to set Name Age at the end of link list
    void setNameAgeEnd() {
        cout << "\nInput Name: " ;
        cin >> node.name;
        cout << "Input Age: ";
        cin >> node.age;
        insert.pushEndName(&head , node.name);
        insert.pushEndAge(&head2 , node.age);
    }

    // Function to print current database
    void list(Node *node , Node *node2) {
        if (node == NULL) {
            cout << "\nCurrent List\n";
            cout << "------------------------------\n";
            cout << "|         LIST IS EMPTY       |\n";
            cout << "------------------------------\n";
        }

        else {
            cout << "\nViewing Current Database\n";
            cout << "------------------------------\n";
            while (node != NULL) {
                cout << "| "; 
                cout.width(20);
                cout << left << node->name << "| ";
                cout.width(5);
                cout << node2->age << "|" << endl;
                node = node->nextName;
                node2 = node2->nextAge;
            }
            cout << "------------------------------\n";
        }
    }

};

// Class to print information
class print {
    private:
    Data data;

    public:
    // Function to print header
    void header() {
        cout << "---------------------------------------\n";                
        cout << "|\tMMU Student's Database\t      |\n";
        cout << "---------------------------------------\n";   
    }

    // Function to print the main menu
    void mainMenu() {
        cout << "\n-------------";
        cout << "\n| MAIN MENU |\n";
        cout << "------------------------------------------------------\n";
        cout << "[1] View Current Database\t\n";
        cout << "[2] Add / Remove Students From Database\n";
        cout << "------------------------------------------------------\n";
        data.setMainMenu();
        optionsMainMenu();
    }

    // Function to determind which menu to switch to from main
    void optionsMainMenu() {
        if (data.mainChoice == 1) {
            data.list(data.head , data.head2);
            mainMenu();
        }
        if (data.mainChoice == 2) {
            addRemoveMenu();
        }
    }

    // Function to print add / remove student menu
    void addRemoveMenu() {
        cout << "\n-----------------";
        cout << "\n| DATABASE MENU |\n";
        cout << "------------------------------------------------------\n";
        cout << "[1] Add A Student To The Top Of The Database\n";
        cout << "[2] Add A Student To The Bottom Of The Database\n";
        cout << "[3] Remove A Student From The Top Of The Database\n";
        cout << "[4] Remove A Student From The Bottom Of The Database\n";
        cout << "[0] Return Back To Main Menu\n";
        cout << "------------------------------------------------------\n";
        data.setAddRemoveMenu();
        optionsAddRemoveMenu();
    }

    // Function to determine action done in add / remove menu
    void optionsAddRemoveMenu() {
        if (data.addRemoveChoice == 0) {
            mainMenu();
        }
        if (data.addRemoveChoice == 1) {
            data.setNameAgeFront();
            cout << "\nStudent Added Successfully\n";
            addRemoveMenu();
        } 
        if (data.addRemoveChoice == 2) {
            data.setNameAgeEnd();
            cout << "\nStudent Added Successfully\n";
            addRemoveMenu();
        }
    }
};

// Main Function
int main() {

    print print;

    print.header();
    print.mainMenu();

    
}

 
