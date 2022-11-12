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
	const int INF = 2000000005;
	inline int mymax(int a,int b){return a>b?a:b;}
	int n,a[MAXN];
	char s[MAXN];
	int f[MAXN][2];
	void work()
	{
		int tst; scanf("%d",&tst);
		while(tst--)
		{
			scanf("%d",&n);
			scanf("%s",s);
			a[0] = 0;
			for(int i=1;i<=n;i++) scanf("%d",&a[i]);
			for(int i=0;i<=n;i++) f[i][0] = f[i][1] = -INF;
			f[0][0] = 0;
			for(int i=1;i<=n;i++)
			{
				if(s[i-1] == '0')
				{
					f[i][1] = -INF;
					f[i][0] = mymax(f[i-1][0], f[i-1][1]);
				}
				else
				{
					f[i][0] = mymax(f[i-1][0]+a[i-1], f[i-1][1]);
					f[i][1] = a[i] + mymax(f[i-1][0], f[i-1][1]);
				}
			}
			printf("%d\n",mymax(f[n][0], f[n][1]));
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
