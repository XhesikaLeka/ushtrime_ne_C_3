//nje vlere x dhe kthen sa here gjendet vlera x ne peme.
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct peme{
	int vlere; 
	struct peme *majte;
	struct peme *djathte;
} peme;


peme * krijoElement(int vlere)
{
	peme * p=(peme *)malloc(sizeof(peme));
	p->vlere=vlere;
	p->djathte=NULL;
	p->majte=NULL;
    return p;
}

peme * Krijo_peme(int n)
{
	peme *kulmi;
	int x,m,d;
	if(n==0)
	return NULL;
	m=n/2;
	d=n-m-1;
	scanf("%d",&x);
	kulmi=krijoElement(x);
	kulmi->majte=Krijo_peme(m);
	kulmi->djathte=Krijo_peme(d);
	return kulmi;
}

void afisho(peme * Q)
{
	if(Q!=NULL)
	{
		printf("%d ",Q->vlere);
		afisho(Q->majte);
		afisho(Q->djathte);
	}
}
int nr(peme *Q,int x)
{if(Q==NULL)
return 0;
else if (Q->vlere==x)
return 1+nr(Q->majte,x)+nr(Q->djathte,x);
else
return nr(Q->majte,x)+nr(Q->djathte,x);
}

int main()
{
	int n,x;
		printf ("jep numrin\n");
	scanf ("%d",&x);
	printf("Jep nr e elementeve te pemes:\n");
	scanf("%d",&n);
	printf("Nderto pemen:\n");
	peme * Q=Krijo_peme(n);
	int a=nr(Q,x);
	printf("%d",a);
	getch(); 
	return 0;
}
