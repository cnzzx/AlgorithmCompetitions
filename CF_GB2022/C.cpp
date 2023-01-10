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
	const int MAXN = 1005;
	int n; LL a[MAXN],b[MAXN];
	int cnt[MAXN];
	void work()
	{
		int tst;scanf("%d",&tst);
		while(tst--)
		{
			scanf("%d",&n);
			for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
			bool ok = true;
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					if(a[i] == a[j]) ok = false;
			if(ok)
			{
				for(int d=2;d<=50;d++)
				{
					for(int i=1;i<=n;i++) b[i] = a[i]%d;
					for(int i=0;i<d;i++) cnt[i] = 0;
					for(int i=1;i<=n;i++) cnt[b[i]]++;
					int bad = 0;
					for(int i=0;i<d;i++) if(cnt[i] >= 2) bad++;
					if(bad >= d){ok = false;break;}
				}
			}
			if(ok) printf("YES\n");
			else printf("NO\n");
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
