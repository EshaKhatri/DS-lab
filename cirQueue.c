#include <stdio.h>
#include<stdlib.h>
#define n 5
int front=-1;
int rear=-1;
int arr[n];

void enqueue(int x){
if(front==-1&&rear==-1){
    front=0;
    rear=0;
    arr[rear]=x;
    printf("\n Inserted -> %d", arr[rear]);
}
else if ((rear+1)%n==front){
    printf("Queue overflow!!");
}
else{
    rear=(rear+1)%n;
    arr[rear]=x;
    printf("\n Inserted -> %d", arr[rear]);
}
}

void dqueue(){
    if(front==-1&&rear==-1){
    printf("Queue underflow!!");
    }
    else if(front==rear){
        printf("\n Deleted element -> %d \n",arr[front]);
        front=-1;
        rear=-1;
    }
    else{
        printf("\n Deleted element -> %d \n",arr[front]);
        front=(front+1)%n;
    }
}

void display(){
     if(front==-1&&rear==-1){
    printf("Queue underflow!!");
    }

   else {
    int i ;
        for(i=front;i!=rear;i=(i+1)%n)
    {
        printf("%d\t",arr[i]);
    }
        printf("%d",arr[i]);

  }

}

int main()
{
    int x,c;
    while(1)
    {
        printf("\nEnter your choice:\n1.Enqueue\n2.Dequeue\n3.display\n4.exit\n");
        scanf("\n %d",&c);
        switch(c)
        {
            case 1:
             {
                printf("\nEnter the value to be pushed:\n");
                scanf("\n %d",&x);
                enqueue(x);
                break;
             }
            case 2:dqueue();
            break;
            case 3:display();
            break;
            case 4:exit(0);
            default:printf("\nEnter the valid input");


        }
    }
    return 0;
}

