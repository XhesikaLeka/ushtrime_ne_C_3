/*Funksionin rekursiv q� merr si paramet�r nj� vektor T, gjat�sin� e tij N dhe z�vend�son numrat negative me vler�n 0.
 Shembull: T = {1,-2, 3}, output: {1,0,3}.*/
 #include <stdio.h>
 void konverto (int t[],int n)
 {if(n==0)
 return;
 else if(t[n-1]<0)
 t[n-1]=0;
 return konverto(t,n-1);
 }
 int main ()
 {int n,i;
 scanf("%d",&n);
 int t[n];
 for(i=0;i<n;i++)
 	{scanf("%d",&t[i]);
	 }
	 konverto(t,n);
	 for(i=0;i<n;i++)
 	{printf("%d ",t[i]);
	 }
	 return 0;
 }
