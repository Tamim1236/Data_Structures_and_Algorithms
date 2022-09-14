#include <iostream>
using namespace std;

void Insert(int value);
void Print();
void Reverse();

struct Node{
    int data;
    Node* next;
};

Node* head;

int main(){
    
    int num_nodes; 
    cout << "Enter the number of nodes you want in your linked list: ";
    cin >> num_nodes;

    for(int i = 0; i < num_nodes; i++)
    {
        int num;
        cout << "Enter a number to add to the linked list: ";
        cin >> num;
        Insert(num);
    }

    Print();

    cout << "Now here is your linked list reversed:" << endl;
    Reverse();
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

void Reverse(){
    Node *prev_node, *curr_node, *next_node;

    prev_node = NULL;
    curr_node = head;
    next_node = curr_node->next;

    while(curr_node != NULL)
    {
        curr_node->next = prev_node; //reverse link
        //move our group of three pointers ahead one
        prev_node = curr_node;
        curr_node = next_node;
        
        /*!!! without this, at the last node, we would have next_node point to null and then try
        to access next_node->next (NULL Pointer Exception) - Alternatively, we could have defined next=curr->next at the
        beginning of the while loop instead of outside first and avoid this case*/
        if(next_node != NULL) 
            next_node = next_node->next;
    }
    
    head = prev_node; //once curr_node is NULL, head is set to prev_node (which is last node)
}
//