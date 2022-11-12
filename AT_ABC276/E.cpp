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
	const int dx[4] = {0, 0, 1, -1};
	const int dy[4] = {1, -1, 0, 0};
	char s[MAXN];
	int n,m,sx,sy;
	int get_x(int id)
	{
		return id/m;
	}
	int get_y(int id)
	{
		return id%m;
	}
	int get_id(int x,int y)
	{
		return x*m+y;
	}
	char get_ele(int x,int y)
	{
		return s[x*m+y];
	}
	int front,rear,q[MAXN],bel[MAXN],cc;
	bool vis[MAXN];
	bool bfs()
	{
		front = rear = 0;
		cc = 0;
		memset(bel,0,sizeof(bel));
		memset(vis,false,sizeof(vis));
		vis[get_id(sx,sy)] = true;
		for(int k=0;k<4;k++)
		{
			int nx = sx + dx[k];
			int ny = sy + dy[k];
			if(nx < 0 || nx >= n) continue;
			if(ny < 0 || ny >= m) continue;
			if(get_ele(nx, ny) == '#') continue;
			bel[get_id(nx,ny)] = ++cc;
			q[rear++] = get_id(nx,ny);
			vis[get_id(nx,ny)] = true;
		}
		while(front-rear)
		{
			int id = q[front++];
			//  printf("%d %d\n",get_x(id), get_y(id));
			for(int k=0;k<4;k++)
			{
				int nx = get_x(id) + dx[k];
				int ny = get_y(id) + dy[k];
				if(nx < 0 || nx >= n) continue;
				if(ny < 0 || ny >= m) continue;
				if(get_ele(nx,ny) == '#') continue;
				if(bel[get_id(nx,ny)] != 0 && bel[get_id(nx, ny)] != bel[id])
				{
					return true;
				}
				if(vis[get_id(nx,ny)]) continue;
				vis[get_id(nx,ny)] = true;
				bel[get_id(nx,ny)] = bel[id];
				q[rear++] = get_id(nx, ny);
			}
		}
		return false;
	}
	void work()
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
			scanf("%s",s+i*m);
		for(int i=0;i<n*m;i++)
			if(s[i] == 'S'){sx = get_x(i), sy = get_y(i);}
		if(bfs()) printf("Yes\n");
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
