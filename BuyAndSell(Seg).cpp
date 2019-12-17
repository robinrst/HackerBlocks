#include        "bits/stdc++.h"
// #include        "bugg.h"
 
using namespace std;
 
#define          f first
#define          endl '\n'
#define          sc second
#define          N (int)2e5+5
#define          pb push_back
#define          PI acos(-1.0)
#define          int long long 
#define          mod 1000000007
#define          ld long double
#define          vi vector<int>
#define          eb emplace_back
#define          vpii vector<pii>
#define          mii map<int,int>
#define          pii pair<int,int>
#define          pq priority_queue
#define          test(x) while(x--)
#define          all(x) begin(x),end(x)
#define          allr(x) rbegin(x),rend(x)
#define          fo(i,a,n) for(int i=a;i<n;i++)
#define          rfo(i,n,a) for(int i=n;i>=a;i--)
#define          FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define          time() cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n"
 
inline void INP()
{
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);   
	    freopen("output.txt","w",stdout);
	#endif 
}
 
const int inf = 0x3f3f3f3f;
const int INF = 0x3f3f3f3f3f3f3f3f;
 
int n,m,k,q;
string s;
vi adj[N];
int vis[N],pre[N],a[N];
 
 
 
struct SegmentTree
{
	vi segTree ;
 
	void init()
	{
		segTree.resize(4*n + 10);
	}
 
	int combine( int i , int j )
	{
		return ( segTree[ i ] + segTree[ j ] );
	}
 
	void build(int v = 1, int tl = 0 , int tr = n-1)
	{
	    if(tl == tr )
	    {
	        segTree[v] = a[tl];
	        return;
	    }
 
	     int tm = (tl+tr)>>1;
	 
	     build( v<<1 , tl, tm);
	     build( v<<1|1 , tm+1, tr);
 
	     segTree[ v ] = combine( v<<1 , v<<1|1 );
	}
	 
	int query(int l, int r , int v = 1, int tl = 0, int tr = n-1 )
	{
	    if( l > tr || r < tl) return 0;
	    if( tl >= l and tr <= r )
	    {
	        return segTree[v];
	    }
 
	    int tm = (tl+tr)/2;
	    int aa = query( l , r, v<<1 , tl , tm );
	    int bb = query( l , r, v<<1|1 , tm+1, tr );
 
		return ( aa + bb ); 
	}
 
	void update(int pos, int val, int v = 1, int tl = 0 , int tr = n - 1)
	{
		if( tl == tr )
		{
			segTree[ v ] += val;
			return;
		}
 
		int tm = (tl + tr)>>1;
		if( pos <= tm )
			update( pos, val, v<<1 , tl , tm );
		else 
			update( pos , val , v<<1|1 , tm+1, tr);
			
		segTree[ v ] = combine( v<<1 , v<<1|1 );
	}
 
}tree;
 
 
 
void go()
{
	cin>>n;
	map<string,int> price , cnt;
 
	fo(i,0,n) 
	{
		cin>>s;
		cin>>k;
		price[s] = k;
	}
 
	tree.init();
 
	cin>>q;
 
	while(q--)
	{
		char ch;
		cin>>ch;
 
		if( ch == '+' )
		{
			cin>>s;
			tree.update( price[s] , 1 );
			cnt[s]++;
		}
		else if( ch == '-' )
		{
			cin>>s;
			if( !cnt[s] ) continue;
			tree.update( price[s] , -1 );
			cnt[s]--;
		}
		else
		{
			int y;
			cin>>y;
 
			int ans = tree.query( y+1 , n );
			cout << ans << endl;
		}
		
 
 
	}
	
}
 
int32_t main()
{
	INP(); 
	FAST;     
	int t=1; 
	// cin>>t;
	test(t) go();
}