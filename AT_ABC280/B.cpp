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
	int n,s[20];
	void work()
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&s[i]);
		s[0] = 0;
		for(int i=1;i<=n;i++)
			printf("%d ",s[i]-s[i-1]);
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
