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

int isBalanced(char *exp){
    struct Stack stk;
    int i;

    stk.size = strlen(exp);
    stk.top = -1;
    stk.S = (char *)malloc(stk.size*sizeof(char));

    for(i=0; exp[i]!='\0'; i++){
        if(exp[i] == '(')
            push(&stk, exp[i]);
        else if(exp[i] == ')'){
            if(isEmpty(stk)){
                destroy(&stk);
                return 0;
            }
            pop(&stk);
        }
    }

    if(isEmpty(stk)){
        destroy(&stk);
        return 1;
    }
    destroy(&stk);
    return 0;
}

int isBalanced2(char *exp){
    struct Stack stk;
    int i, x, y;

    stk.size = strlen(exp);
    stk.top = -1;
    stk.S = (char *)malloc(stk.size*sizeof(char));

    for(i=0; exp[i]!='\0'; i++){
        if(exp[i] == '[' || exp[i] == '{' || exp[i] == '(')
            push(&stk, exp[i]);
        else if(exp[i] == ']' || exp[i] == '}' || exp[i] == ')'){
            if(isEmpty(stk)){
                destroy(&stk);
                return 0;
            }

            x = pop(&stk);
            y = exp[i];
            if(y < 50){
                if(abs(y-x) > 1){
                    destroy(&stk);
                    return 0;
                }
            }
            else{
                if(abs(y-x) > 2){
                    destroy(&stk);
                    return 0;
                }
            }
        }
    }

    if(isEmpty(stk)){
        destroy(&stk);
        return 1;
    }
    destroy(&stk);
    return 0;
}

int main(){
    char *exp1 = "((a+b)*(c-d))";
    char *exp2 = "((p*q)-r)+(a+b)-c)";
    char *exp3 = "(((a+b)*(c-d))";
    char *exp4 = "{([a+b]*[c-d])/e}";
    char *exp5 = "{([a+b)*[c-d]]/e}";

    if(isBalanced(exp1))
        printf("The expression \'%s\' is balanced.\n", exp1);
    else
        printf("The expression \'%s\' is not balanced.\n", exp1);

    if(isBalanced(exp2))
        printf("The expression \'%s\' is balanced.\n", exp2);
    else
        printf("The expression \'%s\' is not balanced.\n", exp2);

    if(isBalanced(exp3))
        printf("The expression \'%s\' is balanced.\n", exp3);
    else
        printf("The expression \'%s\' is not balanced.\n", exp3);

    printf("%d\n", isBalanced2(exp4));
    printf("%d\n", isBalanced2(exp5));
    
    return 0;
}