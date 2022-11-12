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
	int n,a[MAXN];
	void work()
	{
		int tst; scanf("%d",&tst);
		while(tst--)
		{
			scanf("%d",&n);
			for(int i=1;i<=n;i++) scanf("%d",&a[i]);
			bool ok = true;
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if(a[i] == a[j]) ok = false;
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
