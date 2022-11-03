#include <iostream>
#include <iomanip>

using namespace std;

int c;                                                                      // Global variable CHOICE


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

// Created a getInfo class
class getInfo
    {
        private:
            string x;                                   // Declare private variables x and y
            int y;
            Node *headName = NULL , *headAge = NULL;    // Declare pointer variables for name and age    
            pushList input;                              // Call class getData ***Can probably do friend class***
            friend class printing;

        public:   
            // Function to get input 
            void setNameAge()   
                {            
                        cout << "\nInput Name: ";
                        cin >> x;                                               // User input name
                        input.pushName(&headName, x);                           // Send name into link list

                        cout << "Input Age : ";
                        cin >> y;                                               // User input age

                        input.pushAge(&headAge, y);                             // Send age into link list
                        
                        printCurrent();                                         // Prints current list
                }
            
            void printCurrent()
                {                        
                    cout << "\nCurrent List\n";                                 // Print current list
                    cout << "------------------------------\n";
                    input.printList(headName , headAge);
                    cout << "------------------------------\n";
                }
        };

// Created a delete class
class Delete
    {
        private:
        pushList Input;
        
        public:
        // Fucntion to delete node
        void deleteNode(Node*& tail , Node*& head , string deleted)     
            {
                if (head == NULL)                                               // Check if link list is empty
                    {
                        cout << "The list is empty\n";
                        return;
                    }
                
                if (head->name == deleted)                                      // Deletes the link list if input value is correct
                    {
                        Node* t = head;
                        head = head->nextName;
                        tail = tail->nextAge;

                        delete(t);
                        return;
                    }
                deleteNode(tail->nextAge , head->nextName , deleted);           // Repeat until all same values are deleted
            }

    };



// Created a printing class
class printing
    {
        friend class getInfo;
        private:
        getInfo info;
        Delete kill;

        public:
        void intro()
            {
                cout << "---------------------------------\n";                // Print intoduction
                cout << "|\tMMU Student's Data\t|\n";
                cout << "---------------------------------\n";   
            }

        int choice()
            {

                cout << "What would you like to do?\n";                             // Print choices   
                cout << "[0] End Program\n";                  
                cout << "[1] Add student details into the database\n";
                cout << "[2] Delete student details from the database\n";
                cout << "[3] Print current list\n";

                cout << "\nChoice :";

                cin >> c;
                return c;

            }  

        // Function to get choice
        void getChoice()
            {
                string deletedPerson;

                if(c == 1)                                                          // Executes set name and age function if 1
                    {
                        info.setNameAge();
                        choice();
                    }
                if(c == 2)                                                          // Executes delete function if 2
                    {
                        cout << "\nWho do you want to delete : ";
                        cin >> deletedPerson;
                        kill.deleteNode(info.headAge , info.headName , deletedPerson);
                        info.printCurrent();
                        choice();
                    }
                if(c == 3)
                    {
                        info.printCurrent();
                        choice();
                    }
                                
            }
    };



int main()
    {
        printing print; 
        getInfo info;                               // Declare class getInfo variable
        Node *headName , *headAge;                  // Declare class Node variables

        print.intro();                              // Prints intro
        print.choice();                             // Prints choices
        do
            {
                print.getChoice();                  // Loops to get info and choices / prints output
            } while (c != 0);

        cout << "Program Ended";

        return 0;
    }
  
