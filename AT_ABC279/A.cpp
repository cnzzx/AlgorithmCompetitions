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
	char s[MAXN];
	void work()
	{
		int ans = 0;
		scanf("%s",s);
		for(int i=0;s[i];i++)
		{
			if(s[i] == 'v') ans += 1;
			else if(s[i] == 'w') ans += 2;
		}
		printf("%d\n",ans);
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
