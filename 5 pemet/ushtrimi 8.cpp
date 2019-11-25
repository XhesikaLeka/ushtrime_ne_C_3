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
/*kthen true nese numri i nyjeve te nenpemes se majte eshte i barabarte me numrin e nyjeve te nenpemes se djathe*/
int nrgjethe(peme * Q,int niveli)
{
	if(Q==NULL)
	return 0;
	if(Q->majte==NULL&&Q->djathte==NULL)
	return 1;
	int a=nrgjethe(Q->majte,niveli+1);
	int b=nrgjethe(Q->djathte,niveli+1);
	if(niveli==1)
	{
		if(a==b)
		return 1;
		else
		return 0;
	}
	return a+b;
}


int main()
{
	int n;
	printf("Jep nr e elementeve te pemes:\n");
	scanf("%d",&n);
	printf("Nderto pemen:\n");
	peme * Q=Krijo_peme(n);
	printf("Pema e dhene eshte\: ");
	afisho(Q);
	int niveli=1;
if(nrgjethe(Q,niveli)==1)
printf("PO");
else printf("JO");
	getch(); 
	return 0;
}
