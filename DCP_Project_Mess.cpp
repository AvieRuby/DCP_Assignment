#include <iostream>
#include <iomanip>

using namespace std;

int c;                                                                      // Global variable CHOICE


// Created a node class
class Node 
    {
        public:
            string name;                 // Declare string variable name
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
                }
            
            void printCurrent()
                {                  
                    if (headName == NULL)
                        {
                            cout << "\nCurrent List\n";                                 // Print current list
                            cout << "------------------------------\n";
                            cout << "|         LIST IS EMPTY       |\n";
                            cout << "------------------------------\n";
                        }

                    else
                        {      
                            cout << "\nCurrent List\n";                                 // Print current list
                            cout << "------------------------------\n";
                            input.printList(headName , headAge);
                            cout << "------------------------------\n";

                        }
                }
        };

// Created a delete class
class Delete
    {
        public:


        // Fucntion to delete node
        void deleteNode(Node*& head , Node*& tail , string deleted)     
            {
                if(head == NULL)
                    {
                        return;
                    }
                if (head->name == deleted)                                      // Deletes the link list if input value is correct
                    {
                        Node* t = head;
                        Node * u = tail;
                        head = head->nextName;
                        tail = tail->nextAge;

                        delete(t);
                        delete(u);
                        return;
                    }
                deleteNode(head->nextName , tail->nextAge , deleted);           // Repeat until all same values are deleted
            }

    };

// Created a search class
class searchData
    {
        public:
        bool search(Node* head , string x)                                  // Check if data entered is in the list
            {

                if(head == NULL)
                    {
                        return false;
                    }
                if(head->name == x)
                    {
                        return true;
                    }
                else
                    {
                        return search(head->nextName , x);
                    }
            }

    };

// Created a find min and max class
class findMinMax
    {
        public:
        int smallestElement(Node* head , Node* tail)
            {
                int min = INT_MIN;
                while (head != NULL)
                    {
                        if (min < head->age)
                            {
                                min = head->age;
                                head = head->nextAge;
                                tail = tail->nextName;
                            }   
                        return min;        
                    }

            }
        
        string namedSmallestElement(Node* head , Node* tail)
            {
                int min = INT_MIN;
                string minName;

                while (head != NULL)
                    {
                        if (min < head->age)
                            {
                                minName = head->name;
                                head = head->nextAge;
                                tail = tail->nextName;

                            }   
                        return minName; 
                    }

            }

        int largestElement(Node* head)
            {
                int max;
                while (head != NULL)
                    {
                        if (max > head->age)
                            {
                                max = head->age;
                                head = head->nextAge;
                            }   

                    }
                return max; 
            }
        
        string namedLargestElement(Node* head , Node* tail)
            {
                int max = INT_MAX;
                string maxName;

                while (head != NULL)
                    {
                        if (max > head->age)
                            {
                                max = head->age;
                                head = head->nextAge;
                                maxName = tail->name;
                                tail = tail->nextName;
                            }   

                    }
                return maxName; 
            }  
    };



// Created a printing class
class printing
    {
        private:
        getInfo info;
        Delete kill;
        searchData search;
        findMinMax find;

        public:
        // Print intoduction
        void intro()
            {
                cout << "---------------------------------\n";                
                cout << "|\tMMU Student's Data\t|\n";
                cout << "---------------------------------\n";   
            }
        // Print choices 
        int choice()
            {
                cout << "----------------------------------------------\n";
                cout << "What would you like to do?\n";                               
                cout << "[0] End Program\n";                  
                cout << "[1] Add student details into the database\n";
                cout << "[2] Delete student details from the database\n";
                cout << "[3] Print current list\n";
                cout << "[4] Search current list\n";
                cout << "[5] Find the youngest student\n";
                cout << "[6] Find the oldest student\n";
                cout << "----------------------------------------------\n";
                cout << "Choice : ";
                cin >> c;
                cout << "----------------------------------------------\n";


                return c;

            }  

        // Function to get choice
        void getChoice()
            {
                string deletedPerson , searchPerson;

                // Executes set name and age function if 1
                if(c == 1)                              
                    {
                        info.setNameAge();
                        choice();
                    }
                // Executes delete function if 2    
                if(c == 2)                                                          
                    {
                        if (info.headName == NULL)                                              
                            {
                                cout << "The list is empty , please try again\n";
                                choice();
                            }
                                cout << "\nWhich student do you want to delete : ";             
                                cin >> deletedPerson;
                                kill.deleteNode(info.headName ,info.headAge , deletedPerson);
                                choice();
                    }
                // Executes print function if 3
                if(c == 3)                                                          
                    {
                        info.printCurrent();
                        choice();
                    }
                // Executes search function if 4
                if(c == 4)
                    {
                        if (info.headAge == NULL)
                            {
                                cout << "The list is empty, please try again\n\n";
                                choice();
                            }
                        if(info.headAge != NULL)
                            {                           
                                cout << "\nType name of student you want to search : ";      
                                cin >> searchPerson;
                                search.search(info.headName , searchPerson) ? cout << "Student's info is in the list :) \n\n" : cout << "Student does not exist in the list:( \n\n";
                                choice();
                            }
                    }
                // Execute find min fuction if 5
                if(c == 5)                                                            
                    {
                        if (info.headAge == NULL)
                            {
                                cout << "The list is empty , please try again\n";
                                choice();
                            }
                        if (info.headAge != NULL)
                                {
                                    cout << "\nThe youngest student is " ;
                                    cout << find.namedSmallestElement(info.headAge , info.headName) << " at " << find.smallestElement(info.headAge , info.headName) << " years old." << endl;
                                    choice();
                                }
                    }
                if(c == 6)                                                            
                    {
                        if (info.headAge == NULL)
                            {
                                cout << "The list is empty , please try again\n";
                                choice();
                            }
                        if (info.headAge != NULL)
                                {
                                    cout << "\nThe oldest student is " ;
                                    cout << find.namedLargestElement(info.headAge , info.headName) << " at " << find.largestElement(info.headAge) << " years old." << endl;
                                    choice();
                                }
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
  
