#include <iostream>
using namespace std;

struct Node{
    int value;
    Node* next;
};

void Delete(int value);
void Print();

Node* head;

int main()
{
    int n;
    cout << "Enter the number of nodes you want in your linked list: ";
    cin >> n;

    //create our linked list with n items
    for(int i = 0; i < n; i++)
    {
        Node* new_node = new Node();
        cout << "Enter the value for a node: ";
        cin >> new_node->value;

        new_node->next = head;
        head = new_node;
    }

    Print();


    return 0;
}

void Print()
{
    Node* ptr = head;
    while(ptr != NULL)
    {
        cout << ptr->value << " ";
        ptr = ptr->next;
    }
}