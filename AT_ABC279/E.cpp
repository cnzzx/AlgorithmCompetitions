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
	const int MAXN = 200005;
	int n,m,a[MAXN],b[MAXN];
	int pos[MAXN],rpos[MAXN];
	void work()
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++) b[i] = i;
		for(int i=1;i<=n;i++) pos[i] = i;
		for(int i=1;i<=m;i++) swap(pos[a[i]], pos[a[i]+1]);
		for(int i=1;i<=n;i++) rpos[pos[i]] = i;
		int cur = 1;
		for(int i=1;i<=m;i++)
		{
			swap(rpos[a[i]], rpos[a[i]+1]);
			printf("%d\n",b[rpos[cur]]);
			if(a[i] == cur) cur++;
			else if(a[i]+1 == cur) cur--;
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
