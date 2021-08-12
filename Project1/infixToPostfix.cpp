#include<stdio.h>

int top=-1, head=-1;

void push(char stack[],char p);
char pop(char stack[]);

void infixToPostfix(char str[]);
int priority(char Operator);

//push function--->>
void push(char stack[],char p)
{
	top++;
	stack[top]=p;
}

//pop function--->>
char pop(char stack[])
{
	int a=top;
	top--;
	return stack[a];
}

//converting infix to postfix--->>
void infixToPostfix(char str[]){
	int i , j=0 ;
	char stack[50] , A[50] , temp;

	for(i=0 ; str[i]!=NULL ; i++){

		//bracket balance-->>
		if(str[i]=='('){
			push(stack,str[i]);
		}
		else if(str[i]==')'){
			while(stack[top]!='('){
				A[j]=pop(stack);  //pop kore A te rakho
				j++;
			}
			temp=pop(stack);
		}

		//operator managing-->>
		else if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]=='^'){
			if(priority(str[i]) > priority(stack[top])) //stack top soto hole push
				push(stack,str[i]);
			else{
				while(priority(str[i]) <= priority(stack[top])){
					A[j]=pop(stack);
					j++;
				}
				push(stack,str[i]);
			}
		}
		//for operand-->>
		else{
			A[j]=str[i];
		    j++;
		}
	}
	//left items in stack-->>
	while(top!=-1){
		A[j]=pop(stack);
		j++;
	}
	A[j]=NULL;

	printf("Postfix: ");
	puts(A);
}

//priority of operator-->>
int priority(char Operator){
	if(Operator=='+'|| Operator=='-')
		return 1;
	else if(Operator=='*'|| Operator=='/')
		return 2;
	else if(Operator=='^')
		return 3;
	else
		return -1;
}

int main(){
	char str[50];      //for input 
	printf("Infix expression: ");
	gets(str);
	infixToPostfix(str);
	return 0;
}