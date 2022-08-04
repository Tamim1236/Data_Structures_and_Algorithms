#include <iostream>
using namespace std;

typedef struct{
    int value;
    Node* next;
}Node;

void Insert(int value);
void Delete(int value);
void Print();

Node* head;

int main()
{
    int n;
    cout << "Enter the number of nodes you want in your linked list: ";
    scanf("%d", &n);

}