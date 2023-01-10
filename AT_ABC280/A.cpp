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
	char s[20][20];
	int n,m;
	void work()
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++) scanf("%s",s[i]);
		int ans = 0;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(s[i][j] == '#') ans++;
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
