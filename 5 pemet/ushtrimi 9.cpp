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
//kthen true nese nr i elementeve cift eshte i barabarte me nr e elementeve negative.
int a=0,b=0,c=0;
int nr(peme *Q)
{if(Q==NULL)
return 0;
if(Q->vlere%2==0&&Q->vlere<0)
 {c++;
}
if (Q->vlere%2==0)
 {a++;
}
if(Q->vlere<0)
 {b++;
}
 nr(Q->majte);
 nr(Q->djathte);
if(a+c==b+c)
return 1;
else return 0;
}

int main()
{
	int n;
	printf("Jep nr e elementeve te pemes:\n");
	scanf("%d",&n);
	printf("Nderto pemen:\n");
	peme * Q=Krijo_peme(n);
	int a=0,b=0,c=0;
if(nr(Q)==1)
printf("PO");
else printf("JO");
	getch(); 
	return 0;
}
