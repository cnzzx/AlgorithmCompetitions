#include<algorithm>
#include<bitset>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<vector>
using namespace std;
namespace Solve
{
	const int MAXN = 300005;
	inline int mymax(int a,int b){return a>b?a:b;}
	int n,a[MAXN],b[MAXN],ra[MAXN],rb[MAXN];
	int rt,np,lc[MAXN<<1],rc[MAXN<<1],maxv[MAXN<<1];
	void init()
	{
		rt = np = 0;
		memset(lc,0,sizeof(lc));
		memset(rc,0,sizeof(rc));
		memset(maxv,0,sizeof(maxv));
		return;
	}
	void pushup(int now)
	{
		maxv[now] = mymax(maxv[lc[now]], maxv[rc[now]]);
		return;
	}
	void build(int &now,int l,int r)
	{
		if(!now) now = ++np;
		if(l == r){
			maxv[now] = 0;
			return;
		}
		int m = (l + r) >> 1;
		build(lc[now],l,m);
		build(rc[now],m+1,r);
		pushup(now);
		return;
	}
	void upd(int now,int l,int r,int i,int v)
	{
		if(l == r && l == i)
		{
			maxv[now] = mymax(maxv[now], v);
			return;
		}
		int m = (l + r) >> 1;
		if(i <= m) upd(lc[now],l,m,i,v);
		else upd(rc[now],m+1,r,i,v);
		pushup(now);
		return;
	}
	int qmax(int now,int l,int r,int i,int j)
	{
		if(i <= l && r <= j) return maxv[now];
		int m = (l + r) >> 1;
		if(j <= m) return qmax(lc[now],l,m,i,j);
		else if(i > m) return qmax(rc[now],m+1,r,i,j);
		return mymax(qmax(lc[now],l,m,i,m),qmax(rc[now],m+1,r,m+1,j));
	}
	int dp(int *x)
	{
		init();
		build(rt,1,n);
		int ret = 1;
		for(int i=1;i<=n;i++)
		{
			// printf("%d ",x[i]);
			if(x[i]==1) upd(rt,1,n,x[i],1);
			else
			{
				int f = qmax(rt,1,n,1,x[i]-1); f++;
				upd(rt,1,n,x[i],f);
				ret = mymax(ret, f);
			}
		}
		// printf("\n");
		return ret;
	}
	void work()
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++) scanf("%d",&b[i]);
		for(int i=1;i<=n;i++) rb[a[i]] = b[i];
		for(int i=1;i<=n;i++) ra[b[i]] = a[i];
		int ans = mymax(dp(ra), dp(rb)) + n;
		printf("%d\n",ans);
		return;
	}
}
int main()
{
	#ifdef LOCAL
	freopen("00test.in","r",stdin);
	freopen("00test.out","w",stdout);
	#endif
	Solve::work(); 
	return 0;
}
