#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <limits.h>
//using namespace std;
typedef long long ll;
void TakeInput(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
//step1 creat ur data type
struct node{
    char ch;
    struct node *next;
    struct node *prev;
 
}*stack[50];
int top = -1;
 
typedef struct node node;
 
void Push(node* temp){
    top++;
    stack[top]=temp;
}
node *pop(){
    node *nn = stack[top];
    top--;
    return nn;
}
void PostFixToInfix(char exp[]){
    node *temp;
    node *op1;
    node *op2;
    for(int i = 0 ; exp[i]!='\0' ; i++){
        if((exp[i] >= 'a' && exp[i]<='z') || (exp[i]>='A' && exp[i]<='Z')){
            temp = (node*)malloc(sizeof(node));
            temp->ch = exp[i];
            temp->next=NULL;
            temp->prev=NULL;
            Push(temp);
        }
        else if(exp[i]=='+' || exp[i]=='-' || exp[i]=='/' || exp[i]=='*' || exp[i]=='^'){
            op1 = pop();
            op2 = pop();
            temp = (node*)malloc(sizeof(node));
            temp->ch = exp[i];
            temp->next = op1;
            temp->prev = op2;
            Push(temp); 
        }
    }
}
void Display(node *temp){
    if(temp!=NULL){
        Display(temp->prev);
        printf("%c ",temp->ch);
        Display(temp->next);
    }
}
int main(){
    TakeInput();
    char exp[50];
    scanf("%s",exp);
    PostFixToInfix(exp);
    Display(pop());
}
 
 
