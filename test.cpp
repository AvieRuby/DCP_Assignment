#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int showList = 0;

// Class to store basic data 
class Node {
    public:
    string name;
    int age;
    Node *next;
};

// Class to print
class linkedList {
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
        cout << "--------------------------------------------------------------------------------\n";
        cout << "[1] Add / Remove Students From Database\n";
        cout << "[2] Search Students From Database\n";
        cout << "[0] Print Current Database\n";
        cout << endl;
        cout << "[99] |TOGGLE DEBUG MODE| " ;
        if (showList % 2 == 0) {
            cout << "OFF : NOT SHOWING DATABASE\n";
        }
        if (showList % 2 != 0) {
            cout << "ON : SHOWING DATABASE\n";
        }
        cout << "--------------------------------------------------------------------------------\n";
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
        cout << "[5] Remove A Student From The Database By Name\n";
        cout << "[6] Clear Entire Database\n";
        cout << "[0] Return Back To Main Menu\n";
        cout << "------------------------------------------------------\n";
    }

    // Function to print search / minMax student menu
    void searchMenu() {
        cout << "\n-----------------";
        cout << "\n|  SEARCH MENU  |\n";
        cout << "------------------------------------------------------\n";
        cout << "[1] Search For A Student By Name\n";
        cout << "[2] Search For The Youngest Student\n";
        cout << "[3] Search For The Oldest Student\n";
        cout << "[0] Return Back To Main Menu\n";
        cout << "------------------------------------------------------\n";
    }

};

// Class to perform link list insertion / removal
class function {
    private:
    Node node;
    Node *head = NULL, *head2 = NULL;
    Node *ptr;
    friend class menu;

    public:
    // Function to print show database
    void showDatabase() {
        showList++;
    }

    // Function to set Name Age at the front of link list
    void setNameAgeFront() {
        cout << "\nInput Name: " ;
        cin >> node.name;
        cout << "Input Age: ";
        cin >> node.age;
        cout << "\nStudent Succesfully Added\n";
        pushFrontName(&head , node.name);
        pushFrontAge(&head2 , node.age);
    }

    //Function to set Name Age at the end of link list
    void setNameAgeEnd() {
        cout << "\nInput Name: " ;
        cin >> node.name;
        cout << "Input Age: ";
        cin >> node.age;
        cout << "\nStudent Succesfully Added\n";
        pushEndName(&head , node.name);
        pushEndAge(&head2 , node.age);
    }
    
    // Function to push name data into the linked list atthe front
    void pushFrontName( Node **head , string data) {
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

    // Function to delete from the bottom (Issue)
    void deleteBottom(Node*& head , Node *& head2) {
        Node *t = head;
        Node *u = head2;
        if (t == NULL) {
            cout << "\nThe Database Is Empty\n";
            t = NULL;
            u = NULL;
            return;
        }
        if (t->nextName == NULL) {
            delete(t);
            delete(u);
            return;
	    }
        else {
            while (t->nextName->nextName != NULL) {
                t = t->nextName;
                u = u->nextAge;
            }
            delete (t->nextName);
            delete (u->nextAge);
            t->nextName = NULL;
            u->nextAge = NULL;
        }
    }

    // Function to delete by name
    void deleteNodeName(Node *&head , Node *&head2 , string deleted) {
            if(head == NULL) {
                    return;
                }    
            if (head->name == deleted) {
                    Node *t = head;
                    Node *u = head2;
                    head = head->nextName;
                    head2 = head2->nextAge;

                    delete(t);
                    delete(u);
                    return;
                }
            deleteNodeName(head->nextName , head2->nextAge , deleted); 
        }

    // Function to delete entire list
    void deleteList(Node *&head , Node *&head2) {
        Node *current = head , *current2 = head2;
        Node *nextName = NULL , *nextAge = NULL;

        while (current != NULL) {
            nextName = current->nextName;
            nextAge = current2->nextAge;
            delete(current);
            delete(current2);
            current = nextName;
            current2 = nextAge;
        }
    
        head = NULL;
        head2 = NULL;

    }
    // Function to search if data is in the link list
    bool search(Node *& head , Node*& head2, string data) {
        Node* t = head;
        Node *u = head2;
        if (t == NULL) {
            cout << "The Database Is Empty\n";
        }
        else {
            if (t->name == data) {
                    return true;
                }
            else {
                return false;
            }
        }

    }

    // Function to find youngest student's age
    int minAge(Node *head) {
        int min = INT_MAX;
        Node *current = head;
        if (current == NULL) {
           cout << "The Database Is Empty\n"; 
        }
        else {
            while (current != NULL) { 
                if (min > current->age) {
                    min = current->age;
                }
            current = current->nextAge;
        }
        return min;
        }
    }

    // Function to find youngest student's name
    string minName(Node *head , Node*head2) {
        int min = INT_MAX;
        string minName;
        Node *current = head;
        Node *current2 = head2;
            while (current != NULL) { 
                if (min > current->age) {
                    min = current->age;
                    minName = current2->name;
                }
            current = current->nextAge;
            current2 = current2->nextName;
        }
        return minName;
    } 

    // Function to find oldest student's age
    int maxAge(Node *head) {
        int max = INT_MIN;
        Node *current = head;
        if (current == NULL) {
           cout << "The Database Is Empty\n"; 
        }
        else {
            while (current != NULL) { 
                if (max < current->age) {
                    max = current->age;
                }
            current = current->nextAge;
            }
        return max;
        }
    }

    // Function to find oldest student's name
    string maxName(Node *head , Node*head2) {
        int max = INT_MIN;
        string maxName;
        Node *current = head;
        Node *current2 = head2;
            while (current != NULL) { 
                if (max < current->age) {
                    max = current->age;
                    maxName = current2->name;
                }
            current = current->nextAge;
            current2 = current2->nextName;
        }
        return maxName;
    } 
	 
    // Function to print current database
    void list(Node *node , Node *node2) {
        if (node == NULL || node2 == NULL) {
            cout << "\n---------------------------------";
            cout << "\n|   Current Student Database    |\n";
            cout << "---------------------------------\n";
            cout << "|       DATABASE IS EMPTY       |\n";
            cout << "---------------------------------\n";
        }

        else {
            cout << "\n---------------------------------";
            cout << "\n|   Current Student Database    |\n";
            cout << "---------------------------------\n";
                cout << "| "; 
                cout.width(20);
                cout << left << "Name" << "| ";
                cout.width(8);
                cout << "Age" << "|" << endl;          
            cout << "---------------------------------\n";
            while (node != NULL || node2 != NULL) {
                cout << "| "; 
                cout.width(20);
                cout << left << node->name << "| ";
                cout.width(8);
                cout << node2->age << "|" << endl;
                node = node->nextName;
                node2 = node2->nextAge;
            }
            cout << "---------------------------------\n";
        }
    }

};

// Class menu to dictate where to go
class menu {
    private:
    function function;
    print print;
    int run = 0;

    public:
    // Function for Main Menu, -> 1 = addRemove , 2 = functions
    void mainMenu() {
        int choice;
        print.mainMenu();
        cout << "Choice: ";
        cin >> choice;
        while(1) {
            if(cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "\nPlease Enter A Valid Choice\n";
                mainMenu();
            }
        if (!cin.fail()) {
            if (choice == 99) {
                function.showDatabase();
                mainMenu();
            }
            if (choice == 0) {
                function.list(function.head , function.head2);
                mainMenu();
            }
            if (choice == 1) {
                addRemove();
            }
            if (choice == 2) {
                search();
            }
            if (choice == 3) {
                function.sort(function.head2);
                function.list(function.head , function.head2);
                mainMenu();
            }
            else {
                cout << "\nPlease Enter A Valid Choice\n";
                mainMenu();
            }
        }
        }
    }

    // Function for addRemove Menu, -> 0 = Main Menu
    void addRemove() {
        int choice;
        if(showList % 2 != 0) {
            function.list(function.head , function.head2);
        }
        print.addRemoveMenu();
        cout << "Choice: ";
        cin >> choice;
        while(1) {
            if(cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "\nPlease Enter A Valid Choice\n";
                addRemove();
            }
        if (!cin.fail()) {
            if (choice == 0) {
                mainMenu();
            }
            if (choice == 1) {
                function.setNameAgeFront();
                addRemove();
            }
            if (choice == 2) {
                function.setNameAgeEnd();
                addRemove();
            }
            if (choice == 3) {
                function.deleteTop();
                addRemove();
            }
            if (choice == 4) {
                function.deleteBottom(function.head , function.head2);
                addRemove();
            }
            if (choice == 5) {
                string deleted;
                if (function.head == NULL) {
                    cout << "\nThe Database Is Empty\n";
                    addRemove();
                }
                else {
                    cout << "\nWhich Student Do You Want To Delete: \n";
                    cin >> deleted;

                    cout << "\nStudent Removed Successfully\n";
                    function.deleteNodeName(function.head , function.head2 , deleted);
                    addRemove();
                }
            }
            if (choice == 6) {
                function.deleteList(function.head , function.head2);
                cout << "\nThe Database Has Been Cleared.\n";
                addRemove();
            }
            else {
                cout << "\nPlease Enter A Valid Choice\n";
                addRemove();
            }
        }
        }
    }

    // Function for search Menu, -> 0 = Main Menu
    void search() {
        int choice;
        if(showList % 2 != 0) {
            function.list(function.head , function.head2);
        }
        print.searchMenu();
        cout << "Choice: ";
        cin >> choice;
        while(1) {
            if(cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "\nPlease Enter A Valid Choice\n";
                search();
            }
        if (!cin.fail()) {
            if (choice == 0) {
                mainMenu();
            }
            if (choice == 1) {
                string searched;
                if (function.head == NULL) {
                    cout << "\nThe Database Is Empty\n";
                    search();
                }
                else {
                cout << "\nWho Do You Want To Search By Name? :";
                cin >> searched;
                function.search(function.head , function.head2 , searched)
                ? cout << "\nThe Student " << searched << " Is In The Database\n" : cout << "\nThe Student " << searched <<"\n Is Not In The Database\n";
                search();
                }
            }
            if (choice == 2) {
                if (function.head == NULL) {
                    cout << "\nThe Database Is Empty\n";
                    search();
                }
                else {
                cout << "\nThe Youngest Student Is " << function.minName(function.head2 , function.head) << " at " << function.minAge(function.head2) << " Years Old\n";
                search();
                }
            }
            if (choice == 3) {
                if (function.head == NULL) {
                    cout << "\nThe Database Is Empty\n";
                    search();
                }
                else {
                cout << "\nThe Oldest Student Is " << function.maxName(function.head2 , function.head) << " at " << function.maxAge(function.head2) << " Years Old\n";
                search();
            }
            }
        }
        }
    }
};




int main() {
    print print;
    menu menu;

    print.header();
    menu.mainMenu();

}
