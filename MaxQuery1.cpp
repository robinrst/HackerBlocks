#include "bits/stdc++.h"

using namespace std;

#define  f first
#define  lgn 25
#define  endl '\n'
#define  sc second
#define  N (int)2e5+5
#define  sz(x) x.size()
#define  int long long int
#define  ld long double
#define  vi vector<int>
#define  vs vector<string>
#define  vc vector<char>
#define  mii map<int,int>
#define  pii pair<int,int>
#define  vpii vector<pii>
#define  test(x) while(x--)
#define  pb push_back
#define  eb emplace_back
#define  pq priority_queue
#define  mod 1000000007
#define  fo(i,a,n) for(int i=a;i<n;i++)
#define  rfo(i,n,a) for(int i=n;i>=a;i--)
#define  mst(a,v,n) fo(i,0,n) a[i]=v
#define  all(x) begin(x),end(x)
#define  allr(x) rbegin(x),rend(x)
#define  rev(x) reverse(begin(x),end(x))
#define  db(x) cout<<#x <<" : "<< x <<endl;
#define time() cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n"

const int inf = 0x3f3f3f3f;
const int INF = 0x3f3f3f3f3f3f3f3f;

int n,m,k,q;
vi adj[N];
int vis[N],par[N],a[N];

vi segTree[4*N];
 
void build (int v=1, int tl=0, int tr=n-1) {
	if (tl == tr)
		segTree[v] = vi (1, a[tl]);
	else {
		int tm = (tl + tr) / 2;
		build (v*2, tl, tm);
		build (v*2+1, tm+1, tr);
		merge (segTree[v*2].begin(), segTree[v*2].end(), segTree[v*2+1].begin(), segTree[v*2+1].end(),
			back_inserter (segTree[v]));
	}
}

int query (int v, int tl, int tr, int l, int r, int x) {
	if (l > r)
		return 0;
	if (l == tl && tr == r) {
		auto pos = lower_bound (begin(segTree[v]), end(segTree[v]), x);
		if (pos != segTree[v].end())
			return segTree[v].size() - (pos - begin(segTree[v]));
		return 0;
	}
	int tm = (tl + tr) / 2;
	return  
		query (v*2, tl, tm, l, min(r,tm), x) + query (v*2+1, tm+1, tr, max(l,tm+1), r, x);
}


void go()
{
	cin>>n;
	fo(i,0,n) cin>>a[i];

	build();

	cin>>q;

	while( q-- )
	{
		int l ,r ,x;
		cin>>l>>r>>x;
		--r,--l;
		cout <<query(1,0,n-1,l,r,x) << endl;
	}
}

int32_t main()
{	
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t=1; 
	// cin>>t;
	test(t) go();
}