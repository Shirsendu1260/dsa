#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stack{
    int size;
    int top;
    int *S;
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

void push(struct Stack *st, int val){
    if(isFull(*st)){
        printf("Stack Overflow\n");
    }
    else{
        st->top++;
        st->S[st->top] = val;
    }
}

int pop(struct Stack *st){
    int x;

    if(isEmpty(*st)){
        printf("Stack Underflow.\n");
    }
    else{
        x = st->S[st->top];
        st->top--;
    }

    return x;
}

int isOperand(char x){
    if(x=='+' || x=='-' || x=='*' || x=='/')
        return 0;
    return 1;
}

int postfix_evaluation(char *postfix){
    struct Stack stk;
    int i, x1, x2, r, res;

    stk.size = strlen(postfix);
    stk.top = -1;
    stk.S = (int *)malloc(stk.size*sizeof(int));

    for(i=0; postfix[i]!='\0'; i++){
        if(isOperand(postfix[i])){
            push(&stk, postfix[i]-'0');
        }
        else{
            x2 = pop(&stk);
            x1 = pop(&stk);

            switch(postfix[i]){
                case '+':
                    r = x1 + x2;
                    push(&stk, r);
                    break;
                case '-':
                    r = x1 - x2;
                    push(&stk, r);
                    break;
                case '*':
                    r = x1 * x2;
                    push(&stk, r);
                    break;
                case '/':
                    r = x1 / x2;
                    push(&stk, r);
                    break;
            }
        }
    }

    res =  pop(&stk);
    destroy(&stk);
    
    return res;
}

int main(){
    char *postfix = "35*62/+4-";

    printf("Result of the postfix exp. \'%s\': %d\n", postfix, postfix_evaluation(postfix));
    
    return 0;
}