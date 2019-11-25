/*#include <stdio.h>
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
float mes(peme *Q,int c,int sh)
{if(Q==NULL)
return (float)sh/c;
else {c++;
sh=Q->vlere+mes(Q->majte,c,sh)+mes(Q->djathte,c,sh);}
return (float)sh/c;
}

int main()
{
	int n;
	printf("Jep nr e elementeve te pemes:\n");
	scanf("%d",&n);
	printf("Nderto pemen:\n");
	peme * Q=Krijo_peme(n);
int c=0,sh=0;
int a=mes(Q,c,sh);
printf("%0.2f",a);
	getch(); 
	return 0;
}*/
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

float s=0;
int c=0;
float mesatare(nyje * p,int niveli)
{
	if(p==NULL)
	return 0;
	int a=0,b=0;
	if(p->majte!=NULL)
	{
		c++;
		a=mesatare(p->majte,niveli+1);
	}
	if(p->djathte!=NULL)
	{
		c++;
		b=mesatare(p->djathte,niveli+1);
	}
	if(niveli==1)
	{
		s+=p->vlere;
		c++;
		return s/c;
	}
	s+=p->vlere;
	return s;
}
int main()
{
	int n;
	printf("jep numrin e elementeve te pemes: ");
	scanf("%d",&n);
	printf("jep elementet e pemes: ");
	nyje *p=krijo_peme(n);
	printf("shuma eshte: %f\nnr i ele eshte: %d\nmesatarja eshte: %f",s,c,mesatare(p,1));
	getch();
	return 0;
}
