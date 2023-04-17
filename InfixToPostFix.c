#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <limits.h>
#include<string.h>
//using namespace std;
typedef long long ll;
void TakeInput(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
//step1 creat ur data type
#define Size 100
#define Empty (-1)

char Stack[100];
// [0,1,2,3]
//        t
int top = Empty;

//push function
void Push(char val){
    if(top == Size-1){
        printf("stack is overflow");
        return;
    }
    top++;
    Stack[top] = val;
}
char pop(){
    if(top == -1){
        //printf("stacck is empty we cant pop");
        return -1;
    }
    char res = Stack[top];
    top--;
    return res;

}
char Top(){
    if(top == -1){
        //printf("stacck is empty we cant get the top");
        return -1;
    }
    char res = Stack[top];
    return res;
}
int length(){
    return top+1;

}
int Isempty(){
    return top==-1;
}
int precedence(char c){
    if(c=='^')return 3;
    else if(c=='*' || c=='/')return 2;
    else if(c=='+' || c=='-')return 1;
    else return -1;
}
void InfixToPostfix(char *infix){
    int n = strlen(infix);
    char Posfix[n];
    int i = 0;
    int j = 0;
    while(infix[i]!='\0'){
        //rule 1
        if((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z')){
            Posfix[j]=infix[i];
            i++;
            j++;
        }
        else if(infix[i]=='('){
            Push(infix[i]);
            i++;
        }
        else if(infix[i]==')'){
            while(Top()!='('){
                Posfix[j]=pop();
                j++;
            }
            pop();
            i++;
        }
        else{
            while(!Isempty() && (precedence(infix[i]) <= precedence(Top()))){
                Posfix[j]=pop();
                j++;
            }
            Push(infix[i]);
            i++;
        }
    }
    while(!Isempty()){
        Posfix[j++]=pop();
    }
    Posfix[j]='\0';
    for(int i = 0 ; Posfix[i]!='\0' ;i++){
        printf("%c",Posfix[i]);
    }


}
int main(){
    TakeInput();
    char infix[100];
    scanf("%s",infix);
    InfixToPostfix(infix);

    
}









