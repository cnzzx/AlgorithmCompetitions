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
	const int MAXN = 2000005;
	inline int mymin(int a,int b){return a<b?a:b;}
	bool isp[MAXN];
	int pri[MAXN],cnt;
	void sieve(int lim)
	{
		memset(isp,true,sizeof(isp));
		cnt = 0;
		isp[0] = isp[2] = false;
		for(int i=2;i<=lim;i++)
		{
			if(isp[i]) pri[++cnt] = i;
			for(int k=1;k<=cnt && i*pri[k]<=lim;k++)
			{
				isp[i*pri[k]] = false;
				if(i%pri[k] == 0) break;
			}
		}
		return;
	}
	int n;
	int pos_e[MAXN], pos_o[MAXN];
	bool vis[MAXN];
	int ans[1005][1005];
	const int dx[4] = {1,-1,0,0};
	const int dy[4] = {0,0,1,-1};
	bool search(int i)
	{
		if(i > 9)
		{
			for(int x=1;x<=3;x++)
			{
				for(int y=1;y<=3;y++)
				{
					for(int k=0;k<4;k++)
					{
						int nx = x + dx[k];
						int ny = y + dy[k];
						if(nx < 1 || nx > 3) continue;
						if(ny < 1 || ny > 3) continue;
						if(isp[ans[x][y] + ans[nx][ny]]) return false;
					}
				}
			}
			return true;
		}
		for(int k=1;k<=9;k++)
		{
			if(vis[k]) continue;
			vis[k] = true;
			ans[(i-1)/3+1][(i-1)%3+1] = k;
			if(search(i+1)) return true;
			ans[(i-1)/3+1][(i-1)%3+1] = -1;
			vis[k] = false;
		}
		return false;
	}
	void work()
	{
		sieve(2000000);
		scanf("%d",&n);
		memset(ans,-1,sizeof(ans));
		if(n == 3)
		{
			memset(vis,false,sizeof(vis));
			search(1);
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
					printf("%d ",ans[i][j]);
				printf("\n");
			}
		}
		else if(n&1)
		{
			int k = mymin(n, n);
			int total = 0;
			memset(vis,false,sizeof(vis));
			vis[2] = vis[4] = vis[7] = vis[23] = true;
			for(int i=1;i<=n*k && total<n-2;i++)
			{
				if(i&1) continue;
				if(vis[i]) continue;
				for(int j=1;j<=n*k && total<n-2;j++)
				{
					if(!(j&1)) continue;
					if(vis[j] || isp[i+j]) continue;
					vis[i] = vis[j] = true;
					total++;
					pos_e[total] = i;
					pos_o[total] = j;
					break;
				}
			}
			//printf("%d %d\n",n,total);
			for(int i=1;i<=total;i++)
			{
				ans[i][(n-1)/2+1] = pos_o[i];
				ans[i][(n-1)/2+2] = pos_e[i];
			}
			ans[n-1][(n-1)/2+1] = 23;
			ans[n][(n-1)/2+1] = 2;
			ans[n-1][(n-1)/2+2] = 4;
			ans[n][(n-1)/2] = 7;
			int cur = 1;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=(n-1)/2;j++)
				{
					if(i==n && j==(n-1)/2) continue;
					while(vis[cur]) cur += 2;
					ans[i][j] = cur;
					cur += 2;
				}
			}
			cur = 2;
			for(int i=1;i<=n;i++)
			{
				for(int j=(n-1)/2+2;j<=n;j++)
				{
					if(i==n-1 && j==(n-1)/2+2) continue;
					while(vis[cur]) cur += 2;
					ans[i][j] = cur;
					cur += 2;
				}
			}
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
					printf("%d ",ans[i][j]);
				printf("\n");
			}
		}
		else
		{
			int k = mymin(n, n);
			int total = 0;
			memset(vis,false,sizeof(vis));
			for(int i=1;i<=n*k && total<n;i++)
			{
				if(i&1) continue;
				if(vis[i]) continue;
				for(int j=1;j<=n*k && total<n;j++)
				{
					if(!(j&1)) continue;
					if(vis[j] || isp[i+j]) continue;
					vis[i] = vis[j] = true;
					total++;
					pos_e[total] = i;
					pos_o[total] = j;
					break;
				}
			}
			for(int i=1;i<=n;i++)
			{
				ans[i][n>>1] = pos_e[i];
				ans[i][(n>>1)+1] = pos_o[i];
			}
			int cur = 2;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=(n>>1)-1;j++)
				{
					while(vis[cur]) cur += 2;
					ans[i][j] = cur;
					cur += 2;
				}
			}
			cur = 1;
			for(int i=1;i<=n;i++)
			{
				for(int j=(n>>1)+2;j<=n;j++)
				{
					while(vis[cur]) cur += 2;
					ans[i][j] = cur;
					cur += 2;
				}
			}
			//printf("%d %d\n",n,total);
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
					printf("%d ",ans[i][j]);
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
