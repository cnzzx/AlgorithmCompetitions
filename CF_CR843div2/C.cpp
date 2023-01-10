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
	typedef unsigned long long LL;
	LL n,x;
	LL p[100], m[100];
	LL figs[100], tot, cnt;
	void work()
	{
		int tst; scanf("%d",&tst);
		while(tst--)
		{
			cin >> n >> x;
			tot = 0;
			LL nn = n;
			while(nn)
			{
				figs[tot++] = nn & 1;
				nn >>= 1;
			}
			if(tot == 0) figs[tot++] = 0;
			figs[tot++] = 0;  // wow
			
			cnt = 0;
			p[++cnt] = n;
			m[cnt] = n;
			for(int k=0;k<tot;k++)
			{
				if(!figs[k])
				{
					p[++cnt] = 0;
					m[cnt] = 1LL << k;
					for(int s=k+1;s<tot;s++)
					{
						if(figs[s])
						{
							p[cnt] += 1LL << s;
							m[cnt] += 1LL << s;
						}
					}
				}
			}
			bool ok = false;
			for(int i=1;i<=cnt;i++)
			{
				if(x == p[i])
				{
					cout << m[i] << endl;
					ok = true;
					break;
				}
			}
			if(!ok) printf("-1\n");
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
