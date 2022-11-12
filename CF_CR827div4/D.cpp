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
	const int MAXV = 1005;
	const int MAXN = 200005;
	int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
	int n,a[MAXN];
	int last_pos[MAXV];
	bool vis[MAXV];
	void work()
	{
		int tst; scanf("%d",&tst);
		while(tst--)
		{
			memset(vis,0,sizeof(vis));
			scanf("%d",&n);
			for(int i=1;i<=n;i++) scanf("%d",&a[i]);
			for(int i=1;i<=1000;i++) last_pos[i] = n+1;
			for(int i=1;i<=n;i++) last_pos[a[i]] = i, vis[a[i]] = true;
			int ans = -1;
			for(int i=1;i<=1000;i++)
			{
				if(!vis[i]) continue;
				for(int j=i;j<=1000;j++)
				{
					if(!vis[j]) continue;
					if(gcd(i,j) == 1)
					{
						if(ans == -1) ans = last_pos[i]+last_pos[j];
						else if(last_pos[i]+last_pos[j] > ans) ans = last_pos[i]+last_pos[j];
					}
				}
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
