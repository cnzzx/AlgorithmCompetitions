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
	const int MAXN = 300005;
	char s[MAXN];
	int n;
	int cnt[MAXN][26];
	int temp[MAXN][26];
	int wow[26];
	int stk[MAXN],top;
	void work()
	{
		scanf("%s",s+1);
		n = strlen(s+1);
		memset(temp,0,sizeof(temp));
		for(int c=0;c<26;c++) temp[0][c] = 0;
		for(int i=1;i<=n;i++)
		{
			for(int c=0;c<26;c++) temp[i][c] = temp[i-1][c];
			if(s[i] != '(' && s[i] != ')') temp[i][s[i]-'a']++;
		}
		top = 0;
		for(int i=1;i<=n;i++)
		{
			if(s[i] == '(') stk[++top] = i;
			else if(s[i] == ')')
			{
				int r = stk[top--];
				for(int c=0;c<26;c++)
					cnt[i][c] = temp[i][c] - temp[r][c];
			}
		}
		bool ok = true;
		memset(wow,0,sizeof(wow));
		for(int i=1;i<=n && ok;i++)
		{
			if(s[i] == '(') continue;
			if(s[i] == ')')
			{
				for(int c=0;c<26;c++)
				{
					wow[c] -= cnt[i][c];
					if(wow[c] < 0) wow[c] = 0;
				}
			}
			else
			{
				if(wow[s[i]-'a']) ok = false;
				else wow[s[i]-'a']++;
			}
		}
		if(ok) printf("Yes\n");
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
