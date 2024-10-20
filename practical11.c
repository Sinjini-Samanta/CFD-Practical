#include<stdio.h>
#include<math.h>

float fun(float x)
{
    return x*(1-x);

}
int main()
{
    int i,j,m,n;
    m=n=5;
    float u[n+1][m+1],r, h=0.2,k=0.2;
    r = (k*k)/(h*h);
    
    for(j=0;j<=m;j++)
    {
        u[0][j]=u[n][j] =0;
    }
    for(i=1;i<n;i++)
    {
    	u[i][0]= fun(i*h);
        u[i][1]=u[i][0]+k;
    }
    for(j=1;j<m;j++)
    {
        for(i=1;i<n;i++)
        u[i][j+1]=2*(1-r)*u[i][j]+r*(u[i-1][j] + u[i+1][j]) - u[i][j-1];
    }
    printf(" The solution is: \n");
    for(j=0;j<=m;j++){
        for(i=0;i<=n;i++)
            printf("%6.2f",u[i][j]);
        printf("\n");
    }
}