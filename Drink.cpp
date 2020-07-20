#include<iostream>
using namespace std;
const int inf=1<<30;
const int n_max=100,m_max=10000,moisture_max=100;
int moisture[n_max],calorie[n_max];//水分，卡路里
int n,m;//饮料种类，至少补充的水分

int func()
{
    int r=inf;
    int temp=0;
    for(int i=0;i<n;i++)
    {
        if(m%moisture[i]==0)
            temp=m/moisture[i]*calorie[i];
        else
            temp=(m/moisture[i]+1)*calorie[i];//不恰好够就多喝一点
        if(temp<r)
        r=temp;        
    }
    
    return r;
}
int test;

int main()
{
    cin>>test;
    for(int k=0; k<test; k++)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&moisture[i],&calorie[i]);

        }
        cout<<func()<<endl;
    }
}
