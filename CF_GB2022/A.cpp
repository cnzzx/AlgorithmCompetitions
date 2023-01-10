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
	const int MAXN = 105;
	int a[MAXN],b[MAXN],t[MAXN];
	void work()
	{
		int tst;scanf("%d",&tst);
		while(tst--)
		{
			int n,m;
			scanf("%d%d",&n,&m);
			for(int i=1;i<=n;i++) scanf("%d",&a[i]);
			for(int i=1;i<=m;i++) scanf("%d",&b[i]);
			LL ans = 0;
			for(int i=1;i<=n;i++) t[i] = a[i];
			for(int i=1;i<=m;i++)
			{
				int mi = 1, mv = t[1];
				for(int j=1;j<=n;j++)
					if(t[j] < mv) mv = t[j], mi = j;
				t[mi] = b[i];
			}
			for(int i=1;i<=n;i++) ans += t[i];
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
