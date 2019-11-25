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
//nr i nyjeve	
int nr(peme *Q)
{if(Q==NULL)
return 0;
else
if (Q->majte==NULL&&Q->djathte==NULL)
return nr(Q->majte)+nr(Q->djathte);
else
return 1+nr(Q->majte)+nr(Q->djathte);
}


int main()
{
	int n,c=0;
	printf("Jep nr e elementeve te pemes:\n");
	scanf("%d",&n);
	printf("Nderto pemen:\n");
	peme * Q=Krijo_peme(n);
	printf("Pema e dhene eshte: ");
	afisho(Q);
	printf("nr i nyjeve eshte %d",nr(Q));
	getch(); 
	return 0;
}
