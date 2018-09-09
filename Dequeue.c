            /* Viken Parikh
            SE Comps B2 1411099
             dequeue program*/

#include<stdio.h>
#include<conio.h>
typedef struct dequeue
{
	int arr[10];
h	int front;
	int back;
}dequeue;

dequeue dq;
void initialize(dequeue *dq);
void queue_front(dequeue* dq);
void queue_back(dequeue* dq);
int dequeue_front(dequeue* dq);
int dequeue_back(dequeue* dq);
void display(dequeue *dq);
int main()
{
	dequeue dq;
	int c,temp, d;
	clrscr();
	initialize(&dq);
	printf("Enter:\n1. Input Restricted\n2.Output Restricted\n3.No Restriction");
	scanf("%d",&d);
	if(d==3){
		printf("Incorrect Option.\n1.Queue Element at Front\n2.Queue Element at Back\n3.Dequeue Element from Front\n4.Dequeue Element from Back\n5.Display\n6.Exit\n");
		scanf("%d",&c);
		while(c!=6){
			switch(c){
				case 1:
				queue_front(&dq);
				break;
				case 2:
				queue_back(&dq);
				break;
				case 3:
				temp=dequeue_front(&dq);
				if(temp!=-999){
					printf("The value dequeued is %d",temp);
				}
				break;
				case 4:
				temp=dequeue_back(&dq);
				if(temp!=-999){
					printf("The value dequeued is %d",temp);
				}
				break;
				case 6:
				display(&dq);
				break;
				default:
				printf("Incorrect Option.\n1.Queue Element at Front\n2.Queue Element at Back\n3.Dequeue Element from Front\n4.Dequeue Element from Back\n5.Display\n6.Exit\n");
				break;
			}
			//display(&dq);
			scanf("%d",&c);
		}
	}
	else if(d==1){
		printf("1.Queue Element at Back\n2.Dequeue Element from Front\n3.Dequeue Element from Back\n4.Display\n5.Exit\n");
		scanf("%d",&c);
		while(c!=5){
			switch(c){
				case 1:
				queue_back(&dq);
				break;
				case 2:
				temp=dequeue_front(&dq);
				if(temp!=-999){
					printf("The value dequeued is %d",temp);
				}
				break;
				case 3:
				temp=dequeue_back(&dq);
				if(temp!=-999){
					printf("The value dequeued is %d",temp);
				}
				break;
				case 4:
				display(&dq);
				break;
				default:
				printf("Incorrect Option.\n1.Queue Element at Front\n2.Queue Element at Back\n3.Dequeue Element from Front\n4.Dequeue Element from Back\n5.Exit\n");
				break;
			}
			//display(&dq);
			scanf("%d",&c);
		}
	}
	else if(d==2){
		printf("1.Queue Element at Back\n2.Queue Element to Back\n3.Dequeue Element from Front\n4.Display\n5.Exit\n");
		scanf("%d",&c);
		while(c!=5){
			switch(c){
				case 1:
				queue_front(&dq);
				break;
				case 2:
				queue_back(&dq);
				break;
				case 3:
				temp=dequeue_front(&dq);
				if(temp!=-999){
					printf("The value dequeued is %d",temp);
				}
				break;
				case 4:
				display(&dq);
				break;
				default:
				printf("Incorrect Option.\n1.Queue Element at Front\n2.Queue Element at Back\n3.Dequeue Element from Front\n4.Dequeue Element from Back\n5.Exit\n");
				break;
			}
			//display(&dq);
			scanf("%d",&c);
		}
	}
	getch();
	return 0;
}

void initialize(dequeue *dq){
	dq->front=-1;
	dq->back=-1;
}

void queue_back(dequeue *dq){
	int val;
	if((dq->front==0 && dq->back==9)||(dq->front==dq->back+1)){
		printf("Queue full\n");
	}
	else{
		printf("Enter the value to be queued\n");
		scanf("%d",&val);
		if((dq->back)<9){
			dq->back+=1;
			(dq->arr[dq->back])=val;
		}
		else{
			dq->back=0;
			(dq->arr)[dq->back]=val;
		}
		if(dq->front==-1){
			dq->front=dq->back;
		}
		printf("Element succesfully inserted\n");
	}
}

void queue_front(dequeue *dq){
	int val;
	if((dq->front==0 && dq->back==9)||(dq->front==dq->back+1 && dq->back!=-1)){
		printf("Queue full\n");
	}
	else{
		printf("Enter the value to be queued\n");
		scanf("%d",&val);
		if((dq->front)>0){
			dq->front-=1;
			(dq->arr)[dq->front]=val;
		}
		else{
			dq->front=9;
			(dq->arr)[dq->front]=val;
		}
		if(dq->back==-1){
			dq->back=dq->front;
		}
		printf("Element succesfully inserted\n");
	}
}

int dequeue_front(dequeue *dq){
	int val=-999;
	if((dq->front)==(dq->back)+1){
		printf("Queue Underflow\n");
	}
	else{
		int val = (dq->arr)[dq->front];
		(dq->arr)[dq->front]=-1;
		if((dq->front)<9){
			dq->front+=1;
		}
		else{
			dq->front=0;
		}
	}
	return val;
}

int dequeue_back(dequeue *dq){
	int val=-999;
	if((dq->front)==(dq->back)+1){
		printf("Queue Underflow\n");
	}
	else{
		int val = (dq->arr)[dq->back];
		(dq->arr)[dq->back]=-1;
		if((dq->back)>0){
			dq->back-=1;
		}
		else{
			dq->back=9;
		}
	}
	return val;
}


void display(dequeue *dq){
	int i;
	for(i=dq->front;;){
		if(i==dq->back){
			break;
		}
		else{
			printf("%d ",(dq->arr)[i]);
			if(i<9){
				i++;
			}
			else{
				i=0;
			}
		}
	}
	printf("%d\n",(dq->arr)[dq->back]);
}