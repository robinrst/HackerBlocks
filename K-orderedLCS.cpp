#include        "iostream"
#include        "algorithm"
#include		"numeric"
#include        "cstring"
#include        "math.h"
#include        "string"
#include        "vector"
#include        "ctime"
#include        "queue"
#include        "stack"
#include        "map"
#include        "set"

#include        <ext/pb_ds/assoc_container.hpp> // Common file
#include        <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include        <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;


#define          f first
#define          lgn 25
#define          endl '\n'
#define          sc second
#define          N (int)2e3+5
#define          pb push_back
#define          mod 1000000007
#define          ld long double
#define          vi vector<int>
#define          eb emplace_back
#define          vpii vector<pii>
#define          mii map<int,int>
#define          int long long 
#define          pii pair<int,int>
#define          pq priority_queue
#define          test(x) while(x--)
#define          all(x) begin(x),end(x)
#define          allr(x) rbegin(x),rend(x)
#define          fo(i,a,n) for(int i=a;i<n;i++)
#define          rfo(i,n,a) for(int i=n;i>=a;i--)
#define          db(x) cout<<#x <<" : "<< x <<endl;
#define          FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define          time() cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n"
#define          PI acos(-1.0)
#define 		 bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)

typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > 
OS ;

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
     const char* comma = strchr (names + 1, ',');
     cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

inline void INP()
{
	#ifndef ONLINE_JUDGE
	    freopen("in.txt","r",stdin);   
	    freopen("ou.txt","w",stdout);
	#endif 
}

const int inf = 0x3f3f3f3f;
const int INF = 0x3f3f3f3f3f3f3f3f;

int n,m,k,q;
string s;
int a[N],b[N],dp[6][N][N];

void go()
{

	cin >> n >> m >> k;

	fo(i,0,n) cin >> a[i];
	fo(i,0,m) cin >> b[i];

	fo(i,1,n+1) // for k == 0 or Gap = 0
	{
		fo(j,1,m+1)
		{
			if( a[i-1] == b[j-1] )
			{
				dp[0][i][j] = 1 + dp[0][i-1][j-1];
			}
			else 
			{
				dp[0][i][j] = max( { dp[0][i-1][j] , dp[0][i][j-1] } );
			}
		// cout << dp[0][i][j] << ' ';
		}
		// cout << endl;
	}

	fo(nowGap,1,k+1)
	{
		fo(i,1,n+1)
		{
			fo(j,1,m+1)
			{
				if( a[i-1] == b[j-1] )
				{
					dp[nowGap][i][j] = 1 + dp[nowGap][i-1][j-1];
				}
				else
				{
					dp[nowGap][i][j] = max( { dp[nowGap][i-1][j] , dp[nowGap][i][j-1] , dp[nowGap-1][i-1][j-1] + 1} );
				}
			}
		}
	}

	int ans = dp[k][n][m];

	cout << ans << endl;	
}

int32_t main()
{
	INP(); 
	FAST;     
	int t=1; 
	// cin>>t;
	test(t) go();
}
