#include<iostream>
using namespace std;

const int n_max=1000;
int test;
int a,b;

int f[n_max+1][n_max+1];
int gcd(int a,int b)//辗转相除求最小公约数
{
    int temp=a;
    while(a%b)
    {
        a=b;
        b=temp%b;
        temp=a;
    }
    return b;
}
void dp()
{
    for(int i=1;i<=n_max;i++)
    {
        for(int j=1;j<=n_max;j++)
        {
            int t=0;
            if (gcd(i,j)==1)//如果最大公约数是0则互质
            t=1;
            f[i][j]=max(f[i-1][j]+t,f[i][j-1]+t);
        }

    }

}
int main()
{
    cin>>test;
    dp();
    for(int k=0; k<test; k++)
    {
    scanf("%d%d",&a,&b); //输入用cin/cout都会超时
    printf("%d\n",f[a][b]);
    }

}
