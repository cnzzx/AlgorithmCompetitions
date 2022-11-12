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
	int n,a[1000];
	void work()
	{
		int tst; scanf("%d",&tst);
		while(tst--)
		{
			scanf("%d",&n);
			if(n & 1)
			{
				for(int i=1;i<=((n-1)>>1);i++)
				{
					a[i*2] = i+(((n-1)>>1)+1);
				}
				a[1] = 1;
				for(int i=2;i<=((n-1)>>1)+1;i++)
				{
					a[(i-1)*2+1] = ((n-1)>>1)+3-i;
				}
			}
			else
			{
				for(int i=1;i<=(n>>1);i++)
				{
					a[i*2] = i;
				}
				a[1] = (n>>1)+1;
				for(int i=1;i<=(n>>1);i++)
				{
					a[i*2+1] = n-i+1;
				}
			}
			for(int i=1;i<=n;i++) printf("%d ",a[i]);
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
