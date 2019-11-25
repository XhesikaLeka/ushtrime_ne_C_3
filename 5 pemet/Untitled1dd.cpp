/*	Ky program krijon nje peme dhe e afishon ate. */
	 
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct nyje{
	int vlere;
	struct nyje *majte;
	struct nyje *djathte;
} nyje;

nyje *krijo_nyje(int vlere)
{
	nyje *n;
	n=(nyje*)malloc(sizeof(nyje));
	n->vlere=vlere;
	n->majte=NULL;
	n->djathte=NULL;
	return n;
}

nyje *krijo_peme(int n)
{
	if(n<=0)
	return NULL;
	nyje *p;
	int vl;
	scanf("%d",&vl);
	p=krijo_nyje(vl);
	int nrmajte=n/2;
	int nrdjathte=n-nrmajte-1;
	p->majte=krijo_peme(nrmajte);
	p->djathte=krijo_peme(nrdjathte);
	return p;
}

void afisho(nyje *p)
{
	if(p!=NULL)
	{
		printf("%d ",p->vlere);
		afisho(p->majte);
		afisho(p->djathte);
	}
}


int lartesia(nyje * p,int niveli,int nivelipare)
{
	if(p==NULL)
	return true;
	if(p->majte==NULL&&p->djathte==NULL)
	{
		if(nivelipare==0)
		{
			nivelipare=niveli;
			return true;
		}
		return (niveli==nivelipare);
	}
	return (lartesia(p->majte,niveli+1,nivelipare)&&lartesia(p->djathte,niveli+1,nivelipare));	
}

int main()
{
	int n;
	printf("jep numrin e elementeve te pemes: ");
	scanf("%d",&n);
	printf("jep elementet e pemes: ");
	nyje *p=krijo_peme(n);
	printf("Pema e re eshte: ");
	afisho(p);
	if(lartesia(p,0,0))
printf("po");
else
printf("jo");
	getch();
	return 0;
}
