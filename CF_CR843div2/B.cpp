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
	const int MAXN = 200005;
	int n;
	vector<int>c[MAXN];
	vector<int>::iterator it;
	int n_one[MAXN];
	int cnt[MAXN];
	void work()
	{
		int tst; scanf("%d",&tst);
		memset(cnt,0,sizeof(cnt));
		while(tst--)
		{
			scanf("%d",&n);
			for(int i=1;i<=n;i++) c[i].clear();
			for(int i=1;i<=n;i++)
			{
				scanf("%d",&n_one[i]);
				for(int j=1;j<=n_one[i];j++)
				{
					int v;scanf("%d",&v);
					c[i].push_back(v);
					cnt[v]++;
				}
			}
			int cnt_sp = 0;
			for(int i=1;i<=n;i++)
			{
				for(it=c[i].begin();it!=c[i].end();it++)
				{
					if(cnt[*it] == 1)
					{
						cnt_sp++;
						break;
					}
				}
			}
			if(cnt_sp != n) printf("Yes\n");
			else printf("No\n");
			for(int i=1;i<=n;i++)
			{
				for(it=c[i].begin();it!=c[i].end();it++)
				{
					cnt[*it]--;
				}
			}
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
