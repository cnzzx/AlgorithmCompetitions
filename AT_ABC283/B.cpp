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
	const int MAXN = 100005;
	int n,q,a[MAXN];
	void work()
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		scanf("%d",&q);
		for(int i=1;i<=q;i++)
		{
			int op,k,x;
			scanf("%d%d",&op,&k);
			if(op == 1)
			{
				scanf("%d",&x);
				a[k] = x;
			}
			else if(op == 2)
			{
				printf("%d\n",a[k]);
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
