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
	const int MAXN = 500005;
	int n; char s[MAXN],t[MAXN];
	void work()
	{
		scanf("%s%s",s,t);
		n = strlen(s);
		int pos = n+1;
		for(int i=0;i<n;i++)
		{
			if(s[i] != t[i])
			{
				pos = i+1;
				break;
			}
		}
		printf("%d\n",pos);
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
