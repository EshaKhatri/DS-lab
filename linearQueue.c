#include <stdio.h>
#define MAX 50
int queue_array[MAX];
int rear = -1 , front = -1, value ;
void enqueue();
void dqueue();
void display();
main()
{
    int choice;
    while(1)
    {
    printf(" \n1.Insert \n");
    printf("2.Delete \n");
    printf("3.Display \n");
    printf("4.Exit \n");
    printf("Enter your choice : ");
    scanf("%d",&choice);
    
    switch (choice)
        {
            case 1 :
            printf("Enter the value : ");
            scanf("%d",&value);
            enqueue(value);
            break;
            case 2 :
            dqueue();
            break;
            case 3 :
            display();
            break;
            case 4 :
            exit(1);
            break;
            default:
            printf("Invalid choice \n");
        }
        
    }
}

void enqueue()
{
    if (rear==MAX-1)
    printf("Queue is full");
    else if(rear == -1 && front == -1)
    {rear = front = 0;}
    else 
    {rear = rear + 1 ;}
    queue_array[rear]=value;
    printf("element %d is added to the queue. ",queue_array[rear]);
}

void dqueue()
{
    if (rear == -1 && front == -1)
    printf("Queue is empty");
    else if (front == rear)
    {   front=-1;
        rear=-1;
    }
    else
    {printf("Deleted element is : %d", queue_array[front]);
    front = front + 1 ;}
}

void display()
{
    int i ; 
    if (rear == -1 && front == -1)
    printf("Queue is empty");
    else
    {
        printf("Queue is : ");
        for(i=front;i<=rear;i++)
        printf("%d", queue_array[i]);
        printf("\n");
    }
}
