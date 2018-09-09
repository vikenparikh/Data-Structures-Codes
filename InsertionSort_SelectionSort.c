            /* Viken Parikh
            SE Comps B2 1411099
               Sort program  */

#include<stdio.h>
#include<conio.h>

void insertionsort(int arr[], int length);
void selectionsort(int arr[], int length);
void display(int a[],int la);

void insertionsort(int a[], int length)
{
	int temp,i,j;
	for(i=1;i<length;i++){
		temp=a[i];
		j=i-1;
		while(a[j]>temp && j>=0){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
	}
}
void display(int a[], int la)
{
	int i;
	for(i=0;i<la;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}
void selectionsort(int a[], int length)
{
	int i, j, temp;
	for(i=0;i<length;i++){
		for(j=i+1;j<length;j++){
			if(a[j]<a[i]){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}
int main()
{
	int a[20];
	int ch,la,i;
	printf("Enter Option:\n1.Insertion Sort\n2.Selection Sort\n3.Exit\n");
	scanf("%d",&ch);
	while(ch!=3){
		switch(ch){
			case 1:
				printf("Enter the number of elements\n");
				scanf("%d",&la);
				printf("Enter %d numbers\n",la);
				for(i=0;i<la;i++){
					scanf("%d",&a[i]);
				}
				insertionsort(a,la);
				display(a,la);
				break;
			case 2:
				printf("Enter the number of elements\n");
				scanf("%d",&la);
				printf("Enter %d numbers\n",la);
				for(i=0;i<la;i++){
					scanf("%d",&a[i]);
				}
				selectionsort(a,la);
				display(a,la);
				break;
			default:
				printf("Incorrect Option\n");
				break;
			}
		printf("Enter Option:\n1.Insertion Sort\n2.Selection Sort\n3.Exit\n");
		scanf("%d",&ch);
	}
	getch();
	return 0;
}
