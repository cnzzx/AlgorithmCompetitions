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
	const int MAXN = 100005;
	typedef long long LL;
	int n; char s[MAXN];
	int cnt[MAXN][10];
	void work()
	{
		int tst; scanf("%d",&tst);
		while(tst--)
		{
			scanf("%d%s",&n,s+1);
			for(int i=0;i<=n;i++) for(int k=0;k<=9;k++) cnt[i][k] = 0;
			for(int i=1;i<=n;i++)
				cnt[i][s[i]-'0']++;
			for(int i=1;i<=n;i++)
				for(int k=0;k<=9;k++)
					cnt[i][k] = cnt[i-1][k] + cnt[i][k];
			int ans = 0;
			for(int len=1;len<=100;len++)
			{
				for(int i=1;i<=n;i++)
				{
					int j = i+len-1;
					if(j > n) continue;
					int div = 0;
					for(int k=0;k<=9;k++)
						if(cnt[j][k]-cnt[i-1][k] > 0) div++;
					bool ok = true;
					for(int k=0;k<=9;k++)
						if(cnt[j][k] - cnt[i-1][k] > div) ok = false;
					if(ok) ans++;
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
