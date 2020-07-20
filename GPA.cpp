#include<iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#define MAX 1000000
using namespace std;
int test;

int grade[10]={95,90,85,80,75,70,67,65,62,60};
float gpas[10]={4.3,4.0,3.7,3.3,3.0,2.7,2.3,2.0,1.7,1.0};
 
float dp[MAX];//存储最后背包最大能存多少

int bag;
 
void ZeroOnePack(int weight,float value )//01背包
{
    int i;
    for(i = bag; i>=weight; i--)
    {
        dp[i] = max(dp[i],dp[i-weight]+value);
    }
}
void CompletePack(int weight,float value)//完全背包
{
    int i;
    for(i = weight; i<=bag; i++)
    {
        dp[i] = max(dp[i],dp[i-weight]+value);
    }
}
 
void MultiplePack(int weight,float value,int number)//多重背包
{
    if(bag<=number*weight)//如果总容量比这个物品的容量要小，那么这个物品可以直到取完，相当于完全背包
    {
        CompletePack(weight,value);
        return ;
    }
    else//否则就将多重背包转化为01背包
    {
        int k = 1;
        while(k<=number)
        {
            ZeroOnePack(k*weight,k*value);
            number = number-k;
            k = 2*k;//这里采用二进制思想
        }
        ZeroOnePack(number*weight,number*value);
    }
}
int main()
{

    cin>>test;
    for(int k=0; k<test; k++)
    {
    scanf("%d",&bag);
    
    int n=10;
    memset(dp,0,sizeof(dp));
    for(int i = 0; i<n; i++)
    {
        MultiplePack(grade[i],gpas[i],4);//调用多重背包,注意穿参的时候分别是重量，价值和数量
    }
    printf("%.1f\n",dp[bag]);
    }
    return 0;
}
