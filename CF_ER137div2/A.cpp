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
	int C[15][15];
	int n,a[15];
	void work()
	{
		int tst; scanf("%d",&tst);
		C[0][0] = 1;
		for(int i=1;i<=10;i++)
		{
			C[i][0] = C[i-1][0];
			for(int j=1;j<=i;j++)
			{
				C[i][j] = C[i-1][j] + C[i-1][j-1];
			}
		}
		while(tst--)
		{
			scanf("%d",&n);
			for(int i=1;i<=n;i++) scanf("%d",&a[i]);
			printf("%d\n",6 * C[10-n][2]);
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
