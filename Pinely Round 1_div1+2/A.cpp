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
	int n,a,b;
	void work()
	{
		int tst;scanf("%d",&tst);
		while(tst--)
		{
			scanf("%d%d%d",&n,&a,&b);
			if(a + b < n-1) printf("Yes\n");
			else if(a == b && a == n) printf("Yes\n");
			else printf("No\n");
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

