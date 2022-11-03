#include <iostream>
#include <iomanip>

using namespace std;

// Created a printing class
class printing
    {
        private:
        friend class getInfo;
        int c;

        public:
        void intro()
            {
                cout << "---------------------------------\n";                // Print intoduction
                cout << "|\tMMU Student's Data\t|\n";
                cout << "---------------------------------\n";   
            }

        int choice()
            {

                cout << "What would you like to do?\n";                         // Print choices
                cout << "[1] Add student details into the database\n";
                cout << "[2] Delete student details from the database\n";

                cin >> c;
                return c;

            }  
    };

// Created a node class
class Node 
    {
        public:
            string name;                       // Declare string variable name
            int age;                           // Declare int variable age
            Node *nextName , *nextAge;         // Declare Node pointer variables
    };

// Created a pushList class
class pushList
    {
        public:

        // Insert a new name node at the end
        void pushName(Node** head_ref, string new_data)  
            {  
                Node* new_node = new Node();            // Allocate new node       
                Node *last = *head_ref;                 // Declaration for last node 

                new_node->name = new_data;              // Insert the data  
                new_node->nextName = NULL;                  // Setting this node to NULL cause its the last one
                
                // Check if linked list is empty, then make the new node as head 
                if (*head_ref == NULL)  
                    {  
                        *head_ref = new_node;  
                        return;  
                    }  
                
                // If linked list is not empty, traverse till the last node 
                while (last->nextName != NULL)
                    {
                        last = last->nextName;  
                    }
                
                // Change the next of last node 
                last->nextName = new_node;  
                return;  
            }


        // Insert a new age node at the end
        void pushAge(Node** head_ref, int new_data)
            {
                Node* new_node = new Node();            // Allocate new node       
                Node *last = *head_ref;                 // Declaration for last node 

                new_node->age = new_data;              // Insert the data  
                new_node->nextAge = NULL;                  // Setting this node to NULL cause its the last one
                
                // Check if linked list is empty, then make the new node as head 
                if (*head_ref == NULL)  
                    {  
                        *head_ref = new_node;  
                        return;  
                    }  
                
                // If linked list is not empty, traverse till the last node 
                while (last->nextAge != NULL)
                    {
                        last = last->nextAge;  
                    }
                
                // Change the next of last node 
                last->nextAge = new_node;  
                return;  
            }

        // This function prints contents of linked list starting from the given node
        void printList(Node* n , Node* m)
            {
                while (n != NULL) 
                    {             
                        cout << "| ";                           // Loop to print data in order 
                        cout.width(20);
                        cout << left << n->name << "| ";
                        cout.width(5);
                        cout << m->age << "|" << endl;
                        n = n->nextName;
                        m = m->nextAge;
                    }
            }
    };

// Created a Delete class
class Delete
    {
        public:
        // Created struct for remove node
        struct Node
            {
                string data;
                Node *link = NULL;
                Node() {}
                Node(string a) : data(a) {}
            };
        

        void deleteNode(Node*&head , string name)
            {
                if(head == NULL)
                    {
                        cout << "List is empty";
                        return;
                    }
                if(head->data == name)
                    {
                        Node *t = head;
                        head = head->link;

                        delete (t);
                        return;
                    }


                deleteNode(head->link , name);
            }

        void pushDeleted(Node*& head, string data)
            {
                Node *newNode = new Node(data);
                newNode->link = head;
                head = newNode;
            }

        void printDelete(Node* head , Node* n , Node* m)
            {
                while (n != NULL) 
                    {             
                        cout << "| ";                           // Loop to print data in order 
                        cout.width(20);
                        cout << left << n->name << "| ";
                        cout.width(5);
                        cout << m->age << "|" << endl;
                        n = n->nextName;
                        m = m->nextAge;
                    }
            }

        //Function to choose which data to delete
        void chooseDelete(Node* head)
            {
                string deletion;

                cout << "Please enter name you would like to delete: ";
                cin >> deletion;

                deleteNode(head , deletion);
            }
    };


// Created a getInfo class
class getInfo
    {
        private:
            string x;                                   // Declare private variables x and y
            int y;
            Node *headName = NULL , *headAge = NULL;    // Declare pointer variables for name and age    
            pushList input;                              // Call class getData ***Can probably do friend class***
            printing p;
            Delete D;

        public:
            // Function to get choice
            void getChoice(int z)
                {
                    if(z == 1)
                        {
                            setNameAge();
                        }
                    if(z == 2)
                        {
                            D.chooseDelete(headName);
                        }
                                 
                }
     
            // Function to get input 
            void setNameAge()   
                {           

                    cout << "Input Names and Age\n";    
                    while ( x != "0")                                           // Keeps asking for input while name isnt 0
                    {
                        cout << "\nInput Name: ";
                        cin >> x;                                               // User input name
                            {                    
                                if (x != "0")
                                    {
                                        input.pushName(&headName, x);           // Send name into link list

                                        cout << "Input Age : ";
                                        cin >> y;                               // User input age

                                        input.pushAge(&headAge, y);             // Send age into link list
                                        
                                        cout << "\nCurrent List\n";                             // Print current list
                                        cout << "------------------------------\n";
                                        input.printList(headName , headAge);
                                        cout << "------------------------------\n";
                                    }
                            }

                    }
                }



    };


int main()
    {
        printing print; 
        getInfo info;                               // Declare class getInfo variable
        Node *headName , *headAge;                  // Declare class Node variables

        print.intro();
        print.choice();
        info.getChoice(print.choice());
        info.setNameAge();                          // Gets user input name / age, prints current list
        

        return 0;
    }
  
