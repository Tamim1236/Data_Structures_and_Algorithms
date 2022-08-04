#include <stdio.h>
#include <stdlib.h>

//node struct
typedef struct
{
    int data;
    struct Node* next;
}Node;

Node* Insert(Node* head, int x);
void Print(Node* head);

int main()
{
    Node* head = NULL; //so far our list is empty
    printf("How many elements would you like in the list? ");
    int n;
    int x;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter a number: ");
        scanf("%d", &x);
        head = Insert(head, x); //insert this number as a node in linked list
        Print(head); //print all nodes of linked list
    }
}

//function to insert node to the beginning
Node* Insert(Node* head, int x)
{
    //create a new node
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->data = x;
    temp->next = head; //temp's next now points to the linked list
                       // if head empty (NULL) then temp->next also points to NULL
    head = temp; //head now points to our new node/list (new 1st element of list)
    return head;
    
}

//print all nodes
void Print(Node* head) //head is passed by value
{
    //Node* temp = head; (we would need to use temp if head was defined globally)
    printf("Here are the nodes currently in our list:\n");

    //linked list traversal
    while(head != NULL) //since head is passed by value we can traverse with that without changing actual list
    {
        printf(" %d", head->data);
        head = head->next; //keep going to next node
        
    }
    printf("\n");
}