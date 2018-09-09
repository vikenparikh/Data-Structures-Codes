            /* Viken Parikh
            SE Comps B2 1411099
           Linked list program*/

#include<stdio.h>
#include<conio.h>
typedef struct nde
{
  int val;
  struct nde *nxt;
}node;
node *start=NULL;
node *str2 = NULL;
node *create(node *start);
node *display(node *start);
node *concat(node *str1,node *str2);
int count(node *start);
node *reverse(node *start);

node *create(node *start)
{
  node *newnode;
  int a;
  newnode=(node *)malloc(sizeof(node));
  if(start==NULL){
    start=newnode;
	newnode->nxt=NULL;
  }
  else{
    node *temp = start;
	start=newnode;
	newnode->nxt=temp;
  }
  printf("Enter data :\n");
  scanf("%d",&a);
  newnode->val=a;
  return start;
}

node *display(node *start)
{
  node *ptr=start;
  if(start==NULL){
    printf("The linked list is empty.\n");
    return start;
  }
  while(ptr->nxt!=NULL){
    printf("%d ",ptr->val);
	ptr=ptr->nxt;
  }
  printf("%d\n",ptr->val);
  return start;
}
node *concat(node *str1,node *str2)
{
  node *ptr =str1;
  while(ptr->nxt!=NULL){
    ptr=ptr->nxt;
  }
  ptr->nxt=str2;
  return  NULL;
}
int count(node *start)
{
  int c=0;
  node *ptr=start;
  while(ptr!=NULL)
 {
  c++;
  ptr=ptr->nxt;
  }
  return c;
}
node *reverse(node *start)
{
  node *ptr,*ptr1,*ptr2=NULL;
  ptr=start;
  while(ptr->nxt!=NULL){
    ptr1=ptr->nxt;
	ptr->nxt=ptr2;
	ptr2=ptr;
	ptr=ptr1;
  }
  ptr->next=ptr2;
  return ptr;
}
int main()
{
  //node *rev;
  int c;
  int flag=1;
  clrscr();
  while(flag)
  {
  printf("1.createll1\n2.createll2\n3.countll1\n4.countll2\n5.concat12\n6.concat21\n7.reverse1\n8.reverse2\n9.display1\n10.display2\n11.exit\n");
  scanf("%d",&c);
  switch(c)
  {
      case 1:
          start=create(start);
          break;
      case 2:
          str2=create(str2);
          break;
      case 3:
          printf("Count of ll1 is %d\n",count(start));
          break;
      case 4:
          printf("Count of ll4 is %d\n",count(str2));
          break;
      case 5:
          start=concat(start,str2);
          break;
      case 6:
          str2=concat(str2,start);
          break;
      case 7:
          start=reverse(start);
          break;
      case 8:
          str2=reverse(str2);
          break;
      case 9:
          start = display(start);
          break;
      case 10:
          str2=display(str2);
          break;
      case 11:
          flag=0;
          break;
  };
  }
  }
  getch();
  return 0;
}

