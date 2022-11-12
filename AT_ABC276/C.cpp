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
	const int MAXN = 1005;
	int a[MAXN];
	void work()
	{
		int n;
		scanf("%d", &n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		prev_permutation(a+1, a+n+1);
		for(int i=1;i<=n;i++) printf("%d ",a[i]);
		printf("\n");
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
