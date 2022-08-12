#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node *head;

void Print(Node* head);
void Recursive_Reverse(Node* ptr);

int main(){
    int num_nodes;
    cout << "Enter the number of nodes you want in your linked list: ";
    cin >> num_nodes;

    for(int i = 0; i < num_nodes; i++)
    {
        Node* new_node = new Node();
        cout << "Enter a value to add to your list: ";
        cin >> new_node->data;

        new_node->next = head;
        head = new_node;
    }

    cout << "Here is your current linked list:" << endl;
    Print(head);
    cout << endl << "Now here is the linked list reversed: " << endl;
    Recursive_Reverse(head);
    Print(head);
}

void Print(Node* ptr)
{
    if(ptr == NULL) return;

    cout << ptr->data << " ";
    Print(ptr->next);
}

void Recursive_Reverse(Node* ptr){
    if(ptr->next == NULL)
    {
        head = ptr;
        return;
    }

    Recursive_Reverse(ptr->next); //allows us to traverse the list
    Node* q = ptr->next;
    q->next = ptr;
    ptr->next = NULL;
}