//shton vleren 0 si pasardhes te nyjeve qe kane vetem nje pasardhes.
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
//shton vleren 0 si pasardhes te nyjeve qe kane vetem nje pasardhes.
peme *shto(peme *Q)
{	peme *k=(peme *)malloc(sizeof(peme));
	k->vlere=0;
	k->djathte=NULL;
	k->majte=NULL;
if(Q==NULL)
{return NULL;
}
else if (Q->majte==NULL&&Q->djathte!=NULL)
{Q->majte=k;
}
else if (Q->majte!=NULL&&Q->djathte==NULL)
{Q->djathte=k;
}
Q->majte=shto(Q->majte);
Q->djathte =shto(Q->djathte);
return Q;
}


int main()
{
	int n;
	printf("Jep nr e elementeve te pemes:\n");
	scanf("%d",&n);
	printf("Nderto pemen:\n");
	peme * Q=Krijo_peme(n);
	printf("Pema e dhene eshte: ");
	afisho(Q);
	shto(Q);
	printf("\nPema e re eshte: ");
	afisho(Q);
	getch(); 
	return 0;
}
