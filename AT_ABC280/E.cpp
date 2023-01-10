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
	const int mo = 998244353;
	typedef long long LL;
	LL qkpow(LL a,LL k)
	{
		LL ret = 1, tt = a;
		while(k)
		{
			if(k&1) ret = ret * tt %mo;
			tt = tt * tt%mo;
			k >>= 1;
		}
		return ret;
	}
	LL inv(LL x)
	{
		return qkpow(x,mo-2);
	}
	LL f[MAXN];
	LL n,p;
	void work()
	{
		scanf("%lld%lld",&n,&p);
		f[0] = 0;
		for(int i=1;i<=n;i++)
		{
			f[i] = 0;
			if(i >= 2) f[i] = (f[i] + (f[i-2]+1)%mo*p%mo*inv(100)%mo)%mo;
			else f[i] = (f[i] + (f[0]+1)%mo*p%mo*inv(100)%mo)%mo;
			f[i] = (f[i] + (f[i-1]+1)%mo*(100-p)%mo*inv(100)%mo)%mo;
		}
		printf("%lld\n", f[n]);
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
