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

    void *getHead() {
        return head;
    }
    // Function to push data to the front
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
    
    // Function to push data to the front
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

    // Function to delete data at the front
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

    // Function to delete data at the end
    void pop_back(){
        if (head == nullptr)
        {
            cout << "The Database Is Empty";
        } 
        else if (head->next == nullptr)
        {
            head = nullptr;
        }
        else
        {
            Node *nNode = head;
            while (head->next->next != nullptr)
            {
                head = head->next;
                delete nNode;
                cout << "\nStudent Successfully Deleted.\n";
            }
        head->next = nullptr;
        }
           
    }

    // Function to delete data by key name
    void pop_name(string key) {
        Node *prev = nullptr;
        Node *current = head;
        while(current != nullptr)
        {
            if (current->name == key)
            {
                if (current == head)
                {
                    head = head->next;
                    delete current;
                    current = head;
                    cout << "\nStudent Successfully Deleted.\n";
                }
                else
                {
                    prev->next = current->next;
                    delete current;
                    current = prev->next;
                }

            }
            else
            {
                prev = current;
                current = current->next;
                cout << "\nStudent not found\n";
            }
        }
        
    }
    
    // Function to delete data by key age
    void pop_age(int key) {
        Node *prev = nullptr;
        Node *current = head;
        while(current != nullptr)
        {
            if (current->age == key)
            {
                if (current == head)
                {
                    head = head->next;
                    delete current;
                    current = head;
                    cout << "\nStudent Successfully Deleted.\n";
                }
                else
                {
                    prev->next = current->next;
                    delete current;
                    current = prev->next;
                }

            }
            else
            {
                prev = current;
                current = current->next;
                cout << "\nStudent not found\n";
            }
        }
        
    }

    // Function to get size
    int getSize(){
        return size;
    }

    // Function to search name 
    bool searchName(string key){
        Node *ptr = head;
        bool found = false;
        while (ptr != nullptr){
            if (ptr->name == key){
                found = true;
                break;
            }
            ptr = ptr->next;
        }
        return found;
    }

    void searchNameAge(string key){
        Node *prev = nullptr;
        Node *current = head;
        int printage , count = 0;
        string newName = key;

        cout << "\nStudent Named " << newName << " Found At Ages: \n"; 
        while(current != nullptr)
        {
            if(current->name == key)
            {
                printage = current->age;
                cout << printage << " ";
                current = current->next;
                count++;
            }
            else
            {
                break;
            }

        }
        cout << "\n\nThe Database Found " << count << " Student(s) Named " << newName;
        delete current;

    }

    // Function to search age 
    bool searchAge(int key){
        Node *ptr = head;
        bool found = false;
        while (ptr != nullptr){
            if (ptr->age == key){
                found = true;
                break;
            }
            ptr = ptr->next;
        }
        return found;
    }

    // Find Maximum Number
    int findMax(){
        int max = INT_MIN;
        Node *ptr = head;
            while (ptr != nullptr)
            {
                if (ptr->age > max)
                {
                    max = ptr->age;
                }
            ptr = ptr->next; 
            }
        getMax(max);
        return max;

        }

    void getMax(int key){
        Node *prev = nullptr;
        Node *current = head;
        string max = "x";
        int count = 0;

        cout << "\nThe Oldest Student(s) Is " << key << " Years Old\n";
        cout << "Student(s) Aged " << key << ": ";
        while(current != nullptr)
        {
            if(current->age == key)
            {
                max = current->name;
                cout << max << " ";
                current = current->next;
                count++;
            }
            else
            {
                break;
            }

        }
        cout << "\n\nThere Are A Total Of " << count << " Student(s) Aged " << key;
        delete current;

    }


    // Find Minimum Number
    int findMin(){
        int min = INT_MAX;
        Node *ptr = head;
            while (ptr != nullptr)
            {
                if (ptr->age < min)
                {
                    min = ptr->age;
                }
            ptr = ptr->next; 
            }
        getMin(min);
        return min;

        }

    void getMin(int key){
        Node *prev = nullptr;
        Node *current = head;
        string min = "x";
        int count = 0;

        cout << "\nThe Youngest Student(s) Is " << key << " Years Old\n";
        cout << "Student(s) Aged " << key << ": ";
        while(current != nullptr)
        {
            if(current->age == key)
            {
                min = current->name;
                cout << min << " ";
                current = current->next;
                count++;
            }
            else
            {
                break;
            }

        }
        cout << "\n\nThere Are A Total Of " << count << " Student(s) Aged " << key;
        delete current;

    }

    // Function to cause havoc
    void deleteList() {
        Node *current = head;
        Node *next = nullptr;

        while (current != nullptr)
        {
            next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }


    // Function to print out my glorious list
    void printList(){
        Node *ptr = head;
        if (head == nullptr)
        {
            cout << "\n---------------------------------";
            cout << "\n|        Current Database       |\n";
            cout << "---------------------------------\n";
            cout << "|       DATABASE IS EMPTY       |\n";
            cout << "---------------------------------\n";
        }
        else
        {
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
            cout << "---------------------------------\n";
        }
    }





};


class Application{
    LinkedList a;
    print p;
    int menu;

public:
    Application(){
        p.welcome();    // Run header message
        do { editNodes();} while (menu != 11); // Run function to add nodes                         
    }

    void getMenu() {
        a.printList(); 
        cout << "------------------------------------------------------\n";
        cout << "[01] Add A Student To The Top Of The Database\n";
        cout << "[02] Add A Student To The Bottom Of The Database\n";
        cout << "[03] Remove A Student From The Top Of The Database\n";
        cout << "[04] Remove A Student From The Bottom Of The Database\n";
        cout << "[05] Remove A Student From The Database By Name\n";
        cout << "[06] Remove A Student From The Database By Age\n";
        cout << "------------------------------------------------------\n";
        cout << "[07] Search For A Student By Name\n";
        cout << "[08] Search For A Student By Age\n";
        cout << "[09] Search For The Oldest Student\n";
        cout << "[10] Search For The Youngest Student\n";
        cout << "------------------------------------------------------\n";
        cout << "[11] Show Size Of Database \n";
        cout << "[12] Clear Database\n";
        cout << "[13] Transfer Data To Sorted Linked List\n";
        cout << "------------------------------------------------------\n";
        cout << "Enter a value: ";
        cin >> menu;
        }

    void editNodes(){
        string name , inputstring; 
        int age , inputint;
        getMenu();
        
        if (menu == 1)     // Push data to the front of the list
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
        else if (menu == 5)  // Delete data by name
        {
            if (a.getHead() == nullptr)
            {
                cout << "\nThe Database Is Empty\n";
            }
            else
            {
            cout << "\nEnter the name of the student you want to delete.\n";
            cout << "Name -> ";
            cin >> inputstring;
            a.pop_name(inputstring);
            }
        }
        else if (menu == 6)  // Delete data by age
        {
            if (a.getHead() == nullptr)
            {
                cout << "\nThe Database Is Empty\n";
            }
            else
            {
            cout << "\nEnter the age of students you want to delete.\n";
            cout << "Age -> ";
            cin >> inputint;
            a.pop_age(inputint);
            }
        }
        else if (menu == 7)  // Search Name
        {   
            if (a.getHead() == nullptr)
            {
                cout << "\nThe Database Is Empty\n";
            }
            else
            {
            cout << "\nEnter the name of the student you want to search.\n";
            cout << "Name -> ";
            cin >> inputstring;

            if (a.searchName(inputstring) == true)
            {
            a.searchNameAge(inputstring);
            }
            else
            {
            cout << "\nThe Student " << inputstring <<" Is Not In The Database\n";
            }
        }
        }
        else if (menu == 8)  // Search Age
        {   
            if (a.getHead() == nullptr)
            {
                cout << "\nThe Database Is Empty\n";
            }
            else
            {
            cout << "\nEnter the age of the student you want to search.\n";
            cout << "Age -> ";
            cin >> inputint;

            a.searchAge(inputint) ? 
            cout << "\nThere Are Students Aged " << inputint << " In The Database\n" :
            cout << "\nThere Are No Students Aged " << inputint << " In The Database\n";
            }
        }
        else if (menu == 9)  // Get Max
        {   
            a.findMax();
        }
        else if (menu == 10)  // Get Max
        {   
            a.findMin();
        }
        else if (menu == 11)  // Find Size Of List
        {    
            cout << "\nCurrent Size Of Database Is " << a.getSize() << " Nodes.\n";
        }
        else if (menu == 12)  // Find Size Of List
        {    
            a.deleteList();
            cout << "\nList Has Been Destroyed.\n";
        }

    }


};

int main(){
    Application app;
    return 0;
}