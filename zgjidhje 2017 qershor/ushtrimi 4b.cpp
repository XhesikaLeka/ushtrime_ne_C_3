
/*merr si parameter listën LDR dhe fshin elementin e dytë të listës. */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct nyje {
	int vlere;
	struct nyje *para;
	struct nyje *pas;
} nyje;

nyje *krijo_nyje(int vlere)
{
	nyje *n;
	n=(nyje*)malloc(sizeof(nyje));
	n->vlere=vlere;
	n->para=NULL;
	n->pas=NULL;
	return n;
}

nyje *krijo_liste(int n)
{
	if(n==0)
	return NULL;
	nyje *koka;
	int vlere;
	scanf("%d",&vlere);
	koka=krijo_nyje(vlere);
	nyje *eliri=koka;
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&vlere);
		eliri->pas=krijo_nyje(vlere);
		eliri->pas->para=eliri;
		eliri=eliri->pas;
	}
	eliri->pas=koka;
	eliri->para=koka;
	return koka;
}


void afisho(nyje *L)
{
	nyje *tmp=L;
	
	while(tmp->pas!=L)
	{
		printf("%d ",tmp->vlere);
		tmp=tmp->pas;
	}
	printf("%d ",tmp->vlere);
}
//merr si parameter listën LDR dhe fshin elementin e dytë të listës.
nyje *fshi (nyje *L)
{if(L==NULL)
return NULL;
else if (L->pas==L)
return NULL;
else {
	L->pas=L->pas->pas;
	L->pas->pas->para=L;
	}
return L;

}
int main()
{
	int n,M;
	printf("Jep numrin e elementeve te listes: ");
	scanf("%d",&n);
	printf("Jep  elementet e listes: ");
	nyje *L=krijo_liste(n);
		L=fshi(L);
	afisho(L);

	getch();
	return 0;
}
