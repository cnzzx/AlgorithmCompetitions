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
	const int MAXN = 15;
	int n = 8;
	char brd[MAXN][MAXN];
	void work()
	{
		int tst; scanf("%d",&tst);
		while(tst--)
		{
			for(int i=0;i<n;i++) scanf("%s",brd[i]);
			char ans = '?';
			for(int i=0;i<n && ans=='?';i++)
			{
				int cnt = 0;
				for(int j=0;j<n;j++)
					if(brd[i][j] == 'R') cnt++;
				if(cnt == 8) ans = 'R';
			}
			for(int j=0;j<n && ans=='?';j++)
			{
				int cnt = 0;
				for(int i=0;i<n;i++)
					if(brd[i][j] == 'B') cnt++;
				if(cnt == 8) ans = 'B';
			}
			printf("%c\n",ans);
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
