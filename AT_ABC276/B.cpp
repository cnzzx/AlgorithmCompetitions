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
	vector<int>g[MAXN];
	int n,m;
	void work()
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(int i=1;i<=n;i++)
		{
			int sz = g[i].size();
			printf("%d ",sz);
			sort(g[i].begin(), g[i].end());
			for(int k=0;k<sz;k++)
				printf("%d ",g[i][k]);
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
