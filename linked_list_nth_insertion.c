#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int value;
    struct Node* next;
}Node;

Node* headptr;
void Insert(int value);
void Insert_nth(int value, int position);
void Print();

int main()
{
    printf("Enter the number of nodes in your linked list: ");
    int n,x;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        printf("Enter a number: ");
        scanf("%d", &x);
        Insert(x); //insert each number to create out initial linked list
    }
    printf("Here is your current linked list:\n");
    Print();

    // int num, position;
    // printf("Now enter a number you want to add to this linked list: ");
    // scanf("%d", &num);
    // printf("Enter the position you would like to add it at: ");
    // scanf("%d", &position);


    return 0;
}

void Print()
{
    Node* ptr = headptr;
    while(ptr != NULL)
    {
        printf(" %d", ptr->value);
        ptr = ptr->next;
    }
}

//insert a node to the beginning of the list
void Insert(int value)
{
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = headptr;
    headptr = new_node;
}

void Insert_nth(int value, int position){
    ;
}