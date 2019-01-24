#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#define D(x) cout<<#x<<" = "<<x<<"  "
#define E cout<<endl 
using namespace std;
const int N = 200*2+5;
const int INF = 0x3f3f3f3f;

int n,m,S,T,SS,K,mxtim;
int t[N][N],f[N][N];

struct Data{ int a,b,s,t,c; } ask[N];

struct Edge{
    int from,to,nxt,cap,flow,cost;
} e[100005];
int head[N], ec=1;
void add(int a,int b,int cap,int cost){
    ec++; e[ec].cap=cap; e[ec].flow=0; e[ec].cost=cost;
    e[ec].from=a; e[ec].to=b; e[ec].nxt=head[a]; head[a]=ec;
}
void add2(int a,int b,int cap,int cost){
    add(a,b,cap,cost); add(b,a,0,-cost);
}

int dis[N],pre[N]; bool vis[N];
bool spfa(){
    memset(dis,0x3f,sizeof(dis));
    memset(vis,false,sizeof(vis));
    queue<int> q; q.push(S); vis[S]=true; dis[S]=0; pre[S]=0;
    while(!q.empty()){
        int u=q.front(); q.pop(); vis[u]=false;
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].to;
            if(e[i].cap>e[i].flow && dis[v]>dis[u]+e[i].cost){
                dis[v]=dis[u]+e[i].cost; pre[v]=i;
                if(!vis[v]){ vis[v]=true; q.push(v); }          
            }
        }
    }
    return dis[T]!=INF;
}

int mxf(){
    int ans=0,a;
    while(spfa()){
        a=INF; 
        for(int i=pre[T];i;i=pre[e[i].from]) a=min(a,e[i].cap-e[i].flow);
        for(int i=pre[T];i;i=pre[e[i].from]){
            e[i].flow+=a; e[i^1].flow-=a; ans+=a*e[i].cost;
        }
//      D(a); D(ans); E;
    }
    return ans;
}

void build(){
    S=m*2+1; T=S+1; SS=S+2;
    for(int i=1;i<=m;i++) 
        if(ask[i].s>=t[0][ask[i].a])
            add2(S,i*2-1,1,f[0][ask[i].a]);
    for(int i=1;i<=m;i++) 
        if(ask[i].t+t[ask[i].b][0]<=mxtim)
            add2(i*2,T,1,f[ask[i].b][0]);
    for(int i=1;i<=m;i++) for(int j=1;j<=m;j++)
        if(ask[i].t+t[ask[i].b][ask[j].a]<=ask[j].s)
            add2(i*2,j*2-1,1,f[ask[i].b][ask[j].a]);
    for(int i=1;i<=m;i++) add2(i*2-1,i*2,1,-ask[i].c);
    add2(S,T,INF,0); add2(SS,S,K,0); swap(S,SS);
}

int main(){
    freopen("a.in","r",stdin);
    scanf("%d%d%d%d",&n,&m,&K,&mxtim);
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%d",&t[i][j]);
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%d",&f[i][j]);
    for(int i=1;i<=m;i++) scanf("%d%d%d%d%d",&ask[i].a,&ask[i].b,&ask[i].s,&ask[i].t,&ask[i].c);
    build(); int ans=-mxf(); 
    printf("%d\n",ans);
}
