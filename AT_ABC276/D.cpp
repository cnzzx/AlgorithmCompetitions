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
	const int MAXN = 1005;
	int n,a[MAXN];
	int e[MAXN][10];
	void work()
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		memset(e,0,sizeof(e));
		for(int i=1;i<=n;i++)
		{
			while(a[i]%2 == 0)
			{
				a[i] /= 2;
				e[i][2]++;
			}
			while(a[i]%3 == 0)
			{
				a[i] /= 3;
				e[i][3]++;
			}
		}
		for(int i=2;i<=n;i++)
		{
			if(a[i] != a[i-1])
			{
				printf("-1\n");
				return;
			}
		}
		int ans = 0;
		int mine[10];
		mine[2] = e[1][2], mine[3] = e[1][3];
		for(int i=1;i<=n;i++)
		{
			mine[2] = mine[2] < e[i][2] ? mine[2] : e[i][2];
			mine[3] = mine[3] < e[i][3] ? mine[3] : e[i][3];
		}
		for(int i=1;i<=n;i++)
		{
			ans += (e[i][2]-mine[2]) + (e[i][3] - mine[3]);
		}
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
