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


class Fenwick
{
public:
    vi BIT;
 
    void init() 
    {
        int nn = N + 11;
        BIT.clear();
        BIT.resize(nn, 0);
    }
 
    void update(int i,int val)
    {
        for( ; i <= (N) ; i += ( i&(-i) ) ) BIT[i] += val;
    }
    
    int query(int i)
    {
        int sum = 0;
        for ( ; i > 0 ; i -= ( i&(-i) ) ) sum += BIT[i];
        return sum;
    }
 
}fn;
// first initialise every element in BIT array to zero
// 1-based indexing
//query(r) gives [0.....r] sum
//update(i,val) -> update every interval in which val exist 
// at index which is power of 2 stores sum from [0 ......... 2^k]
// at odd index, it store that element as in array
// at even index, not power of 2, sum stores in interval in which bit is 1 in binary.




void go()
{
	cin>>n;
	map<string,int> price , cnt;

	fo(i,1,n+1) 
	{
		cin>>s;
		cin>>k;
		price[s] = k;
	}

	fn.init();

	cin>>q;

	while(q--)
	{
		char ch;
		cin>>ch;

		if( ch == '+' )
		{
			cin>>s;
			fn.update( price[s] , 1 );
			cnt[s]++;
		}
		else if( ch == '-' )
		{
			cin>>s;
			if( !cnt[s] ) continue;
			fn.update( price[s] , -1 );
			cnt[s]--;
		}
		else
		{
			int y;
			cin>>y;

			int ans = fn.query(N) - fn.query(y);
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
