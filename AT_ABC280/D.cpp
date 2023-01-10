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
	const int MAXN = 500005;
	typedef long long LL;
	LL find_up(LL p,LL e)
	{
		LL tot = 0;
		for(LL i=1;i<=e;i++)
		{
			LL xx = i;
			while(xx%p == 0) tot++, xx/=p;
			tot++;
			if(tot >= e) return i*p;
		}
		return e*p;
	}
	LL find_ans(LL x)
	{
		LL ret = 0;
		LL m = (LL)sqrt(x+0.5);
		for(LL i=2;i<=m;i++)
		{
			if(x%i == 0)
			{
				LL e = 0;
				while(x%i == 0) x/=i, e++;
				LL tt = find_up(i,e);
				ret = tt > ret ? tt : ret;
			}
		}
		if(x > 1) ret = x > ret ? x : ret;
		return ret;
	}
	LL n; 
	void work()
	{
		while(scanf("%lld",&n)!=EOF)
		{
			LL ans = find_ans(n);
			printf("%lld\n",ans);
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
