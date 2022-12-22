#include<stdio.h>
#include<math.h>
int main()
{
	float x,u1,u,y;
	int i,j,n,fact;
	printf("Enter number of terms\n");
	scanf("%d",&n);
	float a[n][n+1];
	printf("Enter the value of X and Y\n");
	for(i=0;i<n;i++)
	{
		scanf("%f",&a[i][0]);
		scanf("%f",&a[i][1]);
	}	
	for(j=2;j<n+1;j++)
	{
		for(i=0;i<n-j+1;i++)
			a[i][j]=a[i+1][j-1]-a[i][j-1];
	}
	printf("The Difference table is as follows\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<=n-i;j++)
			printf("%f ", a[i][j]);
		printf("\n");
	}
	int ch;
	while(1)
	{
		printf("\nEnter the choice\n1.Newton Forward\n2.Newton Backward\n");
		scanf("%d", &ch);
		switch(ch)
		{
		case 1:
			printf("Value of x for which you want y\n");
			scanf("%f", &x);
			u=(x-a[0][0])/(a[1][0]-a[0][0]);
			y=a[0][1];
			u1=u;
			fact=1;
			for(i=2;i<=n;i++)
			{
				y=y+(u1*a[0][i])/fact;
				fact=fact*i;
				u1=u1*(u-(i-1));
			}
			printf("\n\nValue at X=%g is = %f", x, y);
			break;
		case 2:
			printf("Value of x for which you want y\n");
			scanf("%f", &x);
			u=(x-a[n-1][0])/(a[1][0]-a[0][0]);
			y=a[n-1][1];
			u1=u;
			fact=1;
			j=2;
			for(i=n-2;i>=0;i--)
			{
				y=y+(u1*a[i][j])/fact;
				fact=fact*j;
				u1=u1*(u+(j-1));
				j++;
			}
			printf("Value at X=%g is = %f", x, y);
			break;
		}
		default:
			return 0;
			break;
	}
}
