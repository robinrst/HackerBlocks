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
string s;
vi adj[N];
int vis[N],par[N],a[N],sz[N],Q[N];

class Fenwick
{
public:
    vi BIT;

    void init()
    {
        int nn = n + 10;
        BIT.clear();
        BIT.resize(nn, 0);
    }

    void update(int i,int val)
    {
        for( ; i <= n ; i += ( i&(-i) ) ) BIT[i] += val;
    }
    
    int query(int i)
    {
        int sum = 0;
        for ( ; i > 0 ; i -= ( i&(-i) ) ) sum += BIT[i];
        return sum;
    }

}fn[27];

void go()
{
    cin>>n>>q;
    cin>>s;
    s = "$" + s;
    n = s.size();

    fo(i,0,27) fn[i].init();

    fo(i,1,n)
    {
        int alpha = s[i] - 'a';
        // db(alpha);
        fn[ alpha ].update(i,1);
    }

    while( q-- )
    {
        int ch,xx,yy;
        char cc;
        cin>>ch>>xx;

        if( ch == 1 )
        {
            cin>>cc;
            int now = s[xx] - 'a';
            s[xx] = cc;
            fn[ now ].update(xx,-1);
            yy = cc - 'a';
            fn[ yy ].update(xx,1);
        }
        else
        {
            cin>>yy;
            int ans = 0;
            int odd = 0, even = 0;
            fo(i,0,26)
            {
                int times = fn[ i ].query(yy) - fn[ i ].query(xx-1);
                if( times&1 ) odd++;
                else even++;
            }

            if( odd > 1 ) cout <<"no\n";
            else cout <<"yes\n";

        }
    }


}

int32_t main()
{    
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int t=1; 
    // cin>>t;
    test(t) go();
}