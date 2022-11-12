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
	const int MAXN = 1000005;
	inline LL mymin(LL a,LL b){return a<b?a:b;}
	LL p[2],t[2];
	LL h,s;
	LL f[5005]; 
	void work()
	{
		scanf("%lld%lld",&p[0],&t[0]);
		scanf("%lld%lld",&p[1],&t[1]);
		scanf("%lld%lld",&h,&s);
		f[0] = 0;
		for(int i=1;i<=h;i++)
		{
			f[i] = ((i-1)/(p[0]-s)+1)*t[0]; // inf
			for(int tp=0;tp<2;tp++)
			{
				if(p[tp]-s >= i) f[i] = mymin(f[i], t[tp]);
				for(int j=1;j*(p[tp]-s)<=h;j++)
				{
					if(j*t[tp] < t[!tp])
					{
						LL shot = j*(p[tp]-s);
						if(shot > i) f[i] = mymin(f[i], j*t[tp]);
						else f[i] = mymin(f[i], f[i-shot]+j*t[tp]);
					}
					else
					{
						LL shot = (j*t[tp]/t[!tp]-1)*(p[!tp]-s)+j*(p[tp]-s)+p[!tp];
						if(shot > i) f[i] = mymin(f[i], j*t[tp]);
						else f[i] = mymin(f[i], f[i-shot]+j*t[tp]);
					}
				}
			}
		}
		printf("%lld\n",f[h]);
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
