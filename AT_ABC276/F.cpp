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
	const int MAXN = 200005;
	const int mo = 998244353;
	int rt,np,lc[MAXN<<1],rc[MAXN<<1];
	LL cnt[MAXN<<1],sumv[MAXN<<1];
	void init()
	{
		rt = np = 0;
		memset(lc,0,sizeof(lc));
		memset(rc,0,sizeof(rc));
		memset(cnt,0,sizeof(cnt));
		memset(sumv,0,sizeof(sumv));
		return;
	}
	void pushup(int now)
	{
		cnt[now] = (cnt[lc[now]] + cnt[rc[now]])%mo;
		sumv[now] = (sumv[lc[now]] + sumv[rc[now]])%mo;
		return;
	}
	void build(int &now,int l,int r)
	{
		if(!now) now = ++np;
		if(l == r){return;}
		int m = (l + r) >>1;
		build(lc[now],l,m);
		build(rc[now],m+1,r);
		pushup(now);
		return;
	}
	void upd(int now,int l,int r,int i,int d)
	{
		if(l == r && l == i)
		{
			cnt[now] += d;
			sumv[now] = (sumv[now] + (LL)d*l%mo)%mo;
			return;
		}
		int m = (l + r) >> 1;
		if(i <= m) upd(lc[now],l,m,i,d);
		else upd(rc[now],m+1,r,i,d);
		pushup(now);
		return;
	}
	LL qcnt(int now,int l,int r,int i,int j)
	{
		if(i <= l && r <= j) return cnt[now];
		int m = (l + r)>> 1;
		if(j <= m) return qcnt(lc[now],l,m,i,j);
		else if(i > m) return qcnt(rc[now],m+1,r,i,j);
		return (qcnt(lc[now],l,m,i,m) + qcnt(rc[now],m+1,r,m+1,j)) % mo;
	}
	LL qsum(int now,int l,int r,int i,int j)
	{
		if(i <= l && r <= j) return sumv[now];
		int m = (l + r )>> 1;
		if(j <=m ) return qsum(lc[now],l,m,i,j);
		else if(i > m) return qsum(rc[now],m+1,r,i,j);
		return (qsum(lc[now],l,m,i,m) + qsum(rc[now],m+1,r,m+1,j)) % mo;
	}
	int qkpow(int a,int k)
	{
		int ret = 1, tt = a;
		while(k)
		{
			if(k&1) ret = (LL)ret*tt%mo;
			tt = (LL)tt*tt%mo;
			k >>= 1;
		}
		return ret;
	}
	int rev(int x)
	{
		return qkpow(x, mo-2);
	}
	int n,a[MAXN],f[MAXN];
	void work()
	{
		init();
		build(rt,1,200000);
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		f[1] = a[1];
		upd(rt,1,200000,a[1],1);
		for(int i=2;i<=n;i++)
		{
			f[i] = (LL)f[i-1]*(i-1)%mo*(i-1)%mo*rev(i)%mo*rev(i)%mo;
			int temp = 0;
			if(a[i] > 1) temp = (temp + (LL)qcnt(rt,1,200000,1,a[i]-1) * a[i]%mo) %mo;
			if(a[i] <= 200000) temp = (qsum(rt,1,200000,a[i],200000) + temp)%mo;
			temp = (temp * 2) % mo;
			temp = (temp + a[i]) % mo;
			upd(rt,1,200000,a[i],1);
			f[i] = (f[i] + (LL)temp*rev(i)%mo*rev(i)%mo)%mo;
		}
		for(int i=1;i<=n;i++) printf("%d\n",f[i]);
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
