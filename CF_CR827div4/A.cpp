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
	void work()
	{
		int tst; scanf("%d",&tst);
		while(tst--)
		{
			int a, b, c;
			scanf("%d%d%d",&a,&b,&c);
			if(a == b + c) printf("YES\n");
			else if(b == a + c) printf("YES\n");
			else if(c == a + b) printf("YES\n");
			else printf("NO\n");
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
