#include <iostream>

using namespace std;

// Creates a node class
class Node 
    {
        public:
            string data;
            Node* next;
    };

// Inserts a new node on the front of the list
void push(Node** head_ref, string new_data) 
    { 
        Node* new_node = new Node();        // Allocate node 
        new_node->data = new_data;          // Insert the data
        new_node->next = (*head_ref);       // Make next of new node as head 
        (*head_ref) = new_node;             // Move the head to point to the new node     
    } 

// Insert a new node after the given node
void insertAfter(Node* prev_node, string new_data)
    {
    
        // 1. Check if the given prev_node is NULL
        if (prev_node == NULL) 
            {
                cout << "The given previous node cannot be NULL";
                return;
            }
    
        Node* new_node = new Node();        // Allocate new node
        new_node->data = new_data;          // Insert the data
        new_node->next = prev_node->next;   // Make next of new node as next of prev_node
        prev_node->next = new_node;         // Move the next of prev_node as new_node
    }


// Insert a new node at the end 
void append(Node** head_ref, string new_data)  
    {  
        Node* new_node = new Node();            // Allocate new node       
        Node *last = *head_ref;                 // Declaration for last node 

        new_node->data = new_data;              // Insert the data  
        new_node->next = NULL;                  // Setting this node to NULL cause its the last one
        
        // Check if linked list is empty, then make the new node as head 
        if (*head_ref == NULL)  
            {  
                *head_ref = new_node;  
                return;  
            }  
        
        // If linked list is not empty, traverse till the last node 
        while (last->next != NULL)
            {
                last = last->next;  
            }
        
        // Change the next of last node 
        last->next = new_node;  
        return;  
    }  

// This function prints contents of linked list starting from the given node
void printList(Node* n)
    {
        while (n != NULL) {
            cout << "| " << n->data << "\t\t|\t" << n->next->data << " |" << endl;
            n = n->next->next;
        }
    }

// Created a getInfo class
class getInfo
    {
        private:
            string x ,y;
            Node* head = NULL;

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
                                        append(&head, x);

                                        cout << "Input Age: ";
                                        cin >> y; 

                                        append(&head, y);
                                    }
                            }
                        cout << "\nCurrent List\n";
                        cout << "----------------------------\n";
                        printList(head);
                        cout << "----------------------------\n";
                    }


                }

    };
  





int main()
    {
        getInfo info;
        Node *head;

        info.printIntro();
        info.setNameAge();
        printList(head);
        



    
        return 0;
    }
  
