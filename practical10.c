#include<stdio.h>
#include<math.h>
#define X 5
#define T 5
float fun(int x)
{
    return x*x*(5-x);

}
int main()
{
    float u[X+1][T+1],square_of_c, ut, ue;
    int i,j;
    float r,h = 1, k = 1;
    r = (k*k)/(h*h);
    printf("\n Enter the square of c: ");
    scanf("%f",&square_of_c);
    printf(" Enter the value of u[0][t]:");
    scanf("%f",&ut);
    printf(" Enter the value of u[%d][t]:",X);
    scanf("%f",&ue);
    for(j=0;j<=T;j++)
    {
        u[0][j]=ut;
        u[X][j]=ue;
    }
    for(i=1;i<=X-1;i++)
{
	u[i][0]= fun(i*h);
    u[i][1]=u[i][0];

}
    for(int j=1;j<=T-1;j++)
    for(int i=1;i<=X-1;i++)
    u[i][j+1]=(u[i-1][j] + u[i+1][j]) - u[i][j-1];
    printf(" The values of u[i][j] are: \n");
    for(j=0;j<=T;j++)
    {
        for(i=0;i<=X;i++)
        printf("%6.2f",u[i][j]);
        printf("\n");

    }

}