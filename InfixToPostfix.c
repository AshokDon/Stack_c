
//https://www.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1


// Function to convert infix expression to postfix expression
//DS -> stack

const int MAX = 30;
char stack[30];
int top;
void SetTop(){
    top = -1;
}
void Push(char c){
    top++;
    stack[top] = c;
}
void pop(){
    if(top==-1){
        return;
    }
    top--;
}
char Top(){
    return stack[top];
}
int Empty(){
    return top==-1;
}
int Value(char c){
    if(c == '-' || c == '+') return 1;
    else if(c == '*' || c == '/') return 2;
    else if(c == '^') return 3;
    else return 4;
}
char* infixToPostfix(char* s) {
    SetTop();
    char *str = (char *)malloc(30*sizeof(char));
    
    int j = 0;
    int n = sizeof(s)/sizeof(char);
    for(int i = 0 ; s[i]!='\0' ; i++){
        
        if(s[i]!='+' && s[i]!='-' && s[i] != '^' && s[i]!='*' && s[i]!='/' && s[i]!='(' && s[i]!=')'){
            str[j]=s[i];
            j++;
        }
        else{
            if(s[i]=='(' || Empty()){
                Push(s[i]);
            }
            else if(s[i] == ')'){
                while(!Empty() && Top()!='('){
                    str[j++]=Top();
                    pop();
                }
                pop();
            }
            else if(!Empty() && Top()=='('){
                Push(s[i]);
            }
            else if(!Empty() && Value(s[i]) > Value(Top())){
                Push(s[i]);
            }
            else{
                while(!Empty() && Top()!='(' && Value(s[i]) <= Value(Top())){
                    str[j++] = Top();
                    pop();
                }
                Push(s[i]);
            }
            
            
         }
    }
    while(!Empty()){
        str[j++]=Top();
        pop();
    }
    // for(int i = 0 ; str[i]!='\0' ; i++){
    //     printf("%c",str[i]);
    // }
    return str;
    
    
}
