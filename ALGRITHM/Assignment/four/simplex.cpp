#include <cstdio>
#include <algorithm>
 
#define rep(i, l, r) for(int i=l; i<=r; i++)
     
using namespace std;
 
inline int read()
{
    int x=0; bool f=0; char ch=getchar();
    while (ch<'0' || '9'<ch) f|=ch=='-', ch=getchar();
    while ('0'<=ch && ch<='9') x=x*10+ch-'0', ch=getchar();
    return f?-x:x;
}
 
#define maxn 21
#define eps 1e-8
 
int n, m, op, tot, q[maxn], idx[maxn], idy[maxn]; double a[maxn][maxn], A[maxn];
 
inline void Pivot(int x, int y)
{
    swap(idy[x],idx[y]);
    double tmp=a[x][y]; a[x][y]=1/a[x][y];
    rep(i, 0, n) if (y!=i) a[x][i]/=tmp;
    tot=0; rep(i, 0, n) if (i!=y && (a[x][i]>eps || a[x][i]<-eps)) q[++tot]=i;
    rep(i, 0, m)
    {
        if ((x==i) || (a[i][y]<eps && a[i][y]>-eps)) continue;
        rep(j, 1, tot) a[i][q[j]]-=a[x][q[j]]*a[i][y];
        a[i][y]=-a[i][y]/tmp;
    }
}
 
int main()
{
    n=read(), m=read(), op=read();
    rep(i, 1, n) a[0][i]=read();
    rep(i, 1, m)
    {
        rep(j, 1, n) a[i][j]=read();
        a[i][0]=read();
    }
     
    rep(i, 1, n) idx[i]=i;
    rep(i, 1, m) idy[i]=i+n;
    while (true)
    {
        int x=0, y=0;
        rep(i, 1, m) if (a[i][0]<-eps && ((!x)||(rand()&1))) x=i; if (!x) break;
        rep(i, 1, n) if (a[x][i]<-eps && ((!y)||(rand()&1))) y=i; if (!y) return puts("Infeasible"),0;
        Pivot(x,y);
    }
     
    while (true)
    {
        int x=0, y=0; double mn=1e15;
        rep(i, 1, n) if (a[0][i]>eps) {y=i; break;} if (!y) break;
        rep(i, 1, m) if (a[i][y]>eps && a[i][0]/a[i][y]<mn) mn=a[i][0]/a[i][y], x=i; if (!x) return puts("Unbounded"),0;
        Pivot(x,y);
    }
     
    printf("%.8lf\n", -a[0][0]); if (!op) return 0;
    rep(i, 1, m) if (idy[i]<=n) A[idy[i]]=a[i][0];
    rep(i, 1, n) printf("%.8lf%c", A[i], i==n?'\n':' ');
     
    return 0;
}
