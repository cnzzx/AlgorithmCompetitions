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
	const int MAXN = 200005;
	inline int mymax(int a,int b){return a>b?a:b;}
	int n,q,h[MAXN],qs[MAXN];
	LL sumh[MAXN];
	int maxh[MAXN];
	void work()
	{
		int tst; scanf("%d",&tst);
		while(tst--)
		{
			scanf("%d%d",&n,&q);
			for(int i=1;i<=n;i++) scanf("%d",&h[i]);
			for(int i=1;i<=q;i++) scanf("%d",&qs[i]);
			sumh[0] = 0;
			for(int i=1;i<=n;i++) sumh[i] = sumh[i-1] + h[i];
			maxh[0] = 0;
			for(int i=1;i<=n;i++) maxh[i] = mymax(maxh[i-1], h[i]);
			for(int i=1;i<=q;i++)
			{
				int v = qs[i];
				int pos = upper_bound(maxh+1,maxh+n+1, v)-maxh-1;
				printf("%lld ",sumh[pos]);
			}
			printf("\n");
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
