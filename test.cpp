#include <iostream>

using namespace std;

// Creates a node class
class Node 
    {
        public:
            string name;                       // Declare string variable name
            int age;                           // Declare int variable age
            Node *nextName , *nextAge;         // Declare Node pointer variables
    };

class getData
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
    };

// This function prints contents of linked list starting from the given node
void printList(Node* n , Node* m)
    {
        while (n != NULL) 
            {             
                cout << "| " << n->name << "\t\t|\t" << n->age << " |" << endl;     // Loop to print data in order 
                n = n->nextName;
                m = m->nextAge;
            }
    }

// Created a getInfo class
class getInfo
    {
        private:
            string x;                                   // Declare private variables x and y
            int y;
            Node *headName = NULL , *headAge = NULL;    // Declare pointer variables for name and age    
            getData input;                              // Call class getData ***Can probably do friend class***

        public:

            //Function to print intro
            void printIntro()
                {
                    cout << "Sorting data\n";
                    cout << "Input Names and Age (0 or next)\n";
                }
            
            // Function to get input 
            void setNameAge()       
                {
                    while ( x != "0")
                    {
                        cout << "\nInput Name: ";
                        cin >> x;
                            {                    
                                if (x != "0")
                                    {
                                        input.pushName(&headName, x);

                                        cout << "Input Age: ";
                                        cin >> y; 

                                        input.pushAge(&headAge, y);
                                    }
                            }
                        cout << "\nCurrent List\n";
                        cout << "----------------------------\n";
                        printList(headName , headAge);
                        cout << "----------------------------\n";
                    }


                }

    };
  





int main()
    {
        getInfo info;
        Node *headName , *headAge;

        info.printIntro();
        info.setNameAge();
        printList(headName , headAge);
        



    
        return 0;
    }
  
