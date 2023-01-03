#include <iostream>
#include <iomanip>
#include <utility>
#include <string>
#include <climits>

using namespace std;

struct Node{
    string name;
    int age;
    Node *next;

    int data;
    Node *link;

    Node(string n, int a){
        name = n;
        age = a;
        next = nullptr;
    }

    Node(int x){
        this->data = x;
        this->link = nullptr;
    }
};

class LinkedList{
    Node *head;
    Node *tail;
    Node *sorted;
    int size;
    friend class sortedLinkedList;

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
    
    // Function to push data to the back
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
                    cout << "\nStudent Deleted.\n";
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
                    cout << "\nStudent Deleted.\n";
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
        return max;

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
        return min;

        }


    // Function to print out my glorious list
    void printList(){
        Node *ptr = head;
        if (head == nullptr)
        {
            cout << "\n---------------------------------";
            cout << "\n|        Current Database       |\n";
            cout << "---------------------------------\n";
            cout << "|       Database Is Empty       |\n";
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

    // Sort the link list
    void Sort(){
        sorted = nullptr;
        Node *current = head;

        while (current != nullptr){
            Node *next = current->next;
            sortedInsert(current);
            current = next;
        }
        head = sorted;
    }

    void sortedInsert(Node *newNode) {
        if (sorted == nullptr || sorted->age >= newNode->age) 
        {
            newNode->next = sorted;
            sorted = newNode;
        }
        else
        {
            Node *current = sorted;
            while (current->next != nullptr && current->next->age < newNode->age) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }
      
void deleteList()
    {
        Node* current = head;
        Node* next = nullptr;
    
        while (current != NULL)
        {
            next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

};

class sortedLinkedList{
  private:
    LinkedList a;
    Node *sorted;
    int size;
  public:
   
    Node* getHead(){
        return a.head;
    }
    void sortedpush(string name,int age){
        Node *nNode = new Node(name, age);
        Node *ptr = a.head;
        Node *current;
        if (ptr == nullptr || ptr->age >= nNode->age)
        {
            nNode->next = a.head;
            a.head = nNode;
        }
        else 
        {   
            current = a.head;
            while (current->next != nullptr && current->next->age < nNode->age)
            {
                current = current->next;
            }
            nNode->next = current->next;
            current->next = nNode;
        }

    }

    // Function to delete data by key string
    void pop_subject(string key) {
        Node *prev = nullptr;
        Node *current = a.head;
        while(current != nullptr)
        {
            if (current->name == key)
            {
                if (current == a.head)
                {
                    a.head = a.head->next;
                    delete current;
                    current = a.head;
                    cout << "\nData Deleted.\n";

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
            }
        }
        
    }
    
    // Function to delete data by key int
    void pop_marks(int key) {
        Node *prev = nullptr;
        Node *current = a.head;
        while(current != nullptr)
        {
            if (current->age == key)
            {
                if (current == a.head)
                {
                    a.head = a.head->next;
                    delete current;
                    current = a.head;
                    cout << "\nData Deleted.\n";

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
            }
        }
        
    }
        

    void sortedPrintList() {
    Node* ptr = a.head;
        if (a.head == nullptr)
        {
            cout << "---------------------------------\n";
            cout << "|          No Data Added        |\n";
            cout << "---------------------------------\n";
        }
        else
        {
            cout << "\n---------------------------------";
            cout << "\n|          ScoreSheet           |\n";
            cout << "---------------------------------\n";
                    cout << "| "; 
                    cout.width(20);
                    cout << left << "Subject" << "| ";
                    cout.width(8);
                    cout << "Marks" << "|" << endl;          
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

class stack{
    Node* top;

  public:
    stack() {top = nullptr;}

    // Push data into stack
    void push(int data) {
        Node *temp = new Node(data);

        if (!temp) {
            cout << "\nStack Overflow";
        }

        temp->data = data;
        temp->link = top;
        top = temp;
    }

    // Check stack is empty or not
    bool isEmpty() {
        return top == nullptr;
    }

    // Return top element of the stack
    int peek(){
        if (!isEmpty())
        {
            return top->data;
        }
        else
        {
            cout << "\n------------------\n";
            cout << "~ Stack Is Empty ~";
            cout << "\n------------------\n";

        }
    }

    void pop(){
        Node *temp;

        if (top == nullptr)
        {
            cout << "\n------------------\n";
            cout << "~ Stack Is Empty ~";
            cout << "\n------------------\n";
        }
        else
        {
            temp = top;
            top = top->link;
            delete temp;
        }
    }

    void display(){
        Node *temp;

        if (top == nullptr)
        {
            cout << "\n------------------\n";
            cout << "~ Stack Is Empty ~";
            cout << "\n------------------\n";
        }
        else
        {
            temp = top;
            cout << "\n-------------";
            cout << "\n| Stack     |\n";
            cout << "-------------\n";      
            while (temp != nullptr) {
                cout << left << "| "; 
                cout.width(10);
                cout << temp->data << "|" << endl;
                temp = temp->link;
            }
        cout << "-------------\n";
        }


    }


};

class BST {
    int data;
    BST *left, *right;

  public:
    BST();
    BST(int);
    BST* insert(BST* , int);
    void inOrder(BST*);


};

BST :: BST() : data(0) , left(nullptr) , right(nullptr){}

BST :: BST(int value){ data = value; left = right = nullptr;}

BST * BST :: insert(BST* root , int value) {
    if (!root) 
    {
        return new BST(value);
    }

    if(value > root->data) 
    {
        root->right = insert(root->right , value);
    }

    else if (value < root->data)
    {
        root->left = insert(root->left , value);
    }

    return root;
}

void BST :: inOrder(BST * root) {
    if (!root)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}



class Application{
    LinkedList a;
    sortedLinkedList s;
    stack z;
    BST b , *root = nullptr;
    int menu;

public:
    Application(){
        
        constructLinkedList();    // Run header message
        listMenu();                 
    }

    void constructLinkedList() {
        cout << "\n~~~ Linked List Constructed ~~~\n\n";
        cout << "---------------------------------------\n";
        cout << "|\tMMU Student's Database\t      |\n";
        cout << "---------------------------------------\n";
        }

    void listMenu() {
        a.printList(); 
        cout << "--------------------------------------------------------\n";
        cout << "| Linked List Menu                                     |\n";
        cout << "--------------------------------------------------------\n";
        cout << "[01] Add A Student To The Top Of The Database          |\n";
        cout << "[02] Add A Student To The Bottom Of The Database       |\n";
        cout << "[03] Remove A Student From The Top Of The Database     |\n";
        cout << "[04] Remove A Student From The Bottom Of The Database  |\n";
        cout << "[05] Remove A Student From The Database By Name        |\n";
        cout << "[06] Remove A Student From The Database By Age         |\n";
        cout << "--------------------------------------------------------\n";
        cout << "[07] Search For A Student By Name                      |\n";
        cout << "[08] Search For A Student By Age                       |\n";
        cout << "[09] Search For The Oldest Student                     |\n";
        cout << "[10] Search For The Youngest Student                   |\n";
        cout << "--------------------------------------------------------\n";
        cout << "[11] Show Size Of Database                             |\n";
        cout << "[12] Sort The Database                                 |\n";
        cout << "[13] Clear The Database                                |\n";
        cout << "--------------------------------------------------------\n";
        cout << "[99] Procede To Sorted Linked List                     |\n";
        cout << "--------------------------------------------------------\n";
        cout << "Enter a value: ";
        cin >> menu;
        editNodes();
        }

    void editNodes(){
        string name , inputstring; 
        int age , inputint;
        
        if (menu == 1)     // Push data to the front of the list
        {
            cout << "\nEnter the name and age of the student.\n";
            cout << "Name -> ";
            cin.ignore(); getline(cin,name);
            cout << "Age  -> "; 
            cin >> age;
            a.push_front(name, age);
            cout << "\nStudent Successfully Added.\n";
            listMenu();
        }
        else if (menu == 2)  // Push data to the end of the list
        {
            cout << "\nEnter the name and age of the student.\n";
            cout << "Name -> ";
            cin.ignore(); getline(cin,name);
            cout << "Age  -> "; 
            cin >> age;
            a.push_back(name, age);
            cout << "\nStudent Successfully Added.\n";
            listMenu();
        }
        else if (menu == 3)  // Delete data at the front of the list
        {
            a.pop_front();
            listMenu();
        }
        else if (menu == 4)  // Delete data at the back of the list
        {
            a.pop_back();
            listMenu();
        }
        else if (menu == 5)  // Delete data by name
        {
            if (a.getHead() == nullptr)
            {
                cout << "\nThe Database Is Empty\n";
                listMenu();
            }
            else
            {
            cout << "\nEnter the name of the student you want to delete.\n";
            cout << "Name -> ";
            cin.ignore(); getline(cin,inputstring);
            a.pop_name(inputstring);
            }
            listMenu();
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
            listMenu();
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
            cin.ignore(); getline(cin,inputstring);

            a.searchName(inputstring) ? 
            cout << "\nThe Student " << inputstring << " Is In The Database\n" :
            cout << "\nThe Student " << inputstring <<" Is Not In The Database\n";
            }
            listMenu();
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
            listMenu();
        }
        else if (menu == 9)  // Get Max
        {   
            cout << "\nThe Oldest Student Is " << a.findMax() << " Years Old.";
            listMenu();
        }
        else if (menu == 10)  // Get Max
        {   
            cout << "\nThe Youngest Student Is " << a.findMin() << " Years Old.";
            listMenu();
        }
        else if (menu == 11)  // Find Size Of List
        {    
            cout << "\nCurrent Size Of Database Is " << a.getSize() << " Nodes.\n";
            listMenu();
        }
        else if (menu == 13)  // Sort the linked list
        {   
            a.Sort();
            listMenu();
        }
        else if (menu == 12)  // Delete entire list
        {   
            a.deleteList();
            cout << "\nDatabase Cleared.\n";
            listMenu();
        }
        else if (menu == 99)  // Sort the linked list
        {   
            constructSortedLinkedList();
            sortedMenu();
        }
        else
        {
            cout << "\nPlease Enter A Valid Input :(\n";
            listMenu();
        }
    }

    void constructSortedLinkedList() {
        cout << "\n~~~ Sorted Linked List Constructed ~~~\n\n";
        cout << "---------------------------------------\n";
        cout << "|\tSorting Exam Test Scores      |\n";
        cout << "---------------------------------------\n";
        }

    void sortedMenu() {
        s.sortedPrintList();
        cout << "--------------------------------------------------------\n";
        cout << "| Sorted Linked List Menu                              |\n";
        cout << "--------------------------------------------------------\n";
        cout << "[01] Add A Subject And Marks To Be Sorted              |\n";
        cout << "[02] Delete Data by Subject Name                       |\n";
        cout << "[03] Delete Data by Marks                              |\n";
        cout << "--------------------------------------------------------\n";
        cout << "[99] Procede To Linked Stack                           |\n";
        cout << "--------------------------------------------------------\n";
        cout << "Enter a value: ";
        cin >> menu;
        editSortedNodes();
        }

    void editSortedNodes(){
        string subject , inputstring;
        int marks , inputint;

        if (menu == 1)      // Add data to be sorted
        {
            int count;
            cout << "\nHow Many Data Do You Want To Add?\n";
            cin >> count;
            cout << "\nEnter the Subject And Marks To Sort.\n";
            for (int i = 0; i < count; i++){
                cout << "Subject -> ";
                cin.ignore(); getline(cin,subject);
                cout << "Marks   -> "; 
                cin >> marks;
                cout << endl;
                s.sortedpush(subject, marks);
            }   
            cout << "\nData Successfully Added.\n";
            sortedMenu();
        }

        else if (menu == 2)
        {
             if (s.getHead() == nullptr)
                {
                    cout << "\nThe Scoresheet Is Empty\n";
                }
            else
                {
                    cout << "\nEnter The Subject You Want To Delete.\n";
                    cout << "Subject -> ";
                    cin.ignore(); getline(cin,inputstring);
                    s.pop_subject(inputstring);
                }
            sortedMenu();
        }

        else if (menu == 3)
        {
            if (s.getHead() == nullptr)
                {
                    cout << "\nThe Scoresheet Is Empty\n";
                }
                else
                {
                cout << "\nEnter The Marks you Want To Delete.\n";
                cout << "Marks -> ";
                cin >> inputint;
                s.pop_marks(inputint);
                
                }
            sortedMenu();
        }

        else if (menu == 99)
        {
            constructStack();
            stackMenu();
        }

        else
        {
            cout << "\nPlease Enter A Valid Input :(\n";
            sortedMenu();
        }
    
    }

    void constructStack() {
        cout << "\n~~~ Linked Stack Contructed ~~~\n\n";
        cout << "-------------------------\n";
        cout << "|    The Great Stack    |\n";
        cout << "-------------------------\n";
        }

    void stackMenu() {
        z.display();
        cout << "\n--------------------------------------------------------\n";
        cout << "| Linked Stack Menu                                    |\n";
        cout << "--------------------------------------------------------\n";
        cout << "[01] Add Number To The Stack                           |\n";
        cout << "[02] Delete Top Of The Stack                           |\n";
        cout << "--------------------------------------------------------\n";
        cout << "[99] Procede To Binary Search Tree                     |\n";
        cout << "--------------------------------------------------------\n";
        cout << "Enter a value: ";
        cin >> menu;
        editStack();
        }

    void editStack(){
        int input;

        if (menu == 1) 
        {
            cout << "\nPlease Enter Number To Stack :";
            cin >> input;
            z.push(input);
            stackMenu();
        }

        else if (menu == 2) 
        {
            z.pop();
            stackMenu();
        }

        else if (menu == 99) 
        {
            constructBST();
            BSTMenu();
        }

        else
        {
            cout << "\nPlease Enter A Valid Input :(\n";
            stackMenu();
        }
    }


void constructBST() {
        cout << "\n~~~ Binary Search Tree Contructed ~~~\n\n";
        cout << "---------------------------\n";
        cout << "|    Binary Search Tree    |\n";
        cout << "---------------------------\n";
        }

    void BSTMenu() {
        cout << "\n--------------------------------------------------------\n";
        cout << "| Binary Search Tree Menu                              |\n";
        cout << "--------------------------------------------------------\n";
        cout << "[01] Add x Numbers To The Tree                         |\n";
        cout << "[02] Sort And Print                                    |\n";
        cout << "--------------------------------------------------------\n";
        cout << "[00] End The Program                                   |\n";
        cout << "--------------------------------------------------------\n";
        cout << "Enter a value: ";
        cin >> menu;
        editBTS();
        }
    
    void editBTS() {
        int input , count;
        
        if (menu == 1) 
        {
            cout << "\nHow many numbers would you like to add?: ";
            cin >> count;
            cout << "\nPlease Enter Number(s) \n";
            for (int i = 0; i < count ; i++)
            {
                cout << "-> ";
                cin >> input;
                root = b.insert(root , input);
            }
            BSTMenu();
        }

        else if (menu == 2) 
        {
            cout << "Data In Order Is:\n";
            b.inOrder(root);
            cout << endl;
            BSTMenu();
        }

    }

};



int main(){
    Application app;
    return 0;
}