
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
bool tebarabart(peme *p)
{
	if(p==NULL)
	return false;
	if(p->majte!=NULL)
	{
		if(p->vlere!=p->majte->vlere)
		return false;
	}
	if(p->djathte!=NULL)
	{
		if(p->vlere!=p->djathte->vlere)
		return false;
	}
	bool a=tebarabart(p->majte);
	if(a==false)
	return false;
	bool b=tebarabart(p->djathte);
	if(b==false)
	return false;
	return true;
}


int main()
{
	int n;
	printf("Jep nr e elementeve te pemes:\n");
	scanf("%d",&n);
	printf("Nderto pemen:\n");
	peme * Q=Krijo_peme(n);
if(tebarabar)
printf ("TRUE");
else printf ("FALSE");
	getch(); 
	return 0;
}
