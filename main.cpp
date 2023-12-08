//
//  main.cpp
//  FinalProjectDS
//
//  Last edited by Alie VanDeVoorde on 12/7/23.
//  This program will take user input and sort
//  using a linked list in order to tell the
//  user in what order to do their assignments.
//  Order is determined by the number of points
//  the assignment is worth.
//  This program was made without any outside help.

#include <iostream>
#include <vector>
#include <memory>
#include <queue>
using namespace std;

typedef struct node {
    int data;
    int priority;
 
    struct node* next;
 
} Node;
 
Node* newNode(int d, int p)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = d;  // Data will be assignment point values
    temp->priority = p;
    temp->next = NULL;
 
    return temp;
}
 

int peek(Node** head) { return (*head)->data; }

// Removes the element with the highest priority from the list
void pop(Node** head) {
    Node* temp = *head;
    (*head) = (*head)->next;
    free(temp);
}

// Function to push according to priority
void push(Node** head, int d, int p) {
    Node* start = (*head);
    
    //Create a new node
    Node* temp = newNode(d, p);
    
        // Checking incase the head of list has
        // lesser priority than new node. So
        // insert newnode before head node
        // and change head node.
        if ((*head)->priority > p)
        {
              
            // Insert New Node before head
            temp->next = *head;
            (*head) = temp;
        }
        else
        {
              
            // Traverse the list and find a
            // position to insert new node
            while (start->next != NULL &&
                start->next->priority < p)
            {
                start = start->next;
            }
      
            // Either at the ends of the list
            // or at required position
            temp->next = start->next;
            start->next = temp;
        }
    }
      
 
int isEmpty(Node** head) { return (*head) == NULL; }

void insertNode(Node*& head, int points) {
    Node* newNode = new Node{points, 0, nullptr};
    if (head == nullptr) {
        head = newNode; // if the list is empty the new node
        // becomes the head
    }
    else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current-> next;
        }
        // Insert the new node at the end
        current->next = newNode;
    }
}
 

// Function to diplay the linked list
void displayList(const Node* head) {
    const Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main()
{
    Node* head = nullptr; // Initializa an empty linked list
    priority_queue<int> priorityQueue; // Initialize a priority queue
    
    int numAssignments;
    cout << "Enter the number of assignments to do: ";
    cin >> numAssignments;
    
    for (int i = 0; i < numAssignments; ++i) {
        int points;
        cout << "Enter the point value to assignment " <<
        i + 1 << ": ";
        cin >> points;
        
        // Insert into linked list
        insertNode(head, points);
        
        // Insert into proproty queue
        priorityQueue.push(points);
    }
    
    cout << "Assignment list: " << endl;
    while (!priorityQueue.empty()) {
        cout << priorityQueue.top() << " " << endl;
          priorityQueue.pop();
      }
      cout << endl;
    
    Node* current = head;
       while (current != nullptr) {
           Node* nextNode = current->next;
           delete current;
           current = nextNode;
       }
    return 0;
}


/*
 Testing:
 Enter the number of assignments to do: 4
 Enter the point value to assignment 1: 30
 Enter the point value to assignment 2: 20
 Enter the point value to assignment 3: 5
 Enter the point value to assignment 4: 50
 Assignment list:
 50
 30
 20
 5 
 */
