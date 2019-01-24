#include <iostream>
#include <cstring>
#include <map>
#include <cstdio>
#include <queue>
#include <algorithm>


using namespace std;

const int N = 200*2+5;
const int INF = 0x3f3f3f3f;

int n,m,S,T,SS,K,max_time;
int t[N][N],f[N][N];

struct Data{ int a,b,s,t,c; } ask[N];

struct Edge{
    int from,to,next,capp,flow,cost;
} edges[100005];

int header[N], edges_count=1;
void add_one(int a,int b,int capp,int cost){
    edges_count++; 
    edges[edges_count].capp=capp; 
    edges[edges_count].flow=0; 
    edges[edges_count].cost=cost;
    edges[edges_count].from=a; 
    edges[edges_count].to=b; 
    edges[edges_count].next=header[a]; 
    header[a]=edges_count;
}
void add_two(int a,int b,int capp,int cost){
    add_one(a,b,capp,cost); 
    add_one(b,a,0,-cost);
}

int dist[N],pre[N]; bool visit[N];
bool spfa(){
    memset(dist,0x3f,sizeof(dist));
    memset(visit,false,sizeof(visit));
    queue<int> q; q.push(S); visit[S]=true; dist[S]=0; pre[S]=0;
    while(!q.empty()){
        int u=q.front(); q.pop(); visit[u]=false;
        for(int i=header[u];i;i=edges[i].next){
            int v=edges[i].to;
            if(edges[i].capp>edges[i].flow && dist[v]>dist[u]+edges[i].cost){
                dist[v]=dist[u]+edges[i].cost; pre[v]=i;
                if(!visit[v]){ visit[v]=true; q.push(v); }          
            }
        }
    }
    return dist[T]!=INF;
}

int mxf(){
    int ans=0,a;
    while(spfa()){
        a=INF; 
        for(int i=pre[T];i;i=pre[edges[i].from]) a=min(a,edges[i].capp-edges[i].flow);
        for(int i=pre[T];i;i=pre[edges[i].from]){
            edges[i].flow+=a; edges[i^1].flow-=a; ans+=a*edges[i].cost;
        }
    }
    return ans;
}

void build(){
    S=m*2+1; T=S+1; SS=S+2;
    for(int i=1;i<=m;i++) 
        if(ask[i].s>=t[0][ask[i].a])
            add_two(S,i*2-1,1,f[0][ask[i].a]);
    for(int i=1;i<=m;i++) 
        if(ask[i].t+t[ask[i].b][0]<=max_time)
            add_two(i*2,T,1,f[ask[i].b][0]);
    for(int i=1;i<=m;i++) for(int j=1;j<=m;j++)
        if(ask[i].t+t[ask[i].b][ask[j].a]<=ask[j].s)
            add_two(i*2,j*2-1,1,f[ask[i].b][ask[j].a]);
    for(int i=1;i<=m;i++) add_two(i*2-1,i*2,1,-ask[i].c);
    add_two(S,T,INF,0); add_two(SS,S,K,0); swap(S,SS);
}

int main(){
    freopen("a.in","r",stdin);
    scanf("%d%d%d%d",&n,&m,&K,&max_time);
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%d",&t[i][j]);
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%d",&f[i][j]);
    for(int i=1;i<=m;i++) 
        scanf("%d%d%d%d%d",&ask[i].a,&ask[i].b,&ask[i].s,&ask[i].t,&ask[i].c);
    build(); int ans=-mxf(); 
    printf("%d\n",ans);
}