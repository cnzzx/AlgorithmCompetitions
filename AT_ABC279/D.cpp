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
	const int MAXN = 400005;
	typedef long long LL;
	LL A,B;
	double f(double x)
	{
		return A / sqrt(1 + x) + B * x;
	}
	void work()
	{
		scanf("%lld%lld",&A,&B);
		LL low = 0, upp = 1e+12, ml = 0, mr = 0;
		double ans = f(low);
		ans = min(ans, f(upp));
		while(low <= upp)
		{
			ml = low + (upp - low) / 3;
			mr = upp - (upp - low) / 3;
			double fl = f(ml), fr = f(mr);
			ans = min(ans, fl);
			ans = min(ans, fr);
			if(fl <= fr) upp = mr-1;
			else low = ml+1;
		}
		printf("%.15lf\n",ans);
//		printf("%.15lf\n",2+10/sqrt(3));
//		double ans = 2.0 * B / A;
//		ans = pow(ans, - 1 / 3.0) * pow(ans, - 1 / 3.0) - 1;
//		ans = A / sqrt(1 + ans) + B * ans;
//		printf("%.15lf\n",ans);
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
