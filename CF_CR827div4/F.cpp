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
	const int MAXN = 500005;
	int q;
	LL cnt[3][30];
	char buf[MAXN];
	bool check()
	{
		for(int i=1;i<26;i++)
			if(cnt[2][i]) return true;
		bool is_all_a = true;
		for(int i=1;i<26;i++)
			if(cnt[1][i]) is_all_a = false;
		if(is_all_a)
		{
			return cnt[1][0] < cnt[2][0];
		}
		else
		{
			return false;
		}
		return false;
	}
	void work()
	{
		int tst; scanf("%d",&tst);
		while(tst--)
		{
			memset(cnt,0,sizeof(cnt));
			cnt[1][0] = cnt[2][0] = 1;
			scanf("%d",&q);
			for(int tsts=1;tsts<=q;tsts++)
			{
				int d,k;
				scanf("%d%d%s",&d,&k,buf);
				for(int i=0;buf[i];i++) cnt[d][buf[i]-'a']+=k;
				if(check()) printf("YES\n");
				else printf("NO\n");
			}
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
