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
	const int MAXN = 100005;
	char s[MAXN];
	void work()
	{
		scanf("%s",s);
		int n = strlen(s);
		int ans = 0,cnt = 0;
		for(int i=0;i<n;i++)
		{
			if(s[i] != '0')
			{
				if(cnt)
				{
					ans += (cnt-1)/2 + 1;
					cnt = 0;
				}
				ans++;
			}
			else if(s[i] == '0')
			{
				cnt++;
			}
		}
		if(cnt!=0) ans += (cnt-1)/2 + 1;
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
