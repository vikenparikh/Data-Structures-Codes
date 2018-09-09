/* VIKEN PARIKH
   SE B2 1411099*/ 
   
/* Q17- Write a program to read a file 
   (containing may be your friends contact numbers or favorite songs) 
   and  builds a list.  
   After the list is created, 
   the program should  present the user with menu to 
   insert new data, remove existing data, 
   or print  the entire list.*/ 



#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<malloc.h>
#define MAX 20
struct node
{
 char name[MAX];
 long phone;
 char song[MAX];
 struct node *next;
};

struct node *start=NULL;
struct node *create(struct node *);
struct node *display(struct node *);
struct node *insert(struct node *);
struct node *deletef(struct node *);

void main()
  {
    int opt;
    clrscr();
    start=create(start);
     do
     {
      printf("\n!!----------Main Menu----------!!");
      printf("\n1: Insert New Friend's Data In The Friend List.");
      printf("\n2: Remove A Friend's Data From The Friend List.");
      printf("\n3: Display The Entire Friend List.");
      printf("\n4: Exit.");
      printf("\n Enter your choice: ");
      scanf("%d",&opt);
        switch(opt)
         {
          case 1:
            start=insert(start);
            break;
          case 2:
            start=deletef(start);
            break;
          case 3:
            start=display(start);
            break;
          case 4:
            break;
            default:
            printf("\nChoose a valid option!");
            break;
          }
      }while(opt!=4);
   getch();
}

struct node *create(struct node *start)
{
 struct node *newnode,*ptr;
 int i;
 char name1[MAX],song1[MAX];
 long phone1;
 i=1;
 printf("\nEnter The Data:");
 while(i==1)
   {
    printf("\nFriend's Name: ");
    scanf("%s",&name1);
    printf("\nFriend's Phone Number: ");
    scanf("%ld",&phone1);
    printf("\nFriend's Favourite Song: ");
    scanf("%s",&song1);
    newnode=(struct node *)malloc(sizeof(struct node));
    strcpy(newnode->name,name1);
    newnode->phone=phone1;
    strcpy(newnode->song,song1);
    if(start==NULL)
      {
       newnode->next=NULL;
       start=newnode;
      }
    else
      {
       ptr=start;
         while(ptr->next!=NULL)
               ptr=ptr->next;
               newnode->next=NULL;
               ptr->next=newnode;
       }
    printf("\nEnter 1 to continue entering more friends: ");
    scanf("%d",&i);
    }
 return start;
}

struct node *insert(struct node *start)
{
 struct node *newnode,*ptr;
 char name1[MAX],song1[MAX];
 long phone1;
 printf("\nEnter The Data:");
 printf("\nFriend's Name: ");
 scanf("%s",&name1);
 printf("\nFriend's Phone Number: ");
 scanf("%ld",&phone1);
 printf("\nFriend's Favourite Song: ");
 scanf("%s",&song1);
 newnode=(struct node *)malloc(sizeof(struct node));
 strcpy(newnode->name,name1);
 newnode->phone=phone1;
 strcpy(newnode->song,song1);
 newnode->next=NULL;
 ptr=start;
 while(ptr->next!=NULL)
      ptr=ptr->next;
 ptr->next=newnode;
 return start;
}

struct node *deletef(struct node *start)
{
 struct node *ptr,*preptr;
 char name1[MAX];
 int i;
 printf("\nEnter the name of the friend that you want to delete: ");
 scanf("%s",&name1);
 ptr=start;
 i=strcmp(ptr->name,name1);

 if(i==0)
   {
    start=start->next;
    free(ptr);
    return start;
   }
 else
   {
    while(i!=0)
       {
       preptr=ptr;
       ptr=ptr->next;
       i=strcmp(ptr->name,name1);
       }
    preptr->next=ptr->next;
    free(ptr);
    return start;
    }
}

struct node *display(struct node *start)
{
 struct node *ptr;
 ptr=start;
 while(ptr!=NULL)
     {
      printf("\n%s\t%ld\t%s",ptr->name,ptr->phone,ptr->song);
      ptr=ptr->next;
     }
 return start;
}
