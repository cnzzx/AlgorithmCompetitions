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
	typedef long long LL;
	LL mod[100];
	int va[100], vb[100];
	LL a,b,d;	
	void extend_gcd(LL a, LL b, LL &x, LL &y){
	    if(b == 0){
	        x = 1, y = 0;
	        return;
	    }
	    extend_gcd(b, a % b, x, y);
	    LL tmp = x;
	    x = y;
	    y = tmp - (a / b) * y;
	}
	LL mod_inverse(LL a, LL mod){
	    LL x, y;
	    extend_gcd(a, mod, x, y);
	    return (x + mod % mod) % mod;
	}
	void work()
	{
		int tst; scanf("%d",&tst);
		while(tst--)
		{
			scanf("%lld%lld%lld",&a,&b,&d);
			mod[0] = 1;
			for(int i=1;i<=61;i++)
				mod[i] = mod[i-1]*2%d;
			LL ba = a%d, bb = b%d;
			if(ba == 0 && bb == 0)
			{
				printf("0\n");
				continue;
			}
			if(d%2 == 0)
			{
				printf("-1\n");
				continue;
			}
			LL x = mod_inverse(mod[30], d);
			x = ((x - 1)%d + d)%d;
			LL ans = (1<<30)-1 + (x<<30);
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
