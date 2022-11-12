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
	const int MAXN = 1000005;
	int n,nn; char s[MAXN];
	int a[MAXN],t[MAXN],bst[MAXN];
	bool cmp()
	{
		for(int i=1;i<=n;i++)
		{
			if(bst[i] != t[i]) return bst[i] < t[i];
		}
		return false;
	}
	void work()
	{
		scanf("%d",&nn);
		scanf("%s",s);
		n = 0; bool one_start = false;
		for(int i=0;i<nn;i++)
		{
			if(s[i] == '1') one_start = true;
			if(one_start) a[++n] = s[i]-'0';
		}
		if(n == 0)
		{
			printf("0\n");
			return;
		}
		int first_zero = 0;
		for(int i=1;i<=n;i++)
		{
			if(!a[i])
			{
				first_zero = i;
				break;
			}
		}
		for(int i=1;i<=n;i++) bst[i] = a[i];
		for(int i=1;i<first_zero;i++)
		{
			for(int len=n-first_zero+1;len<=n-i+1;len++)
			{
				for(int k=1;k<=n;k++) t[k] = a[k];
				for(int k=1;k<=len;k++)
				{
					t[n-(len-k+1)+1] = t[n-(len-k+1)+1] | a[i+k-1];
				}
				if(cmp())
				{
					for(int j=1;j<=n;j++) bst[j] = t[j];
				}
			}
		}
		for(int i=1;i<=n;i++) printf("%d",bst[i]);
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
