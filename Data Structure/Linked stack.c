#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node{
int data;
struct node*next
}*top=NULL;
void push(int);
void pop();
void display();

void main()
{
    int choice, value;
    printf("\n::Stack implementation using Linked List::\n");
    while(1){
        printf("\nStack Operations\n");
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
            {
            case 1:
                printf("Enter the value to be inserted : ");
                scanf("%d",&value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nEnter a valid choice\n");
            }
            }
}
void push(int value)
{
    struct node*newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=value;
    if(top==NULL)
    {
        newNode->next=NULL;
    }
    else
    {
        newNode->next=top;
    }
    top=newNode;
    printf("\nInsertion is successful");
}
void pop()
{
    if(top==NULL)
    {
        printf("\nThe Stack is Empty\n");
    }
    else
    {
    struct node*temp=top;
    printf("The deleted element :%d",temp->data);
    top=temp->next;
    free(temp);
    }
}
void display()
{

    if(top==NULL)
    {
        printf("\nThe Stack is Empty\n");
    }
    else
    {
        struct node*temp=top;
        while(temp->next!=NULL)
        {
            printf("%d-->",temp->data);
            temp=temp->next;
        }
        printf("%d-->NULL",temp->data);
    }
}
