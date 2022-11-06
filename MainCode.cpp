#include <iostream>
#include <iomanip>

using namespace std;

// Class to store basic data 
class Node {
    public:
    string name;
    int age;
    Node *nextName = NULL, *nextAge = NULL;
};

// Class to perform link list insertion / removal
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

    // Function to print current database
    void list(Node *node , Node *node2) {
        if (node == NULL) {
            cout << "\nCurrent Student Database\n";
            cout << "---------------------------------\n";
            cout << "|       DATABASE IS EMPTY       |\n";
            cout << "---------------------------------\n";
        }

        else {
            cout << "\nCurrent Student Database\n";
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

// Class to perform search , find mix / max in link list
class utility {
    public:
    // Function to search if data is in the link list
    bool search(Node* head , string data) {
        Node* current = head;
        if (current == NULL) {
            cout << "The Database Is Empty\n";
        }
        else {
            if (current->name == data) {
                    return true;
                }
            else {
                return false;
            }
        }
    }
};

// Class for setting ,returning and editing data
class Data {
    private:
    friend class print;
    Node node;
    insert insert;
    int mainChoice , addRemoveChoice , utilityChoice;
    string deleted , searchStudent;
    Node *head = NULL, *head2 = NULL;

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

    void setUtilityMenu() {
        cout << "Choice: ";
        cin >> utilityChoice;
    }

    // Function to set search student data
    void setSearch() {
        cout << "Which student do you want to search: ";
        cin >> searchStudent;
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

    // Function to delete the front of the link list
    void deleteTop() {
        if (head == NULL) {
            cout << "\nThe Database Is Empty\n";
        }
        if (head != NULL) {
            head = head->nextName;
            head2 = head2->nextAge;
            cout << "\nStudent Removed Successfully\n";
        }
    }

// Function to delete from the bottom (Currently Not Working)
    void deleteBottom() {
        if (head == NULL) {
            head = NULL;
        }
        if (head->nextName == NULL) {
            delete head;
        }
        while (head->nextName->nextName != NULL) {
            head = head->nextName;

            delete (head->nextName);
            head->nextName = NULL;
        }
    }
        
    // Function to set the name of the deleted student
    void setDeleteName() {
        if (head == NULL) {
            cout << "The Database Is Empty";
        }
        else {
            cout << "\nWhich student do you want to delete: \n";
            cin >> deleted;

            cout << "\nStudent Removed Successfully\n";
            deleteNodeName(head , head2 , deleted);
        }
    }

    // Function to delete node by inputing name
    void deleteNodeName(Node*& head , Node*& head2 , string deleted) {
            if(head == NULL)
                {
                    return;
                }
            if (head->name == deleted)   
                {
                    Node* t = head;
                    Node * u = head2;
                    head = head->nextName;
                    head2 = head2->nextAge;

                    delete(t);
                    delete(u);
                    return;
                }
            deleteNodeName(head->nextName , head2->nextAge , deleted); 
        }


};


// Class to print information
class print {
    private:
    Node node;
    Data data;
    insert insert;
    utility utility;

    public:
    // Function to print header
    void header() {
        cout << "---------------------------------------\n";                
        cout << "|\tMMU Student's Database\t      |\n";
        cout << "---------------------------------------\n";   
    }

    // Function to print the main menu
    void mainMenu() {
        insert.list(data.head , data.head2);
        cout << "\n-------------";
        cout << "\n| MAIN MENU |\n";
        cout << "------------------------------------------------------\n";
        cout << "[1] Add / Remove Students From Database\n";
        cout << "[2] Database Utilities ( Searching )\n";
        cout << "------------------------------------------------------\n";
        data.setMainMenu();
        optionsMainMenu();
    }

    // Function to determind which menu to switch to from main
    void optionsMainMenu() {
        if (data.mainChoice == 1) {
            addRemoveMenu();
        }
        if (data.mainChoice == 2) {
            utilityMenu();
        }
    }

    // Function to print add / remove student menu
    void addRemoveMenu() {
        insert.list(data.head , data.head2);
        cout << "\n-----------------";
        cout << "\n| DATABASE MENU |\n";
        cout << "------------------------------------------------------\n";
        cout << "[1] Add A Student To The Top Of The Database\n";
        cout << "[2] Add A Student To The Bottom Of The Database\n";
        cout << "[3] Remove A Student From The Top Of The Database\n";
        cout << "[4] Remove A Student From The Bottom Of The Database\n";
        cout << "[5] Remove A Student From The Database By Name\n";
        cout << "[6] Clear Entire Database\n";
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
        if (data.addRemoveChoice == 3) {
            data.deleteTop();
            addRemoveMenu();
        }
        if (data.addRemoveChoice == 4) {
            // data.deleteBottom(data.head , data.head2);
            data.deleteBottom();
            addRemoveMenu();
        }
        if (data.addRemoveChoice == 5) {
            data.setDeleteName();
            addRemoveMenu();
            }
        if (data.addRemoveChoice == 6) {
            }
        }

    void utilityMenu() {
        cout << "\n-----------------";
        cout << "\n|  UTILITY MENU  |\n";
        cout << "------------------------------------------------------\n";
        cout << "[1] Search For A Student In The Database\n";
        cout << "------------------------------------------------------\n";
        data.setUtilityMenu();
        optionsUtilityMenu();


        }

    void optionsUtilityMenu () {
        if (data.utilityChoice == 0) {
            mainMenu();
        }
        if (data.utilityChoice == 1) {
            data.setSearch();
            utility.search(data.head , data.searchStudent)? cout << "The Student Is In The Database\n" : cout << "The Student Is Not In The Database\n";
            utilityMenu();
        } 
    }




};

// Main Function
int main() {

    print print;

    print.header();
    print.mainMenu();

    
}

 
