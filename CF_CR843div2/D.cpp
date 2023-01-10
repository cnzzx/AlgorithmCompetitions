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
	bool isp[MAXN];
	int pri[MAXN], tot, rpri[MAXN];
	struct data
	{
		int id, val;
		data(int a=0,int b=0):
			id(a),val(b){}
	};
	vector<data>g[MAXN];
	int tmp[MAXN], wow;
	void sieve(int lim)
	{
		tot = 0;
		memset(isp,true,sizeof(isp));
		isp[0] = isp[1] = false;
		for(int i=2;i<=lim;i++)
		{
			if(isp[i])
			{
				pri[++tot] = i;
				rpri[i] = tot;
			}
			for(int k=1;k<=tot && (LL)i*pri[k] <= lim;k++)
			{
				isp[i*pri[k]] = false;
				if(i%pri[k] == 0) break;
			}
		}
		return;
	}
	int n,a[MAXN],s,t;
	vector<int>s_p;
	vector<int>t_p;
	vector<int>::iterator it;
	vector<data>::iterator tit;
	int dist[MAXN];
	int q[MAXN],front,rear,fa[MAXN],faw[MAXN];
	void bfs()
	{
		memset(fa,-1,sizeof(fa));
		memset(faw,-1,sizeof(faw));
		memset(dist, -1, sizeof(dist));
		front = rear = 0;
		for(it=s_p.begin();it!=s_p.end();it++)
			q[rear++] = *it, dist[*it] = 1;
		while(rear-front)
		{
			int i = q[front++];
			for(tit=g[i].begin();tit!=g[i].end();tit++)
			{
				if(dist[tit->id]!=-1) continue;
				dist[tit->id] = dist[i] + 1;
				fa[tit->id] = i;
				faw[tit->id] = tit->val;
				q[rear++] = tit->id;
			}
		}
		return;
	}
	void work()
	{
		sieve(300000);
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		scanf("%d%d",&s,&t);
		if(s == t)
		{
			printf("1\n");
			printf("%d\n",s);
			return;
		}
		for(int i=1;i<=n;i++)
		{
			wow = 0;
			int x = a[i];
			int m = (int)sqrt(x+0.5);
			for(int k=1;k<=tot && pri[k]<=m;k++)
			{
				if(x%pri[k] == 0) tmp[++wow] = k;
				while(x%pri[k] == 0)
				{
					x /= pri[k];
				}
			}
			if(x > 1) tmp[++wow] = rpri[x];
			for(int u=1;u<=wow;u++)
			{
				for(int v=u+1;v<=wow;v++)
				{
					g[tmp[u]].push_back(data(tmp[v], i));
					g[tmp[v]].push_back(data(tmp[u], i));
				}
			}
			if(i == s)
				for(int k=1;k<=wow;k++) s_p.push_back(tmp[k]);
			else if(i == t)
				for(int k=1;k<=wow;k++) t_p.push_back(tmp[k]);
		}
		bfs();
		int bst = -1, bst_ed = -1;
		for(it=t_p.begin();it!=t_p.end();it++)
		{
			if(dist[*it] == -1) continue;
			if(bst_ed == -1)
			{
				bst_ed = *it;
				bst = dist[*it];
			}
			else if(dist[*it] < bst)
			{
				bst = dist[*it];
				bst_ed = *it;
			}
		}
		if(bst_ed == -1) printf("-1\n");
		else
		{
			wow = 0;
			int cur = bst_ed;
			while(cur != -1)
			{
				if(fa[cur] == -1) break;
				tmp[++wow] = faw[cur];
				cur = fa[cur];
			}
			printf("%d\n",wow+2);
			printf("%d ",s);
			for(int i=wow;i>=1;i--)
			{
				printf("%d ",tmp[i]);
			}
			printf("%d\n",t);
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
