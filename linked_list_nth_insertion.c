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
    //headptr = NULL;
    printf("Enter the number of nodes in your linked list: ");
    int n; //number of elements in the linked list
    int x; //current number to add to linked list
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        printf("Enter a number: ");
        scanf("%d", &x);
        Insert(x); //insert each number to create out initial linked list
    }
    
    Print();

    //get new number to add to the linked list
    int num;
    int position = -1;
    printf("Now enter a number you want to add to this linked list: ");
    scanf("%d", &num);
    
    //make sure a valid position is entered
    if(n == 0)
    {
        while(position != 0){
            printf("Enter a valid nth position you would like to add it at: ");
            scanf("%d", &position);
        }
    }
    else{
        while(!(position >= 0 && position <= n-1))
        {
            printf("Enter a valid nth position you would like to add it at: ");
            scanf("%d", &position);
        }
    }

    Insert_nth(num, position);
    Print();

    return 0;
}

void Print()
{
    printf("Here is your current linked list:\n");
    Node* ptr = headptr;
    while(ptr != NULL)
    {
        printf(" %d", ptr->value);
        ptr = ptr->next;
    }
    printf("\n");
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
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;
    
    Node* ptr = headptr;

    if(headptr == NULL) //if no nodes, so head points to nothing
    {
        new_node->next = headptr;
        headptr = new_node;
    }
    else
    {
        int curr_pos = 0;
        while(curr_pos != position - 1)
        {
            ptr = ptr->next;
            curr_pos++;
        }
        new_node->next = ptr->next;
        ptr->next = new_node;
    }

}