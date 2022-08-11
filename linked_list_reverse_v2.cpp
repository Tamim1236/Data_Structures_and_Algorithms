#include <iostream>
using namespace std;

void Insert();
void Print();
void Reverse();

struct Node{
    int data;
    Node* next;
};

int main(){
    
    int num_nodes; 
    cout << "Enter the number of nodes you want in your linked list: ";
    cin >> num_nodes;

    for(int i = 0; i < num_nodes; i++)
    {
        int num;
        cout << "Enter a number to add to the linked list: ";
        cin >> num;
    }
}