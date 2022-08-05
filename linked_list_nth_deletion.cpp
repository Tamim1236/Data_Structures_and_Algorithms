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

    //node removal
    int value;
    cout << "Enter the value you want to delete: ";
    cin >> value;
    Delete(value);
    Print();


    return 0;
}

void Print()
{
    cout << "Here are the nodes in you list: " << endl;
    Node* ptr = head;
    while(ptr != NULL)
    {
        cout << ptr->value << " ";
        ptr = ptr->next;
    }
    cout << "" <<endl;
}

void Delete(int value)
{
    Node* ptr = head;
    
    //if we want to remove the first node
    if(head->value == value)
    {
        head = head->next;
        return;
    }

    while(ptr->next->value != value) //traverse till we reach node before one to be removed (with value == 'value') 
    {
        ptr = ptr->next;
    }
    
    if(ptr->next->value == value){
        ptr->next = ptr->next->next; //node before one to be removed should point to next of one to be removed (unlink intended node)
    }
    else
    {
        cout << "The value you wished to remove is not present in." << endl;
    }
}