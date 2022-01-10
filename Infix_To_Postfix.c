#include<stdio.h>
#define MAX 30

int top=-1;
char st[MAX];

void push(char symbol)
{
	top=top+1;
	st[top]=symbol;
}

char pop()
{
	return st[top--];
}

int isOperand(char symbol)
{
	if((symbol>='A' && symbol<='Z')||(symbol>='a' && symbol<='z'))
		return 1;
	else
		return 0;
}

int isOperator(char symbol)
{
	if(symbol=='+'||symbol=='-'||symbol=='*'||symbol=='/'||symbol=='^')
		return 1;
	else
		return 0;
}

int precedence(char symbol)
{
	int result;
	switch(symbol)
	{
		case '(':result=0;
				 break;
		case '+':
		case '-':result=1;
				 break;
		case '*':
		case '/':result=2;
				 break;
		case '^':result=3;
				 break;
	}
	return result;
}

main()
{
	int i=0,j=0,l=0;
	char infix[MAX],postfix[MAX],symbol,tmp;
	printf("Enter infix: ");
	scanf("%s",infix);
	push('(');
	tmp=infix[i++];
	while(tmp!='\0')
	{
		if(isOperand(tmp)||isOperator(tmp))
			l++;
		tmp=infix[i++];
	}
	for(i=0;i<strlen(infix);i++)
	{
		symbol=infix[i];
		if(isOperand(symbol))
			postfix[j++]=symbol;
		if(symbol=='(')
			push(symbol);
		if(isOperator(symbol))
		{
			while(precedence(st[top])>=precedence(symbol))
			{
				tmp=pop();
				postfix[j]=tmp;
				j++;
			}
			push(symbol);
		}
		if(symbol==')')
		{
			while(st[top]!='(')
			{
				tmp=pop();
				postfix[j++]=tmp;
			}
			tmp=pop();
		}
	}
	while((tmp=pop())!='(')
		postfix[j++]=tmp;
	postfix[l]='\0';
	printf("Postfix Expression: %s",postfix);
}