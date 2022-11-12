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
	const int MAXN = 200005;
	typedef long long LL;
	int n, a[MAXN];
	map<LL,int>vis;
	LL s[MAXN];
	int q[MAXN], tot;
	void work()
	{
		int tst; scanf("%d",&tst);
		while(tst--)
		{
			scanf("%d",&n);
			for(int i=1;i<=n;i++) scanf("%d",&a[i]);
			s[0] = 0;
			for(int i=1;i<=n;i++) s[i] = s[i-1]+a[i];
			a[n+1] = 0;
			tot = 0;
			for(int i=1;i<=n+1;i++)
				if(a[i] == 0) q[++tot] = i;
			int ans = 0;
			for(int i=1;i<q[1];i++)
				if(s[i] == 0) ans++;
			for(int k=1;k<tot;k++)
			{
				int best = 0;
				int start = q[k], end = q[k+1];
				vis.clear();
				for(int i=start;i<end;i++)
				{
					if(vis.count(s[i]) == 0) vis[s[i]] = 1;
					else vis[s[i]] = vis[s[i]]+1;
					best = vis[s[i]] > best ? vis[s[i]] : best;
				}
				ans += best;
			}
			printf("%d\n",ans);
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
