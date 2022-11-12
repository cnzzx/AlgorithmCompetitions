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
	int n,m;
	LL mod[MAXN];
	LL sum[MAXN];
	bool check(int d,int f)
	{
		return (d*sum[f-1])%m == 0;
	}
	void work()
	{
		scanf("%d%d",&n,&m);
		mod[0] = 1%m;
		for(int i=1;i<=n;i++) mod[i] = mod[i-1]*10%m;
		sum[0] = mod[0];
		for(int i=1;i<=n;i++) sum[i] = (sum[i-1]+mod[i])%m;
		int bst_fig = -1, bst_d = -1;
		for(int fig=n;fig>=1 && bst_fig==-1;fig--)
		{
			for(int d=9;d>=1;d--)
			{
				if(check(d,fig))
				{
					bst_fig = fig;
					bst_d = d;
					break;
				}
			}
		}
		if(bst_fig == -1) printf("-1\n");
		else
		{
			for(int i=1;i<=bst_fig;i++) printf("%d",bst_d);
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
