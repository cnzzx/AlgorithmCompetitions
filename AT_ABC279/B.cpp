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
	char s[MAXN], t[MAXN];
	void work()
	{
		scanf("%s%s",s,t);
		int n = strlen(s);
		int m = strlen(t);
		bool fd = false;
		for(int i=0;i<n-m+1;i++)
		{
			bool ok = true;
			for(int j=0;j<m;j++)
				if(s[i+j]!=t[j]) ok = false;
			if(ok) fd = true;
		}
		if(fd) printf("Yes\n");
		else printf("No\n");
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
