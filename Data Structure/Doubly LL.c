#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void instBegin();
void instEnd();
void instBtw();
void delBegin();
void delEnd();
void delBtw();
void display();

struct Node
{
   int data;
   struct Node*prev,*next;
}*head=NULL;

void main()
{
   int choice=0;
    while(choice!=8)
    {
        printf("\nMain menu\n\n");
        printf("Choose a function\n\n");
        printf(" 1.Insert at beginning\n 2.Insert at end\n 3.Insert in between\n 4.Delete at beginning\n 5.Delete at last\n 6.Delete in between\n 7.Display the list\n 8.End \n");
        printf("\n Enter the choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            instBegin();
            break;
            case 2:
            instEnd();
            break;
            case 3:
            instBtw();
            break;
            case 4:
            delBegin();
            break;
            case 5:
            delEnd();
            break;
            case 6:
            delBtw();
            break;
            case 7:
            display();
            break;
            default:
            printf("Enter a valid choice! \n");
            break;
            case 8:
            exit(0);
            break;
        }
    }
}

void instBegin()
{
    struct Node *newNode,*temp;
    int value;
    printf("Enter the value to be inserted: ");
    scanf("%d",&value);
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = value;
    newNode -> prev = NULL;
    if(head == NULL)
    {
       newNode -> next = NULL;
       head = newNode;
    }
    else
    {
       newNode->next=head;
       head = newNode;
       temp=newNode->next;
       temp->prev=newNode;
    }
    printf("\nInsertion success!!!");
}
void instEnd()
{
   struct Node *newNode;
   int value;
   printf("Enter the value to be inserted: ");
   scanf("%d",&value);
   newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode -> data = value;
   newNode -> next = NULL;
   if(head == NULL)
   {
      newNode -> prev = NULL;
      head = newNode;
   }
   else
   {
      struct Node *temp = head;
      while(temp->next!=NULL)
  {
         temp=temp->next;
  }
   temp->next=newNode;
   newNode ->
   prev = temp;
   }
   printf("\nInsertion success!!!");
}
void instBtw()
{
   struct Node *newNode,*temp=head,*temp1;
   int value,location;
   printf("Enter the value to be inserted: ");
   scanf("%d",&value);
   printf("Enter the value after which the new value should be inserted: ");
   scanf("%d",&location);
   newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode -> data = value;
   if(head == NULL)
   {
      newNode -> prev = newNode -> next = NULL;
      head = newNode;
   }
   else
   {
       while(temp->data!=location)
       {
           temp=temp->next;
       }
       temp1=temp->next;
       newNode->next=temp1;
       newNode->prev=temp;
       temp1->prev=newNode;
       temp->next=newNode;
   }
   printf("\nInsertion success!!!");
}
void delBegin()
{
   if(head == NULL)
      printf("Underflow!");
   else
   {
      struct Node *temp = head;
      if(temp -> prev == temp -> next)
      {
         head = NULL;
         free(temp);
      }
      else{
         head = temp -> next;
         head -> prev = NULL;
         free(temp);
      }
      printf("\nDeletion success!!!");
   }
}
void delEnd()
{
   if(head == NULL)
      printf("Underflow!");
   else
   {
      struct Node *temp = head,*temp1;
      if(temp->prev==temp->next)
      {
         head=NULL;
         free(temp);
      }
      else
      {
         while(temp->next!=NULL)
         {
            temp=temp->next;
         }
         temp1=temp->prev;
         temp1->next=NULL;
         free(temp);
      }
      printf("\nDeletion success!!!");
   }
}
void delBtw()
{
   struct Node *temp=head,*temp1,*temp2;
   int delValue;
   printf("Enter the value to be deleted: ");
   scanf("%d",&delValue);
   if(head==NULL)
   {
      printf("Underflow!");
   }
   else
   {
      while(temp->data!=delValue)
      {
          temp=temp->next;
      }
      if(temp->next==NULL)
      {
          printf("The entered location does not exist");
      }
      else
      {
          temp1=temp->prev;
          temp2=temp->next;
          temp1->next=temp2;
          temp2->prev=temp1;
          free(temp);
          printf("\nDeletion success!!!");
      }
   }
}
void display()
{
    struct Node *temp=head;
    printf("\nThe doubly linked list: \n");
    printf("NULL<--");
    while(temp->next!= NULL)
    {
        printf("%d<==>",temp->data);
        temp=temp->next;
    }
    printf("%d-->NULL",temp->data);
}

