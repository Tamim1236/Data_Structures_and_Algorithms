#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *head;

void Recursive_Print(Node *ptr);
void Reverse(Node *prev, Node *curr);

int main(){

    int num_nodes;
    cout << "How many nodes do you want in your linked list: ";
    cin >> num_nodes;

    for(int i = 0; i < num_nodes; i++)
    {
        Node* new_node = new Node();
        cout << "Enter a number you want in your linked list: ";
        cin >> new_node->data;

        new_node->next = head;
        head = new_node;
    }

    cout << "Here are the nodes present in your linked list: ";
    Recursive_Print(head);

    cout << endl << "Now let's reverse the list: " << endl;
    Reverse(NULL, head);
    Recursive_Print(head);
}

void Recursive_Print(Node *ptr)
{
    if(ptr == NULL) return;

    cout << ptr->data << " ";
    Recursive_Print(ptr->next);
}

void Reverse(Node *prev_node, Node *curr_node)
{
    if(curr_node == NULL){
        head = prev_node;
        return;
    }

    Reverse(curr_node, curr_node->next);
    curr_node->next = prev_node;
    prev_node = curr_node;
    curr_node = curr_node->next;
}