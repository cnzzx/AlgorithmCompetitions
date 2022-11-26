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
	const int MAXN = 105;
	int n,a[MAXN];
	void work()
	{
		int tst;scanf("%d",&tst);
		while(tst--)
		{
			scanf("%d",&n);
			for(int i=1;i<=n;i++) scanf("%d",&a[i]);
			a[0] = a[n], a[n+1] = a[1];
			bool ok = true;
			for(int i=1;i<=n;i++)
				if(a[i-1] != a[i+1]) ok = false;
			if(ok) printf("%d\n",n/2+1);
			else printf("%d\n",n);
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
