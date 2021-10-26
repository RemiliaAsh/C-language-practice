#include <stdio.h>

struct item
{
	char name[10];
	int quan;
	float cost;
};

int np=0,nd=0,nb=0,nf=0;
typedef struct item it;

int selection(int n);
void additem(it *p,it *d,it *b,it *f);
void editquantity(it *p,it *d,it *b,it *f);
void editcost(it *p,it *d,it *b,it *f);
void file(it *p,it *d,it *b,it *f);

void main()
{
	it p[100],d[100],b[100],f[100];
	int index=0;
	while(!index)
	{
		printf("What you want to do?\n1.Add an item to inventory\n2.Change the quantity of an item in inventory\n3.Change the cost of an item in inventory\n4.Output inventory to file\n5.Exit program\nSelection:");
		switch(selection(5))
		{
			case 1:additem(p,d,b,f);break;
			case 2:editquantity(p,d,b,f);break;
			case 3:editcost(p,d,b,f);break;
			case 4:file(p,d,b,f);break;
			case 5:index++;break;
		}
	}
	puts("\n");
}

int selection(int n)
{
	int index=-1;
	while(index==-1)
	{
		scanf("%d",&index);
		if(!(index>0&&index<=n))
		{
			printf("try again!\n");
			index=-1;
		}
	}
	return index;
}
void additem(it *p,it *d,it *b,it *f)
{
	printf("What type you want to add?\n1.Produce\n2.Deli\n3.Bakery\n4.Frozen food\n5.Quit\nSelection:");
	switch(selection(5))
	{
		case 1:printf("name:");scanf("%s",p[np].name);printf("quantity:");scanf("%d",&p[np].quan);printf("cost:");scanf("%f",&p[np].cost);np++;break;
		case 2:printf("name:");scanf("%s",d[nd].name);printf("quantity:");scanf("%d",&d[nd].quan);printf("cost:");scanf("%f",&d[nd].cost);nd++;break;
		case 3:printf("name:");scanf("%s",b[nb].name);printf("quantity:");scanf("%d",&b[nb].quan);printf("cost:");scanf("%f",&b[nb].cost);nb++;break;
		case 4:printf("name:");scanf("%s",f[nf].name);printf("quantity:");scanf("%d",&f[nf].quan);printf("cost:");scanf("%f",&f[nf].cost);nf++;break;
		case 5:break;
	}
}
void editquantity(it *p,it *d,it *b,it *f)
{
	int s;
	printf("What type of quantity you want to edit?\n1.Produce\n2.Deli\n3.Bakery\n4.Frozen food\n5.Quit\n");
	switch(selection(5))
	{
		case 1:
			printf("Item list:\n");
			for (int i=0;i<np;i++)
			{
				printf("%d.%s\n",i+1,p[i].name);
			}
			printf("Changing Item:");
			s=selection(np);
			printf("quantity:");
			scanf("%d",&p[s-1].quan);
			break;
		case 2:
			printf("Item list:\n");
			for (int i=0;i<nd;i++)
			{
				printf("%d.%s\n",i+1,d[i].name);
			}
			printf("Changing Item:");
			s=selection(nd);
			printf("quantity:");
			scanf("%d",&d[s-1].quan);
			break;
		case 3:
			printf("Item list:\n");
			for (int i=0;i<nb;i++)
			{
				printf("%d.%s\n",i+1,b[i].name);
			}
			printf("Changing Item:");
			s=selection(nb);
			printf("quantity:");
			scanf("%d",&b[s-1].quan);
			break;
		case 4:
			printf("Item list:\n");
			for (int i=0;i<nf;i++)
			{
				printf("%d.%s\n",i+1,f[i].name);
			}
			printf("Changing Item:");
			s=selection(nf);
			printf("quantity:");
			scanf("%d",&f[s-1].quan);
			break;
		case 5:break;
	}
}
void editcost(it *p,it *d,it *b,it *f)
{
	int s;
	printf("What type of cost you want to edit?\n1.Produce\n2.Deli\n3.Bakery\n4.Frozen food\n5.Quit\n");
	switch(selection(5))
	{
		case 1:
			printf("Item list:\n");
			for (int i=0;i<np;i++)
			{
				printf("%d.%s\n",i+1,p[i].name);
			}
			printf("Changing Item:");
			s=selection(np);
			printf("cost:");
			scanf("%f",&p[s-1].cost);
			break;
		case 2:
			printf("Item list:\n");
			for (int i=0;i<nd;i++)
			{
				printf("%d.%s\n",i+1,d[i].name);
			}
			printf("Changing Item:");
			s=selection(nd);
			printf("cost:");
			scanf("%f",&d[s-1].cost);
			break;
		case 3:
			printf("Item list:\n");
			for (int i=0;i<nb;i++)
			{
				printf("%d.%s\n",i+1,b[i].name);
			}
			printf("Changing Item:");
			s=selection(nb);
			printf("cost:");
			scanf("%f",&b[s-1].cost);
			break;
		case 4:
			printf("Item list:\n");
			for (int i=0;i<nf;i++)
			{
				printf("%d.%s\n",i+1,f[i].name);
			}
			printf("Changing Item:");
			s=selection(nf);
			printf("cost:");
			scanf("%f",&f[s-1].cost);
			break;
		case 5:break;
	}
}
void file(it *p,it *d,it *b,it *f)
{
	FILE *cfptr;
	cfptr=fopen("items.txt","w");
	fprintf(cfptr,"Produce Inventory\nname       quantity   cost\n");
	for(int i=0;i<np;i++)
	{
		fprintf(cfptr,"%-10s %-10d %f\n",p[i].name,p[i].quan,p[i].cost);
	}
	fprintf(cfptr,"\n\nDeli Inventory\nname       quantity   cost\n");
	for(int i=0;i<nd;i++)
	{
		fprintf(cfptr,"%-10s %-10d %f\n",d[i].name,d[i].quan,d[i].cost);
	}
	fprintf(cfptr,"\n\nBakery Inventory\nname       quantity   cost\n");
	for(int i=0;i<nb;i++)
	{
		fprintf(cfptr,"%-10s %-10d %f\n",b[i].name,b[i].quan,b[i].cost);
	}
	fprintf(cfptr,"\n\nFrozen Food Inventory\nname       quantity   cost\n");
	for(int i=0;i<nf;i++)
	{
		fprintf(cfptr,"%-10s %-10d %f\n",f[i].name,f[i].quan,f[i].cost);
	}
	fclose(cfptr);
	printf("File created!\n");
}