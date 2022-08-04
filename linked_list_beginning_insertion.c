#include <stdio.h>
#include <stdlib.h>

//node struct
typedef struct
{
    int data;
    struct Node* next;
}Node;

struct Node* head;
void Insert(int x);
void Print();

int main()
{
    head = NULL; //so far our list is empty
    printf("How many elements would you like in the list?");
    int n;
    int x;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter a number:\n");
        scanf("%d", &x);
        Insert(x); //insert this number as a node in linked list
        Print(); //print all nodes of linked list
    }
}

//function to insert node to the beginning
void Insert(int x)
{
    //create a new node
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->data = x;
    temp->next = NULL;
}