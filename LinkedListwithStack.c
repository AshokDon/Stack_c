//implemet stack using linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *top=NULL;
void push(int x)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=top;
    top=newnode;
}
void pop()
{
    struct node *temp;
    if(top==NULL)
    {
        printf("stack is empty\n");
    }
    else
    {
        temp=top;//
        top=top->next;
        free(temp);
    }
}
void display()
{
    struct node *temp;
    if(top==NULL)
    {
        printf("stack is empty\n");
    }
    else
    {
        temp=top;
        while(temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp=temp->next;
        }
    }
}
int main()
{
    int ch,x;
    while(1)
    {
        printf("1.push\n");
        printf("2.pop\n");
        printf("3.display\n");
        printf("4.exit\n");
        printf("enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("enter the element to be pushed\n");
            scanf("%d",&x);
            push(x);
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
            printf("invalid choice\n");
        }
    }
    return 0;
}
