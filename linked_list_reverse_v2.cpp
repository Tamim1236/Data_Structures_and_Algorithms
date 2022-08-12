#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void Insert(int value);
void Print();
void Reverse();

Node* head;

int main(){
    
    int num_nodes; 
    cout << "Enter the number of nodes you want in your linked list: ";
    cin >> num_nodes;

    //int num;
    for(int i = 0; i < num_nodes; i++)
    {
        int num;
        cout << "Enter a number to add to the linked list: ";
        cin >> num;
        Insert(num);

        // Node* new_node = new Node();
        // cout << "Enter a number to add to the linked list: ";
        // cin >> new_node->data;
        // new_node->next = head->next;
        // head = new_node;
        

        // Node* new_node = new Node();
        // new_node->data = num;
        // new_node->next = head->next;
        // head = new_node;
    }

    Print();
}

//insert a new node at the beginning of the linked list
void Insert(int value)
{
    Node* new_node = new Node();
    new_node->data = value;
    new_node->next = head; //the new node points to the list (what head points to)
    head = new_node; //head now points to new node (new start of list)
}

void Print(){
    cout << "Here are the current nodes in the linked list:" << endl;
    Node* tempptr = head;
    while(tempptr != NULL)
    {
        cout << tempptr->data << " ";
        tempptr = tempptr->next;
    }
    cout << "" << endl;
}