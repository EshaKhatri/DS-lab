#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node
{
                int data;
                struct node *link;
};
typedef struct node * NODE;

NODE getnode()
{
                NODE x;
                x = (NODE)malloc(sizeof(struct node));
                if(x==NULL)
                {
                                printf("\nInsufficient memory");
                                exit(0);
                }
                x->link = NULL;
                return x;
}

NODE insert(NODE first)
{
                int val;
                NODE temp, cur;
                temp = getnode();

                printf("\nEnter the value: ");
                scanf("%d", &val);
                temp->data = val;

                if(first==NULL)
                                return temp;

                cur = first;
                while(cur->link!=NULL)
                {
                                cur = cur->link;
                }
                cur->link = temp;
                return first;
}

NODE concat(NODE first, NODE second)
{
                NODE cur;
                if(first==NULL)
                                return second;
                if(second==NULL)
                                return first;
                cur =first;
                while(cur->link!=NULL)
                {
                                cur = cur->link;
                }
                cur->link = second;
                return first;
}

void display(NODE first)
{
                NODE cur;
                cur = first;
                printf("\nContents are:\n");
                if(cur == NULL)
                                printf("\nList is empty. Nothing to display.");
                else
                {
                                while(cur!=NULL)
                                {
                                                printf("%d \t ", cur->data);
                                                cur = cur->link;
                                }
                }
}

void main()
{
                int ch, i , n1,n2;
                NODE first = NULL;
                NODE second =NULL;

                printf("\nEnter number of nodes for list1: ");
                scanf("%d", &n1);
                for(i=0;i<n1;i++)
                                first = insert(first);

                printf("\nEnter number of nodes for list2: ");
                scanf("%d", &n2);
                for(i=0;i<n2;i++)
                                second = insert(second);

                first = concat(first, second);
                display(first);
}

