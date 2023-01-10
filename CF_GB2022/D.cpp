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
	typedef long long LL;
	const int MAXN = 100005;
	const int mo = 998244353;
	int qkpow(int a,int k)
	{
		int ret = 1, tt = a;
		while(k)
		{
			if(k&1) ret = (LL)ret*tt%mo;
			tt = (LL)tt*tt%mo;
			k >>= 1;
		}
		return ret;
	}
	int n,a[MAXN],b[MAXN];
	int cnt[MAXN];
	vector<int>g[MAXN];
	bool mrk[MAXN],vis[MAXN];
	bool dfs(int i,int fa)
	{
		bool ok = false;
		vis[i] = true;
		vector<int>::iterator it;
		for(it=g[i].begin();it!=g[i].end();it++)
		{
			int j = *it;
			// printf("%d -> %d\n",i,j);
			if(vis[j])
			{
				if(j!=fa) ok=true;
				continue;
			}
			if(dfs(j,i)) ok = true;
		}
		return ok;
	}
	void work()
	{
		int tst;scanf("%d",&tst);
		while(tst--)
		{
			scanf("%d",&n);
			for(int i=1;i<=n;i++) scanf("%d",&a[i]);
			for(int i=1;i<=n;i++) scanf("%d",&b[i]);
			for(int i=1;i<=n;i++) cnt[i] = 0;
			for(int i=1;i<=n;i++)
			{
				if(a[i] == b[i]) cnt[a[i]]++;
			}
			int tot = 0;
			for(int i=1;i<=n;i++)
			{
				if(cnt[i] == 1) tot++;
				else if(cnt[i] > 1)
				{
					tot = -1;
					break;
				}
			}
			if(tot == -1)
			{
				printf("0\n");
				continue;
			}
			LL ans = qkpow(n,tot);
			for(int i=1;i<=n;i++) mrk[i] = false;
			for(int i=1;i<=n;i++)
			{
				if(a[i] == b[i]) mrk[i] = true;
				else if(cnt[a[i]])
				{
					mrk[i] = true;
					cnt[b[i]]++;
				}
				else if(cnt[b[i]])
				{
					mrk[i] = true;
					cnt[a[i]]++;
				}
			}
			tot = 0;
			for(int i=1;i<=n;i++)
			{
				if(cnt[i] <= 1) continue;
				else if(cnt[i] > 1)
				{
					tot = -1;
					break;
				}
			}
			if(tot == -1)
			{
				printf("0\n");
				continue;
			}
			for(int i=1;i<=n;i++) g[i].clear();
			for(int i=1;i<=n;i++)
			{
				if(mrk[i]) continue;
				g[a[i]].push_back(b[i]);
				g[b[i]].push_back(a[i]);
			}
			for(int i=1;i<=n;i++) vis[i] = false;
			for(int i=1;i<=n;i++)
			{
				if(!cnt[i] && !vis[i])
				{
					if(!dfs(i,0))
					{
						tot = -1;
						break;
					}
					else tot++;
				}
			}
			if(tot == -1)
			{
				printf("0\n");
				continue;
			}
			ans = (LL)ans * qkpow(2,tot)%mo;
			printf("%lld\n",ans);
		}
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
