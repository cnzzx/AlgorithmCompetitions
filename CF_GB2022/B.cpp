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
	const int MAXN = 1000005;
	int n,k,a[MAXN];
	void work()
	{
		int tst;scanf("%d",&tst);
		while(tst--)
		{
			scanf("%d%d",&n,&k);
			int low = 1, upp = n;
			for(int i=1;i<=n;i++)
			{
				if(i&1) a[i] = upp--;
				else a[i] = low++;
			}
			for(int i=1;i<=n;i++) printf("%d ",a[i]);
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
