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
    cout << "Now we will reverse the linked list: " << endl;
    Reverse();
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

void Reverse()
{
    int num_nodes; // number of nodes in the linked list
    Node* tempptr = head; //used to store final node position
    
    while(tempptr->next != NULL) //tempptr->next so that we don't go past last element
    {
        num_nodes++;
        tempptr = tempptr->next;
    }

    int last_index = num_nodes - 1; //get index of last node in list
    Node* tempptr2 = tempptr; //used to traverse backwards from end

    while(tempptr2 != head)
    {
        last_index -= 1; //to get index of previous
        int counter = 0; //count up to index
        Node* prev_location = head; //pointer to record the position value at previous Node

        while(counter != last_index)
        {
            prev_location = prev_location->next;
            counter++;
        }
        tempptr2->next = prev_location; //set next of current node to previous node (reverse link)
        tempptr2 = prev_location; //tempptr now points to previous node
    }

    tempptr2->next = NULL; //set first node's next to be NULL
    head = tempptr; //final assignment to set head equal to last element
}