//afishon kodin e farmacisë e cila ka me shumë gjendje në total
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#define z 10
typedef struct farmacia{
	char *kodi;
	int gjendjet [z];
}farmacia;
int main()
{FILE *kod,*gj,*il;
int n,m,i,j,sh,max=0,poz;
kod=fopen("C:/farmacia.txt","r");
gj=fopen("C:/gjendje.txt","r");
il=fopen("C:/ilace.txt","r");
if(kod==NULL||gj==NULL)
{printf ("gabim");
return 0;
}
else
fscanf (gj,"%d",&m);
fscanf (gj,"%d",&n);
farmacia f[m];
for (i=0;i<m;i++)
	{   f[i].kodi=(char*)malloc(sizeof(char));
	    fscanf (kod,"%s",f[i].kodi);
		for(j=0;j<n;j++)
		fscanf (gj,"%d",&f[i].gjendjet[j]);
	}
char *ilac[n];
for (i=0;i<m;i++)
	{   ilac[i]=(char*)malloc(sizeof(char));
	    fscanf (il,"%s",ilac[i]);
	}
//afishon kodin e farmacisë e cila ka me shumë gjendje në total
for (i=0;i<m;i++)
	{ sh=0;
	for(j=0;j<n;j++)
	{	sh=sh+f[i].gjendjet[j];}
		if(sh>max)
		{max=sh;
		poz=i;
		}
	}
printf ("farmacia me me shume hyrje esht %s\n",f[poz].kodi);
//) afishon kodin e ilacit, i cili ka të paktën një gjendje 0 në një nga farmacitë.
for (j=0;j<n;j++)
	{sh=0;
		for(i=0;i<m;i++)
		{if(f[i].gjendjet[j]==0)
		sh++;
		}
		if(sh!=0)
		printf ("ilaci qe ka te pakten nje gjendje zero ne nje nga farmacite eshte :%s\n",ilac[j]);
	}

fclose(kod);
fclose(gj);
fclose(il);
return 0;







}

