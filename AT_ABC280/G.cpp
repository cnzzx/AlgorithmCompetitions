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
	const int MAXN = 305;
	const int mo = 998244353;
	typedef long long LL;
	inline LL mysgn(LL a){return a<0?-1:1;}
	inline LL myabs(LL a){return a<0?-a:a;}
	inline LL mymin(LL a, LL b){return a<b?a:b;}
	inline LL mymax(LL a, LL b){return a>b?a:b;}
	LL qkpow(LL a,LL k)
	{
		LL ret = 1, tt = a;
		while(k)
		{
			if(k&1) ret = ret * tt %mo;
			tt = tt * tt%mo;
			k >>= 1;
		}
		return ret;
	}
	LL x[MAXN],y[MAXN],n,d;
	LL hx_dis(int i,int j)
	{
		LL dx = myabs(x[i]-x[j]);
		LL dy = myabs(y[i]-y[j]);
		if(mysgn(x[i]-x[j])*mysgn(y[i]-y[j]) >= 0) return mymax(dx, dy);
		else return dx + dy;
	}
	bool g[MAXN][MAXN];
	LL f[MAXN][MAXN];
	void work()
	{
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)
			scanf("%lld%lld",&x[i],&y[i]);
		memset(g,false,sizeof(g));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(hx_dis(i,j) > d) g[i][j] = false;
				else g[i][j] = true;
			}
		}
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++) f[i][i] = 1;
		for(int len=2;len<=n;len++)
		{
			for(int i=1;i<=n-len+1;i++)
			{
				int j = i+len-1;
				// no i & no j
				f[i][j] = f[i+1][j-1];
				// yes i & no j
				LL temp = 1; int lst = i;
				for(int k=i+1;k<=j;k++)
				{
					if(!g[i][k])
					{
						temp = (temp*(f[lst+1][k-1]+1))%mo;
						lst = k;
					}
				}
				temp = (temp*(f[lst+1][j-1]+1))%mo;
				f[i][j] = (f[i][j] + temp)%mo;
				// no i & yes j
				temp = 1; lst = j;
				for(int k=j-1;k>=i;k--)
				{
					if(!g[j][k])
					{
						temp = (temp*(f[k+1][lst-1]+1))%mo;
						lst = k;
					}
				}
				temp = (temp*(f[i+1][lst-1]+1))%mo;
				f[i][j] = (f[i][j] + temp)%mo;
				// yes i & yes j
				if(!g[i][j]) continue;
				for(int k=i+1;k<=j;k++)
				{
					if(!g[i][k] || !g[j][k])
					{
						temp = (temp*(f[lst+1][k-1]+1))%mo;
						lst = k;
					}
				}
				temp = (temp*(f[lst+1][j-1]+1))%mo;
				f[i][j] = (f[i][j] + temp)%mo;
			}
		}
		printf("%lld\n",f[1][n]);
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=n;j++)
//			{
//				printf("%d ",g[i][j]);
//			}
//			printf("\n");
//		}
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
