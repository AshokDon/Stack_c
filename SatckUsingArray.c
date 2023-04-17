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
//stack implementation using array
#define Maxi 10
#define Empty (-1);
int stack[Maxi];
int top = -1;

void Push(int val){
    if(top == Maxi-1){
        printf("stack is filled");
        return;
    }
    top++;
    stack[top]=val;
}
int pop(){
    if(top==-1){
        return -1;
    }
    int res = stack[top];
    top--;
    return res;
}
int Top(){
    if(top==-1){
        return -1;
    }
    int res = stack[top];
    
    return res;
}
int size(){
    return top+1;
}
int Isempty(){
    return top==-1;
}
int main(){
    TakeInput();
    Push(10);
    Push(30);
    Push(40);
    Push(50);
    Push(60);
    pop();
    printf("%d",Top());
    while(!Isempty()){
        printf("%d \n",Top());
        pop();
    }
}
 
 

