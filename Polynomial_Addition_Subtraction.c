            /* Viken Parikh
          SE Comps B2 1411099
        Addition and Subtraction 
            of polynomials */

#include<stdio.h>
#include<conio.h>

struct node
{
	int coef,power;
	struct node *next;
};

struct node *start1=NULL;
struct node *start2=NULL;
struct node *start3=NULL;
struct node *create(struct node *);
struct node *display(struct node *);
struct node *add(struct node*, struct node *, struct node *);
struct node *addnode(struct node *,int,int);
struct node *sub(struct node*, struct node *, struct node *);

struct node *create(struct node *start)
{
	struct node *ptr, *pre;
	int i,j;
	printf("Enter the coefficient and the power");
	scanf("%d",&i);
	scanf("%d",&j);
	while(i!=-1)
	{
		if(start==NULL)
		{
			ptr=(struct node *)malloc(sizeof(struct node));
			ptr->coef=i;
			ptr->power=j;
			ptr->next=NULL;
			start=ptr;
		}
		else
		{
			pre=start;
			while(pre->next!=NULL)
			pre=pre->next;
			ptr=(struct node *)malloc(sizeof(struct node *));
			ptr->coef=i;
			ptr->power=j;
			pre->next=ptr;
			ptr->next=NULL;
		}
		printf("Enter the coefficient and the power  :  ");
		scanf("%d",&i);
		scanf("%d",&j);
	}
return start;
}

struct node *display(struct node *start)
{
	struct node *ptr;
	ptr=start;
	while(ptr!=NULL)
	{
		printf("%d x^%d  +  ",ptr->coef,ptr->power);
		ptr=ptr->next;
	}
return start;
}

struct node *add(struct node *start1, struct node *start2, struct node *start3)
{
	struct node *ptr1,*ptr2;
	int add;
	ptr1=start1;
	ptr2=start2;
	while(ptr1!=NULL && ptr2!=NULL)
	{
		if(ptr1->power==ptr2->power)
		{
			add=ptr1->coef+ptr2->coef;
			start3=addnode(start3,add,ptr1->power);
			ptr1=ptr1->next;
			ptr2=ptr2->next;
		}
		else{
			 if(ptr1->power>ptr2->power)
			 {
			 start3=addnode(start3,ptr1->coef,ptr1->power);
			 ptr1=ptr1->next;
			 }
			 else {
				if(ptr1->power<ptr2->power)
				{
				start3=addnode(start3,ptr2->coef,ptr2->coef);
				ptr2=ptr2->next;
				}
		 	}
		}
	}
if(ptr2==NULL)
{
	while(ptr1!=NULL)
	{
		start3=addnode(start3,ptr1->coef,ptr1->power);
		ptr1=ptr1->next;
	}
}
if(ptr1==NULL)
{
	while(ptr2!=NULL)
		{
		start3=addnode(start3,ptr2->coef,ptr2->power);
		ptr2=ptr2->next;
	}
}
return start3;
}


struct node *sub(struct node *start1, struct node *start2, struct node *start3)
{
	struct node *ptr1,*ptr2;
	int sub;
	ptr1=start1;
	ptr2=start2;
	while(ptr1!=NULL && ptr2!=NULL)
	{
		if(ptr1->power==ptr2->power)
		{
			sub=ptr1->coef-ptr2->coef;
			start3=addnode(start3,sub,ptr1->power);
			ptr1=ptr1->next;
			ptr2=ptr2->next;
		}
		else{
			 if(ptr1->power>ptr2->power)
			 {
				 start3=addnode(start3,ptr1->coef,ptr1->power);
				 ptr1=ptr1->next;
			 }
			 else {
				if(ptr1->power<ptr2->power)
				{
				start3=addnode(start3,ptr2->coef,ptr2->coef);
				ptr2=ptr2->next;
				}
		 	}
		}
	}
if(ptr2==NULL)
{
	while(ptr1!=NULL)
	{
		start3=addnode(start3,ptr1->coef,ptr1->power);
		ptr1=ptr1->next;
	}
}

if(ptr1==NULL)
{
	while(ptr2!=NULL)
	{
		start3=addnode(start3,ptr2->coef,ptr2->power);
		ptr2=ptr2->next;
	}
}
return start3;
}


struct node *addnode(struct node *start,int a, int b)
{
	struct node *ptr,*pre;
	if(start==NULL)
	{       ptr=(struct node *)malloc(sizeof(struct node *));
		ptr->coef=a;
		ptr->power=b;
		ptr->next=NULL;
		start=ptr;
	}
	else
	{       pre=start;
		while(pre->next!=NULL)
		pre=pre->next;
		ptr=(struct node *)malloc(sizeof(struct node *));
		ptr->coef=a;
		ptr->power=b;
		pre->next=ptr;
		ptr->next=NULL;
	}
return start;
}
void main()
{
	int c;
	clrscr();
	do
	{
		printf("Enter the choice 1.Create1 2.Create2 3.Display1 4.Display2 5.Add 6.Display add 7. Subtracr 8.Display sub");
		scanf("%d",&c);
		switch(c)
		{
			case 1:start1=create(start1);
				break;
			case 2:start2=create(start2);
				break;
			case 3:start1=display(start1);
				break;
			case 4:start2=display(start2);
				break;
			case 5:start3=add(start1,start2,start3);
				break;
			case 6:start3=display(start3);
				break;
			case 7:start3=sub(start1,start2,start3);
				break;
			case 8:start3=display(start3);
				break;
		}
	}while(c<8);
getch();
}




/*
OUTPUT:
Enter the choice 1.Create1 2.Create2 3.Display1 4.Display2 5.Add 6.Display add 7. Subtracr 8.Display sub
1
Enter the coefficient and the power1 5
Enter the coefficient and the power  :  2 4
Enter the coefficient and the power  :  3 3
Enter the coefficient and the power  :  4 2
Enter the coefficient and the power  :  5 1
Enter the coefficient and the power  :  -1 1
Enter the choice 1.Create1 2.Create2 3.Display1 4.Display2 5.Add 6.Display add 7. Subtracr 8.Display sub
3
1 x^5  +  2 x^4  +  3 x^3  +  4 x^2  +  5 x^1  +
Enter the choice 1.Create1 2.Create2 3.Display1 4.Display2 5.Add 6.Display add 7. Subtracr 8.Display sub
2
Enter the coefficient and the power1 5
Enter the coefficient and the power  :  2 4
Enter the coefficient and the power  :  3 3
Enter the coefficient and the power  :  4 2
Enter the coefficient and the power  :  5 1
Enter the coefficient and the power  :  -1 1
Enter the choice 1.Create1 2.Create2 3.Display1 4.Display2 5.Add 6.Display add 7. Subtracr 8.Display sub
4
1 x^5  +  2 x^4  +  3 x^3  +  4 x^2  +  5 x^1  
Enter the choice 1.Create1 2.Create2 3.Display1 4.Display2 5.Add 6.Display add 7. Subtracr 8.Display sub
5
Enter the choice 1.Create1 2.Create2 3.Display1 4.Display2 5.Add 6.Display add 7. Subtracr 8.Display sub
6
2 x^5  +  4 x^4  +  6 x^3  +  8 x^2  +  10 x^1  
Enter the choice 1.Create1 2.Create2 3.Display1 4.Display2 5.Add 6.Display add 7. Subtracr 8.Display sub
7
Enter the choice 1.Create1 2.Create2 3.Display1 4.Display2 5.Add 6.Display add 7. Subtracr 8.Display sub
8
0 x^5  +  0 x^4  +  0 x^3  +  0 x^2  +  0 x^1  
*/








