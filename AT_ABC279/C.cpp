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
	const int MAXN = 400005;
	char s[MAXN], t[MAXN], a[MAXN];
	int n,m,ps[MAXN],pt[MAXN];
	bool mycmp(int i, int j)
	{
		for(int k=0;k<n;k++)
			if(a[k*m+i] != a[k*m+j])
				return a[k*m+i] < a[k*m+j];
		return false;
	}
	void mysort(char *src_a, int *p)
	{
		for(int i=0;i<n*m;i++) a[i] = src_a[i];
		for(int i=0;i<m;i++) p[i] = i;
		sort(p,p+m,mycmp);
		return;
	}
	void work()
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++) scanf("%s",s+i*m);
		for(int i=0;i<n;i++) scanf("%s",t+i*m);
		mysort(s,ps);
		mysort(t,pt);
		bool ok = true;
		for(int j=0;j<m;j++)
		{
			bool jd = true;
			for(int i=0;i<n;i++)
				if(s[i*m+ps[j]] != t[i*m+pt[j]]) jd = false;
			if(!jd) ok = false;
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
