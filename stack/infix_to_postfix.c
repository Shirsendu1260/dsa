#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stack{
    int size;
    int top;
    char *S;
};

void destroy(struct Stack *st){
    free(st->S);
    printf("Stack is deleted.\n");
}

int isEmpty(struct Stack st){
    if(st.top == -1)
        return 1;
    return 0;
}

int isFull(struct Stack st){
    if(st.top == st.size-1)
        return 1;
    return 0;
}

void push(struct Stack *st, char ch){
    if(isFull(*st)){
        printf("Stack Overflow\n");
    }
    else{
        st->top++;
        st->S[st->top] = ch;
    }
}

char pop(struct Stack *st){
    char ch;

    if(isEmpty(*st)){
        printf("Stack Underflow.\n");
    }
    else{
        ch = st->S[st->top];
        st->top--;
    }

    return ch;
}

int stackTop(struct Stack st){
    if(isEmpty(st))
        return -1;
    return st.S[st.top];
}

int isOperand(char x){
    if(x=='+' || x=='-' || x=='*' || x=='/')
        return 0;
    return 1;
}

int isOperand2(char x){
    if(x=='+' || x=='-' || x=='*' || x=='/' || x=='^' || x=='(' || x==')')
        return 0;
    return 1;
}

int pre(char x){
    if(x=='+' || x=='-')
        return 1;
    else if(x=='*' || x=='/')
        return 2;
    return 0;
}

int out_pre(char x){
    if(x=='+' || x=='-')
        return 1;
    else if(x=='*' || x=='/')
        return 3;
    else if(x=='^')
        return 6;
    else if(x=='(')
        return 7;
    else if(x==')')
        return 0;
    return 0;
}

int in_pre(char x){
    if(x=='+' || x=='-')
        return 2;
    else if(x=='*' || x=='/')
        return 4;
    else if(x=='^')
        return 5;
    else if(x=='(')
        return 0;
    return 0;
}

void infix_to_postfix(char *infix){
    struct Stack stk;
    char *postfix;
    int i=0, j=0;

    stk.size = strlen(infix);
    stk.top = -1;
    stk.S = (char *)malloc(stk.size*sizeof(char));

    postfix = (char *)malloc((stk.size+1)*sizeof(char));

    while(infix[i] != '\0'){
        if(isOperand(infix[i])){
            postfix[j++] = infix[i++];
        }
        else{
            if(pre(infix[i]) > pre(stackTop(stk))){
                push(&stk, infix[i]);
                i++;
            }
            else{
                postfix[j++] = pop(&stk);
            }
        }
    }

    while(!isEmpty(stk)){
        postfix[j++] = pop(&stk);
    }
    postfix[j] = '\0';

    printf("Postfix exp. of the infix exp \'%s\': %s\n", infix, postfix);

    destroy(&stk);
}

void infix_to_postfix2(char *infix){
    struct Stack stk;
    char *postfix;
    int i=0, j=0;

    stk.size = strlen(infix);
    stk.top = -1;
    stk.S = (char *)malloc(stk.size*sizeof(char));

    postfix = (char *)malloc((stk.size+1)*sizeof(char));

    while(infix[i] != '\0'){
        if(isOperand2(infix[i])){
            postfix[j++] = infix[i++];
        }
        else{
            if(out_pre(infix[i]) > in_pre(stackTop(stk))){
                push(&stk, infix[i]);
                i++;
            }
            else if(out_pre(infix[i]) < in_pre(stackTop(stk))){
                postfix[j++] = pop(&stk);
            }
            else{
                pop(&stk);
                i++;
                j++;
            }
        }
    }

    while(!isEmpty(stk)){
        postfix[j++] = pop(&stk);
    }
    postfix[j] = '\0';

    printf("Postfix exp. of the infix exp \'%s\': %s\n", infix, postfix);

    destroy(&stk);
}

int main(){
    char *infix1 = "a+b*c-d/e";
    char *infix2 = "((a+b)*c)-d^e^f";

    infix_to_postfix(infix1);
    infix_to_postfix2(infix2);
    
    return 0;
}