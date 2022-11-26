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
	const int MAXN = 105;
	char buf[MAXN][MAXN];
	int n,a[MAXN][MAXN],s[MAXN][MAXN],res[MAXN];
	int rd[MAXN],q[MAXN],front,rear;
	void work()
	{
		int tst;scanf("%d",&tst);
		while(tst--)
		{
			scanf("%d",&n);
			for(int i=0;i<n;i++) scanf("%s",buf[i]);
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					a[i+1][j+1] = (buf[i][j] == '1');
			for(int i=1;i<=n;i++) rd[i] = 0;
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					if(a[i][j]) rd[j]++;
			for(int i=1;i<=n;i++) res[i] = n;
			front = rear = 0;
			int temp = 0;
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					s[i][j] = 0;
			for(int i=1;i<=n;i++)
			{
				if(rd[i] == 0) s[i][++temp] = 1;
				q[rear++] = i;
			}
			while(rear-front)
			{
				int i=q[front++];
				for(int j=1;j<=n;j++)
				{
					if(!a[i][j]) continue;
					rd[j]--;
					for(int k=1;k<=n;k++)
					{
						if(a[k][j])
						{
							for(int u=1;u<=n;u++)
							{
								s[j][u] = s[j][u] | s[k][u];
							}
						}
					}
					if(rd[j] == 0)
					{
						bool ok = true;
						for(int k=1;k<=n;k++)
						{
							if(a[k][j])
							{
								bool temp = true;
								for(int u=1;u<=n;u++)
								{
									if(s[j][u] != s[k][u])
									{
										temp = false;
										break;
									}
								}
								if(temp){
									ok = false;
									break;
								}
							}
						}
						if(!ok)
						{
							s[j][res[i]--] = 1;
						}
						q[rear++] = j;
					}
				}
				if(res[i] < temp)
				{
					int ccccc = 0;
					while(true) ccccc++;
					printf("%d\n",ccccc);
				}
				for(int j=1;j<=n;j++)
				{
					if(!a[i][j]) continue;
					res[j] = res[i];
				}
			}
			for(int i=1;i<=n;i++)
			{
				int cnt = 0;
				for(int j=1;j<=n;j++)
					if(s[i][j]) cnt++;
				printf("%d ",cnt);
				for(int j=1;j<=n;j++)
					if(s[i][j]) printf("%d ",j);
				printf("\n");
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
