//Funksionin GjejVlera, i cili merr si parameter matric�n T[n][n] dhe nj� num�r X dhe gjen sa vlera n�n diagonalen kryesore plot�pjestohen me X. 
#include<stdio.h>
int gjejvlera (int t[][10],int n,int x)
{int i,j,s;
for (i=1;i<n;i++)
	{for(j=0;j<i;j++)
	if(t[i][j]%x==0)
	s++;
	}
return s;
}
int main ()
{int n,i,j,x;
scanf ("%d",&n);
scanf ("%d",&x);
int t[n][10];
for (i=0;i<n;i++)
	{for(j=0;j<n;j++)
	scanf("%d",&t[i][j]);
	}
	printf ("%d",gjejvlera(t,n,x));
}
