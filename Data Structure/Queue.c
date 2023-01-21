#include <stdio.h>
#define MAX 50
void enqueue();
void dequeue();
void display();
int queue[MAX];
int rear=-1;
int front=-1;
void main()
{
    int choice;
    while (1)
    {
        printf("1. Insert the elements to queue\n");
        printf("2. Delete elements from queue \n");
        printf("3. Display all elements of queue\n");
        printf("4. Quit\n\n");
        printf("Enter your choice : \n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        default:
            printf("Enter a valid choice");
        }
    }
}
void enqueue()
{
    int adit;
    if(rear==MAX-1)
        printf("Queue Overflow\n");
    else
    {
        if(front==-1)
        front=0;
        printf("Insert the elements in queue: ");
        scanf("%d",&adit);
        rear=rear+1;
        queue[rear]=adit;

    }
}
void dequeue()
{
    if(front==-1 || front>rear)
    {
        printf("Queue Underflow");
        return;
    }
    else
    {
     printf("Element successfully deleted from queue\n");
     front=front+1;
    }
}
void display()
{
    int i;
    if(front==-1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is :\n");
        for(i=front;i<=rear;i++)
            printf("%d \n",queue[i]);
            printf("\n");
    }
}
