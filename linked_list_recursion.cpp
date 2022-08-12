#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *head;

void Print(Node *ptr); //recursive print function

int main(){
    int num_nodes;
    cout << "Enter the number of nodes you want in your linked list: ";
    cin >> num_nodes;

    for(int i = 0 ; i < num_nodes; i++)
    {
        Node *new_node = new Node();
        cout << "Enter a value you want in your linked list: ";
        cin >> new_node->data;
        
        new_node->next = head;
        head = new_node;
    }

    cout << "Here is your linked list:" << endl;
    Print(head);
}

void Print(Node *ptr){
    if(ptr == NULL) return;

    cout << ptr->data << " ";
    Print(ptr->next);
    //cout << ptr->data << " "; //having this line after the recursive call allows for reverse print
}