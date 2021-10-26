#include <stdio.h>
void load(int array[],int x,int y)
{
	for(int i=0;i<x*y;i++)
	{
		printf("Enter the value for location %d x %d\n",(i/y)+1,(i%y)+1);
		scanf("%d",&array[i]);
	}
}
void sb(int A[],int B[],int x,int y)
{
	for(int i=0;i<x*y;i++)
	{
		printf("%d ",A[i]-B[i]);
		if((i+1)%y==0) printf("\n");
	}
}
void pm(int array[],int x,int y)
{
	for(int i=0;i<x*y;i++)
	{
		printf("%d ",array[i]);
		if((i+1)%y==0) printf("\n");
	}
}
void tran(int array[],int x,int y)
{
	for(int i=0;i<y;i++)
	{
		for(int j=0;j<x;j++)
		{
			printf("%d ",array[y*j+i]);
		}
		printf("\n");
	}
}
void rank(int array[])
{
	if(array[0]==0&&array[1]==0&&array[2]==0&&array[3]==0) printf("the rank is 0\n");
	else if(array[0]*array[3]==array[1]*array[2]) printf("the rank is 1\n");
	else printf("the rank is 2\n");
}
void main(void)
{
	int Ax,Ay,Bx,By,choice;
	printf("Enter the rows you want in A\n");
	scanf("%d",&Ax);
	printf("Enter the columns you want in A\n");
	scanf("%d",&Ay);
	printf("Enter the rows you want in B\n");
	scanf("%d",&Bx);
	printf("Enter the columns you want in B\n");
	scanf("%d",&By);
	choice=1;
	int A[Ax*Ay],B[Bx*By];
	printf("Initializing matrix A\n");
	load(A,Ax,Ay);
	printf("Initializing matrix B\n");
	load(B,Bx,By);
	do
	{
		printf("1. Load Values in the Matrix (A or B)\n2. Subtract matrices (A-B or B-A)\n3. Print matrix (A or B)\n4. Transpose matrix (A or B)\n5. Rank of matrix (A or B)\n6. Exit\nOption: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: 
				printf("Type 1 to load A, anynumber else for B.\n");
				scanf("%d",&choice);
				if(choice==1) load(A,Ax,Ay);
				else load(B,Bx,By);
				break;
			case 2:
				if(Ax!=Bx||Ay!=By) printf("The dimention of A and B is Different\n");
				else
				{
					printf("Type 1 to get A-B, anynumber else for B-A.\n");
					scanf("%d",&choice);
					if(choice==1) sb(A,B,Ax,Ay);
					else sb(B,A,Bx,By);
				}
				break;
			case 3:
				printf("Type 1 to print A, 2 for B.\n");
				scanf("%d",&choice);
				if(choice==1) pm(A,Ax,Ay);
				else if (choice==2) pm(B,Bx,By);
				else printf("only number 1 or 2 is accepted\n");
				break;
			case 4:
				printf("Type 1 to print transpose of A, anynumber else for B.\n");
				scanf("%d",&choice);
				if(choice==1) tran(A,Ax,Ay);
				else tran(B,Bx,By);
				break;
			case 5:
				printf("Type 1 to print rank of A, anynumber else for B.\n");
				scanf("%d",&choice);
				if(choice==1)
				{
					if(Ax==2&&Ay==2) rank(A);
					else printf("A is not a 2x2 matrix\n");
				}
				else if(Bx==2&&By==2) rank(B);
				else printf("B is not a 2x2 matrix\n");
				break;
			default:break;
		}
	}while(choice!=6);
}
