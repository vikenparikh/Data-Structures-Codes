            /* Viken Parikh
            SE Comps B2 1411099
              infix to prefix*/

#include<stdio.h>
#include<conio.h>
#include<math.h>

char charstack[100];
int chartop=-1;
char opstack[100];
int optop=-1;
int evalstack[100];
int evaltop=-1;

void push(char *a,int *top,char val);
char pop(char *a, int *top);
void pushi(int *a,int *top,int val);
int popi(int *a, int *top);
int precedence(char c);
int isNotEmpty(char *a,int *top);
char peek(char *a, int *top);
int getstr(char *s);

void push(char *a, int *top,char val)
{
    if(*top>=99){
	//printf("Stack Overflow\n");
	return;
    }
    else{
	a[++(*top)]=val;
    }
}

char pop(char *a, int *top)
{
    if(*top<0){
	printf("Stack Underflow\n");
    }
    else{
	char temp =a[(*top)--];
	return temp;
    }
}

void pushi(int *a, int *top,int val)
{
    if(*top>=99){
    //printf("Stack Overflow\n");
    return;
    }
    else{
    a[++(*top)]=val;
    }
}

int popi(int *a, int *top)
{
    if(*top<0){
    printf("Stack Underflow\n");
    }
    else{
    char temp =a[(*top)--];
    return temp;
    }
}

int precedence(char c)
{
    switch(c)
    {
    case '(':
    case ')':
	return -1;
    case '+':
    case '-':
	return 0;
    case '*':
    case '/':
    case '%':
	return 1;
    case '^':
	return 2;
    };
}
int isNotEmpty(char *a,int *top)
{
    return (*top)>=0;
}

char peek(char *a, int *top)
{
    return a[*top];
}

int getstr(char *s)
{
    int c,i=0;
    while((c=getchar())!='\n'){
        s[i++]=c;
    }
    s[i]='\0';
    return i;
}
int main()
{
    char s[100];
    int i,j,k,len;
    char a[100];
    clrscr();
    printf("Enter expression\n");
    len = getstr(s);
    printf("%s\t%d\n",s,len);
    for(i=0;i<len;i++){
	push(charstack,&chartop,s[i]);
	//printf("%c\n",peek(charstack,&chartop));
    }
    j=0;
    //printf("here\n");
    while(chartop>=0){
	//printf("here\n");
	char ch= pop(charstack,&chartop);
	printf("%c\n",ch);
	if(ch<='z' && ch>='a'){
	    a[j++]=ch;
	}
	else if(ch==')'){
	    //printf("here\n");
	    push(opstack,&optop,ch);
	}
	else if(ch=='('){
	    //printf("%c\n",peek(opstack,&optop));
	    char ch2=pop(opstack,&optop);
	    while(ch2!=')'){
		a[j++]=ch2;
		ch2=pop(opstack,&optop);
	    }
	}
	else{
	    if(!isNotEmpty(opstack,&optop)){
		push(opstack,&optop,ch);
	    }
	    else{
		if(precedence(peek(opstack,&optop))>=precedence(ch)){
		    a[j++]=pop(opstack,&optop);
		}
		push(opstack,&optop,ch);
	    }
	}
    }
    while(optop>=0){
	a[j++]=pop(opstack,&optop);
    }
    for(i=j-1;i>=0;i--){
	printf("%c",a[i]);
    }
    printf("\n");
    printf("Enter the prefix to be evaluated\n");
    len = getstr(s);
    i=len-1;
    while(i>=0){
        if(s[i]<='9' && s[i]>='0'){
            pushi(evalstack,&evaltop,s[i]-'0');
        }
        else{
            int a,b,result;
            a=popi(evalstack,&evaltop);
            b=popi(evalstack,&evaltop);
            switch(s[i]){
                case '+':
                    pushi(evalstack,&evaltop,b+a);
                    break;
                case '-':
		    pushi(evalstack,&evaltop,a-b);
		    break;
		case '*':
		    pushi(evalstack,&evaltop,b*a);
		    break;
		case '/':
		    pushi(evalstack,&evaltop,a/b);
		    break;
		case '%':
		    pushi(evalstack,&evaltop,a%b);
		    break;
		case '^':
		    pushi(evalstack,&evaltop,(int)pow(a,b));
		    break;
	    }
	}
        i--;
    }
    printf("The answer is:\t%d\n",popi(evalstack,&evaltop));
    getch();
    return 0;
}

