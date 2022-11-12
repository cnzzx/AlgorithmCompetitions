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
	int n;
	LL a[MAXN]; int b[MAXN];
	bool vis[MAXN];
	LL bits = 0; 
	void work()
	{
		int tst; scanf("%d",&tst);
		while(tst--)
		{
			bits = 0;
			scanf("%d",&n);
			for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
			for(int i=1;i<=n;i++) vis[i] = false;
			
			// find the answer
			for(int tsts=1;tsts<=32;tsts++)
			{
				for(int i=1;i<=n;i++) b[i] = a[i] & (~bits);
				int mx_id = -1; LL maxv = 0;
				for(int i=1;i<=n;i++)
				{
					if(vis[i]) continue;
					if(b[i] > maxv) maxv = b[i], mx_id = i;
				}
				if(mx_id == -1) break;
				printf("%lld ",a[mx_id]);
				vis[mx_id] = true;
				bits |= a[mx_id];
			}
			for(int i=1;i<=n;i++)
			{
				if(vis[i]) continue;
				printf("%lld ",a[i]);
			}
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
