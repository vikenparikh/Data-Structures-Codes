            /* Viken Parikh
            SE Comps B2 1411099
              hash function*/


#include<stdio.h>
#include<conio.h>
#include<math.h>
int hashfunc(int k, int m);
void linearhash(int k, int mo, int i, int arr[]);
void quadhash(int k, int mo, int i, int c1,int c2, int arr[]);
void printmap(int arr[], int m);
int main()
{
    int m=20,arr[20];
    int ch,i,ch2,k,c1,c2;
    clrscr();
    printf("Enter the choice:\n1.Linear Probing\n2.Quadratic Probing\n3.Exit\n");
    scanf("%d",&ch);
    while(ch!=3){
        switch(ch)
        {
        case 1:
            for(i=0;i<m;i++){
                arr[i]=-1;
            }
            printf("Enter option:\n1.Hash Number\n2.Print HashTable\n3.Exit");
            scanf("%d",&ch2);
            while(ch2!=3){
                switch(ch2)
                {
                case 1:
                    printf("Enter the number to be added\n");
                    scanf("%d",&k);
                    linearhash(k,m,0,arr);
                    break;
                case 2:
                    printmap(arr,m);
                    break;
                default:
                    printf("Incorrect Option\n");
                    break;
                }
                printf("\nEnter option:\n1.Hash Number\n2.Print HashTable\n3.Exit");
                scanf("%d",&ch2);
            }
            break;
        case 2:
            for(i=0;i<m;i++){
                arr[i]=-1;
            }
            printf("Enter the constants for the Quadratic Hash:\n");
            printf("c1:\t");
            scanf("%d",&c1);
            printf("c2:\t");
            scanf("%d",&c2);
            printf("Enter option:\n1.Hash Number\n2.Print HashTable\n3.Exit");
            scanf("%d",&ch2);
            while(ch2!=3){
                switch(ch2)
                {
                case 1:
                    printf("Enter the number to be added\n");
                    scanf("%d",&k);
                    quadhash(k,m,0,c1,c2,arr);
                    break;
                case 2:
                    printmap(arr,m);
                    break;
                default:
                    printf("Incorrect Option\n");
                    break;
                }
                printf("\nEnter option:\n1.Hash Number\n2.Print HashTable\n3.Exit");
                scanf("%d",&ch2);
            }
            break;
        default:
            printf("Incorrect Option\n");
        }
        printf("Enter the choice:\n1.Linear Probing\n2.Quadratic Probing\n3.Exit\n");
        scanf("%d",&ch);
    }
    getch();
    return 0;
}

int hashfunc(int k, int m)
{
    return k%m;
}

void linearhash(int k, int m, int i, int arr[])
{
    int j;
    if(i==20){
        printf("The hash table is full\n");
        return;
    }
    j=(hashfunc(k,m)+i)%m;
    if(arr[j]==-1){
        arr[j]=k;
    }
    else{
        linearhash(k,m,i+1,arr);
    }
}

void quadhash(int k, int m, int i, int c1,int c2,int arr[])
{
    int j;
    if(i==20){
        printf("Hash Table is full");
        return;
    }
    j=(hashfunc(k,m)+c1*i+c2*i*i)%m;
    if(arr[j]==-1){
        arr[j]=k;
    }
    else{
        quadhash(k,m,i+1,c1,c2,arr);
    }
}

void printmap(int arr[], int m)
{
    int i;
    printf("Index Key\n");
    for(i=0;i<m;i++){
        if(arr[i]!=-1){
            printf("%4d %4d\n",i,arr[i]);
        }
    }
}
