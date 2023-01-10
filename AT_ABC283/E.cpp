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
	int a[MAXN][MAXN],n,m;
	bool mrk[MAXN][MAXN];
	void work()
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%d",&a[i][j]);
		memset(mrk,false,sizeof(mrk));
		for(int j=1;j<=m;j++) a[0][j] = a[n+1][j] = -1;
		for(int i=1;i<=n;i++) a[i][0] = a[i][m+1] = -1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(a[i][j-1] != a[i][j] && a[i][j+1] != a[i][j]) mrk[i][j] = true;
			}
		}
		bool ok = true;
		int ans = 0;
		for(int i=1;i<=n && ok;i++)
		{
			int tms = 0;
			for(int j=1;j<=m;j++)
			{
				if(a[i][j] == a[i-1][j]) mrk[i][j] = false;
				if(!mrk[i][j]) continue;
				if(a[i][j] != a[i+1][j]) tms++;
			}
			if(i == n)
			{
				if(tms > 0) ok = false;
			}
			else
			{
				if(tms > 2) ok = false;
				if(tms == 1)
				{
					for(int j=1;j<=m;j++)
						a[i+1][j] = 1-a[i+1][j];
				}
			}
			ans += tms;
		}
		if(ok) printf("%d\n",ans);
		else printf("-1\n");
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
