        /* Viken Parikh
        SE Comps B2 1411099
         Expression Tree  */

#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAX 20
int stack[MAX],top=-1;

struct node
{
    char data;
    struct node *left, *right;
};

void push(struct node*add)
{
if(top==MAX-1)
printf("Stack is full");
else
stack[++top]=add;
}

struct node *pop()
{
struct node *p;
if(top==-1)
printf("Stack is empty");
else
{
p= stack[top];
top--;
}
return p;
}

struct node *create(char post[])
{   struct node *temp,*root;
    int i;
  int n=strlen(post);
  for(i=0;i<n;i++)
  {
      switch(post[i])
      {
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
            temp=(struct node*)malloc(sizeof(struct node));
            temp->data=post[i];
            temp->left=pop();
            temp->right=pop();
            push(temp);
            break;
            default :
            temp=(struct node*)malloc(sizeof(struct node));
            temp->data=post[i];
            temp->right=NULL;
            temp->left=NULL;
            push(temp);

      }
  }
  root=pop();
  return root;
}

void inorder(struct node *tree)
{
	if(tree!=NULL)
	{
		inorder(tree->right);
		printf("%c\t",tree->data);
		inorder(tree->left);
	}

}

int eval(struct node *root)
{
    struct node *ptr;
    int ans;
    ptr=root;
    while(ptr!=NULL)
    {
        switch(ptr->data)
        {

            case '+':ans=eval(ptr->left)+eval(ptr->right);
                    break;
            case '-':ans=eval(ptr->left)-eval(ptr->right);
                    break;
            case '*':ans=eval(ptr->left)*eval(ptr->right);
                    break;
            case '/':ans=eval(ptr->left)/eval(ptr->right);
                    break;
            default:ans=ptr->data-'0';
                    break;
        }
        return ans;
    }
return ans;
}

void main()
{
    struct node *root;
    int i,ans=0;
    char post[20];
    clrscr();
    printf("Enter the postfix expression");
    scanf("%s",post);
    root=create(post);
    printf("inorder");
    inorder(root);
    getch();
}
