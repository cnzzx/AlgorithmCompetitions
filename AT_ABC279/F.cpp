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
	const int MAXN = 1000005;
	int pa[MAXN],box_id[MAXN],rt[MAXN];
	void init(int N,int Q)
	{
		for(int i=1;i<=N+Q;i++) pa[i] = i;
		for(int i=1;i<=N+Q;i++) box_id[i] = i;
		for(int i=1;i<=N+Q;i++) rt[i] = i;
		return;
	}
	int find(int x)
	{
		if(x == pa[x]) return x;
		return pa[x] = find(pa[x]);
	}
	int n,q;
	void work()
	{
		scanf("%d%d",&n,&q);
		init(n,q);
		int k = n;
		for(int i=1;i<=q;i++)
		{
			int op,x,y; scanf("%d",&op);
			if(op == 1)
			{
				scanf("%d%d",&x,&y);
				if(rt[y] == -1) continue;
				if(rt[x] == -1)
				{
					rt[x] = rt[y];
					box_id[rt[x]] = x;
					rt[y] = -1;
				}
				else
				{
					pa[rt[y]] = rt[x];
					rt[y] = -1;
				}
			}
			else if(op == 2)
			{
				k++;
				scanf("%d",&x);
				if(rt[x] == -1)
				{
					rt[x] = k;
					box_id[k] = x;
				}
				else
				{
					pa[rt[x]] = k;
					rt[x] = k;
					box_id[k] = x;
				}
			}
			else if(op == 3)
			{
				scanf("%d",&x);
				printf("%d\n",box_id[find(x)]);
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
