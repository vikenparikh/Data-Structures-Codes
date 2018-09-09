            /* Viken Parikh
            SE Comps B2 1411099
            Binary Search Tree */


#include<stdio.h>
#include<conio.h>

struct node
{
	struct node *left;
	int val;
	struct node *right;
};

struct node *tree=NULL;

struct node *insert(struct node *, int);
void preorder(struct node *);
void inorder(struct node *);
void postorder(struct node *);
void del(struct node *,int);
struct node *largest(struct node *);

void main()
{
struct node *temp;
int v, option;
clrscr();
do{

printf("1.Insert 2.Preorder 3.Inorder 4.Postorder");
printf("\nEnter your choice");
scanf("%d",&option);
switch(option)
{
	case 1:printf("Enter the element to be added \t");
		scanf("%d",&v);
		tree=insert(tree,v);
		break;
	case 2:printf("The preorder is:\n");
		preorder(tree);
		break;
	case 3:printf("The inorder is:\n");
		inorder(tree);
		break;
	case 4:printf("The postorder is:\n");
		postorder(tree);
		break;
	case 5:printf("Enter the value to be deleted");
		scanf("%d",&v);
		del(tree,v);
		break;
	case 6:temp=largest(tree);
		printf("%d",temp->val);
		break;
}
}while(option!=0);
}

struct node *insert(struct node *tree, int v)
{
struct node *ptr, *preptr, *newnode;
newnode=(struct node *)malloc(sizeof(struct node));
newnode->left=NULL;
newnode->right=NULL;
newnode->val=v;
if(tree==NULL)
{
tree=newnode;
}
else
{
	ptr=tree;
	preptr=NULL;
	while(ptr!=NULL)
	{
		preptr=ptr;
		if(ptr->val<v)
		ptr=ptr->right;
		else
		ptr=ptr->left;
	}
	if(preptr->val>v)
	preptr->left=newnode;
	else
	preptr->right=newnode;
}
return tree;
}

void preorder(struct node *tree)
{
	if(tree!=NULL)
	{
		printf("%d\t",tree->val);
		preorder(tree->left);
		preorder(tree->right);
	}
}

void inorder(struct node *tree)
{
	if(tree!=NULL)
	{
		inorder(tree->left);
		printf("%d\t",tree->val);
		inorder(tree->right);
	}

}
void postorder(struct node *tree)
{
	if(tree!=NULL)
	{
		postorder(tree->left);
		postorder(tree->right);
		printf("%d",tree->val);
	}

}

void del(struct node *tree,int v)
{
	struct node *ptr, *preptr, *temp, *ah;
	ptr=tree;
	if(ptr==NULL)
	printf("Empty");
	else{
		while(ptr->val!=v&&ptr!=NULL)
		{
		preptr=ptr;
		if(ptr->val>v)
		ptr=ptr->left;
		else
		ptr=ptr->right;
		}
		if(ptr==NULL)
		printf("Element not found");
		else
		{
			if(ptr->left!=NULL && ptr->right!=NULL)
			{
			temp=largest(ptr->left);
			ah=temp->right;
			ptr->val=ah->val;
			temp->right=NULL;
			free(ah);
			}
			else
			{     	if(ptr->left==NULL && ptr->right==NULL)
				{
				if(ptr->val>preptr->val)
				preptr->right=NULL;
				else preptr->left=NULL;
				free(ptr);
				}
				else
				{
					if(ptr->left==NULL)
					{
					preptr->right=ptr->right;
					free(ptr);
					}
					else
					{
					preptr->left=ptr->left;
					free(ptr);
					}
				}
			}
		}
	}
}

struct node *largest(struct node *tree)
{
struct node *pre,*ptr;
ptr=tree;
while(ptr->right!=NULL)
{
pre=ptr;
ptr=ptr->right;
}
printf("%d %d",pre->val,ptr->val );
return pre;
}
