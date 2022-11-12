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
	const int mo = 998244353;
	typedef long long LL;
	const int MAXN = 10000005;
	int f[MAXN][3],a[3];
	int n,m;
	void work()
	{
		scanf("%d%d",&n,&m);
		a[0] = m/3+1;
		a[1] = m/3;
		a[2] = m/3;
		if(m%3 == 1) a[1]++;
		if(m%3 == 2) a[1]++, a[2]++;
		for(int t=0;t<=2;t++) f[1][t] = a[t];
		for(int i=2;i<=n;i++)
		{
			f[i][0] = (f[i-1][1]+f[i-1][2])%mo*(LL)a[0]%mo;
			f[i][1] = (f[i-1][0]+f[i-1][2])%mo*(LL)a[1]%mo;
			f[i][2] = (f[i-1][0]+f[i-1][1])%mo*(LL)a[2]%mo;
		}
		printf("%d\n",((f[n][0]+f[n][1])%mo+f[n][2])%mo);
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
