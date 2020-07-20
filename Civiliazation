#include<iostream>
#include<queue>
using namespace std;
const int n_max=500,population_max=9,a3_num=24,a2_num=12;
int test;
int n,x,y;

int g[n_max+1][n_max+1];
int a3[a3_num],b3[a3_num],a2[a2_num],b2[a2_num];//移动曼哈顿距离3和2的移动方案

void init()//计算移动方案
{
    int step=3;
    int counter=0;
    for(int i=-step;i<=step;i++)
    {
        for(int j=-step;j<=step;j++)
        {
            if(abs(i)+abs(j)<=step && (i!=0 || j!=0)) //排除不移动:i==0 && j==0的情况
            {a3[counter]=i;
            b3[counter]=j;
            //cout<<i<<" "<<j<<endl;
            counter++;
            }
        }
    }
    //cout<<counter<<endl;
    step=2;
    counter=0;
    for(int i=-step;i<=step;i++)
    {
        for(int j=-step;j<=step;j++)
        {
            if(abs(i)+abs(j)<=step  && (i!=0 || j!=0))
            {
                a2[counter]=i;
                b2[counter]=j;
                //cout<<i<<" "<<j<<endl;
                counter++;
            }
        }
    }
    //cout<<counter<<endl;
}

int get_round(int x,int y)//城市在x,y处完成游戏所对应的回合数
{
   
    int p=1;//现在的人数
    int produce[10]={0,g[x][y]};//每个人对应的每回合可以获取的食物数
    int round=0;//回合数
    
    priority_queue<int> q;//让食物多的地方率先被分配
    for(int i=0;i<a3_num;i++)
    {
        int n_x=x+a3[i];
        int n_y=y+b3[i];
        if(n_x<=n && n_x>0 &&n_y <=n && n_y>0 )
        {
            q.push(g[n_x][n_y]);
        }
    }
    int total=0;//积累的总食物
    while(p<population_max)
    {
        
        for(int i=1;i<10;i++)
        {
            total+=produce[i];
        }
        if(total>=p*p*8)
        {
            p++;
            if(!q.empty())//空则表明有人失业了，这个人不能产出食物了
            {
            produce[p]=q.top();
            q.pop();
            }
        }
        round++;

    }
    return round;

}
int mini_round; //最小回合数

int bfs()
{
    mini_round=get_round(x,y);
    int visited[n_max][n_max]={0};
    //memset(visited,0,sizeof(visited));
    int n_x,n_y;
    visited[x][y]=1;
    queue<pair<int,int>> q;
    int level=0;
    q.push(make_pair(x,y));
    int rounds[mini_round]={1};//记录每层的合法的点数
    while (!q.empty())
    {
        pair<int,int> temp=q.front();
        mini_round=min(get_round(temp.first,temp.second)+level,mini_round);
        q.pop();
    
       
        for(int i=0;i<a2_num;i++)
        {
        n_x=temp.first+a2[i];
        n_y=temp.second+b2[i];
        if(n_x<=n && n_x>0 &&n_y <=n && n_y>0 && !visited[n_x][n_y])
        {
            //cout<<n_x<<" "<<n_y<<" "<<round<<endl;
            q.push(make_pair(n_x,n_y)); 
            visited[n_x][n_y]=1;
            rounds[level+1]+=1;//压的是下一层的点所以level+1
        }   
        }
        rounds[level]-=1;
        if( rounds[level]==0) //该层遍历完了该遍历下一层了
        {  
            level++;
            if(level>=mini_round) /*每下一层就在开始建城前多移动了level回合
                                    如果移动的回合大于目前最小的总回合数，那再放下一层找就不可能产生更优解了*/
                 break;
                
        }
    }
    return mini_round; 
     
}

int main()
{
    init();
    cin>>test;
    for(int k=0; k<test; k++)
    {
    scanf("%d%d%d",&n,&x,&y);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&g[i][j]);
        }
    }
    cout<<bfs()<<endl;
    }
}
