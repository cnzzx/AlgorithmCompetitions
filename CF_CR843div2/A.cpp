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
	int n; char s[MAXN];
	void work()
	{
		int tst; scanf("%d",&tst);
		while(tst--)
		{
			scanf("%s",s); n = strlen(s);
			int fir_a = -1, fir_b = -1, na = 0, nb = 0;
			for(int i=1;i<n;i++)
			{
				if(s[i] == 'a')
				{
					if(fir_a == -1) fir_a = i;
					na++;
				}
				if(s[i] == 'b')
				{
					if(fir_b == -1) fir_b = i;
					nb++;
				}
			}
			if(s[0] == 'a')
			{
				if(na == 0 || nb == 0)
				{
					printf("%c ", s[0]);
					for(int i=1;i<n-1;i++) printf("%c", s[i]);
					printf(" %c\n", s[n-1]);
				}
				else if(fir_a < fir_b)
				{
					printf("%c ", s[0]);
					printf("%c ", s[1]);
					for(int i=2;i<n;i++) printf("%c", s[i]);
					printf("\n");
				}
				else
				{
					printf("%c ", s[0]);
					for(int i=1;i<fir_a;i++) printf("%c", s[i]); printf(" ");
					for(int i=fir_a;i<n;i++) printf("%c", s[i]); printf("\n");
				}
			}
			else
			{
				if(na == 0)
				{
					printf("%c ", s[0]);
					for(int i=1;i<n-1;i++) printf("%c", s[i]);
					printf(" %c\n", s[n-1]);
				}
				else if(nb == 0)
				{
					printf("%c ", s[0]);
					printf("%c ", s[1]);
					for(int i=2;i<n;i++) printf("%c", s[i]);
					printf("\n");
				}
				else if(fir_a < fir_b)
				{
					printf("%c ", s[0]);
					for(int i=1;i<fir_b;i++) printf("%c", s[i]); printf(" ");
					for(int i=fir_b;i<n;i++) printf("%c", s[i]); printf("\n");
				}
				else
				{
					printf("%c ", s[0]);
					for(int i=1;i<fir_a;i++) printf("%c", s[i]); printf(" ");
					for(int i=fir_a;i<n;i++) printf("%c", s[i]); printf("\n");
				}
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
