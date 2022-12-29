#include <iostream>
#include <iomanip>
#include <utility>
using namespace std;

struct Node{
    string name;
    int age;
    Node *next;

    Node(string n, int a){
        name = n;
        age = a;
        next = nullptr;
    }
};

class print {
    public:
        void welcome() {
            cout << "---------------------------------------\n";
            cout << "|\tMMU Student's Database\t      |\n";
            cout << "---------------------------------------\n";
        }


};

class LinkedList{
    Node *head;
    Node *tail;
    int size;

  public:
    // Initialize the LinkedList
    LinkedList(){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    LinkedList(string name, int age){
        Node *nNode = new Node(name, age);
        head = nNode;
        tail = nNode;
        size = 1;
    }

    // Function to push data to the front of the linked list
    void push_front(string name, int age){
        Node *nNode = new Node(name, age);
        if (head == nullptr)
        {
            head = nNode;
            tail = nNode;
        }
        else
        {
            nNode->next = head;
            head = nNode;
        }
        size++;
    }
    
    // Function to push data to the front of the linked list
    void push_back(string name, int age){
        Node *nNode = new Node(name, age);
        if (tail == nullptr)
        {
            head = nNode;
            tail = nNode;
        }
        else
        {
            tail->next = nNode;
            tail = nNode;
        }
        size++;
    }

    // Function to delete data to the front of the linked list
    void pop_front(){
        if (head == nullptr)
        {
            cout << "The Database Is Empty";
        } 
        else if (head != nullptr)
        {
            Node *nNode = head;
            head = head->next;
            delete nNode;
            cout << "\nStudent Successfully Deleted.\n";
        }   
    }

    void pop_back(){
        if (tail == nullptr)
        {
            cout << "The Database Is Empty";
        } 
        else if (tail != nullptr)
        {
            Node *nNode = tail;
            tail = tail->next;
            delete nNode;
            cout << "\nStudent Successfully Deleted.\n";
        }   
    }

    bool search(string name){
        Node *ptr = head;
        bool found = false;
        while (ptr != nullptr){
            if (ptr->name == name){
                found = true;
                break;
            }
            ptr = ptr->next;
        }
        return found;
    }
    int searchName(string name){
        Node *ptr = head;
        bool found = false;
        while (ptr != nullptr){
            if (ptr->name == name){
                found = true;
                break;
            }
            ptr = ptr->next;
        }
        return ptr->age;
    }

    void printList(){
        Node *ptr = head;
        cout << "\n---------------------------------";
        cout << "\n|        Current Database       |\n";
        cout << "---------------------------------\n";
                cout << "| "; 
                cout.width(20);
                cout << left << "Name" << "| ";
                cout.width(8);
                cout << "Age" << "|" << endl;          
            cout << "---------------------------------\n";
            while (ptr != nullptr) {
                cout << "| "; 
                cout.width(20);
                cout << left << ptr->name << "| ";
                cout.width(8);
                cout << ptr->age << "|" << endl;
                ptr = ptr->next;
            }
    }


    pair<string, int> front(){
        if (head != nullptr)
          return make_pair(head->name, head->age);
        else
            return make_pair("Empty", 0);
    }

    pair<string, int> back(){
        if (tail != nullptr)
            return make_pair(tail->name, tail->age);
        else
            return make_pair("Empty", 0);
    }

    int getSize(){
        return size;
    }
};


class Application{
    LinkedList a;
    print p;
    int menu;

public:
    Application(){
        p.welcome();    // Run header message
        do { editNodes();} while (menu != 11);
                                // Run function to add nodes
        a.printList();

        // cout << a.getSize() << " nodes in the list" << endl;

        // searchDemo();
        // front_back_demo();
    }

    void getMenu() {
        cout << "------------------------------------------------------\n";
        cout << "[00] Print Database\n";
        cout << "[01] Clear Database\n";
        cout << "[02] Move To Sorted Linked List With Data\n";
        cout << "------------------------------------------------------\n";
        cout << "[1] Add A Student To The Top Of The Database\n";
        cout << "[2] Add A Student To The Bottom Of The Database\n";
        cout << "[3] Remove A Student From The Top Of The Database\n";
        cout << "[4] Remove A Student From The Bottom Of The Database\n";
        cout << "[5] Remove A Student From The Database By Name\n";
        cout << "[6] Remove A Student From The Database By Age\n";
        cout << "------------------------------------------------------\n";
        cout << "[7] Show Size Of Database \n";
        cout << "[8] Search For A Student By Name\n";
        cout << "[9] Search For A Student By Age\n";
        cout << "[10] Search For The Youngest Student\n";
        cout << "[11] Search For The Oldest Student\n";
        cout << "------------------------------------------------------\n";
        cout << "Enter a value: ";
        cin >> menu;
        }

    void editNodes(){
        string name; int age;
        getMenu();
        
        if (menu == 00)
        {
            a.printList();
        }

        else if (menu == 1)     // Push data to the front of the list
        {
            cout << "\nEnter the name and age of the student.\n";
            cout << "Name -> ";
            cin >> name;
            cout << "Age  -> "; 
             cin >> age;
            a.push_front(name, age);
            cout << "\nStudent Successfully Added.\n";
        }
        else if (menu == 2)  // Push data to the end of the list
        {
            cout << "\nEnter the name and age of the student.\n";
            cout << "Name -> ";
            cin >> name;
            cout << "Age  -> "; 
            cin >> age;
            a.push_back(name, age);
            cout << "\nStudent Successfully Added.\n";
        }
        else if (menu == 3)  // Delete data at the front of the list
        {
            a.pop_front();
        }
        else if (menu == 4)  // Delete data at the back of the list
        {
            a.pop_back();
        }

    }

    void searchDemo(){
        cout << boolalpha << a.search("Lynne") << endl;
        cout <<  a.searchName("afif") << endl;
        cout << boolalpha << a.search("sharaf") << endl;

    }

    void front_back_demo(){
        pair<string, int> front = a.front();
        if (front.first == "Empty")
            cout << "List is empty" << endl;
        else
            cout << front.first << ":" << front.second << endl;

        pair<string, int> back = a.back();
        if (back.first == "Empty")
            cout << "List is empty" << endl;
        else
            cout << back.first << ":" << back.second << endl;
    }
};

int main(){
    Application app;
    return 0;
}