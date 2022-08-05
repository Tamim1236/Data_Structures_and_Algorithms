#include <iostream>
using namespace std;

struct Node{
    int value;
    Node* next;
};

void Reverse();
void Print();

Node* head;

int main()
{
    //get the number of elements/nodes that the linked list will consist of
    int num;
    cout << "Enter the number of elements would you like in your linked list: ";
    cin >> num;

    for(int i = 0; i < num; i++)
    {
        //create new node to be added to the list
        Node* new_node = new Node();
        cout << "Enter a value you want in your list: ";
        cin >> new_node->value;

        //add new node to the beginning of the list
        new_node->next = head;
        head = new_node;
    }
    Print();
}

void Print()
{
    cout << "Here is your current linked list: ";
    Node* tempptr = head;
    while(tempptr != NULL)
    {
        cout << tempptr->value << " ";
        tempptr = tempptr->next;
    }
    cout << "" << endl;
}