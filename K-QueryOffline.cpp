#include "bits/stdc++.h"

using namespace std;

#define  f first
#define  lgn 25
#define  endl '\n'
#define  sc second
#define  N (int)3e5+5
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

int n,m,q;
string s;
int a[N],p[N],ans[N],b[N];

struct DD
{
    int v,pos;
}D[N];

struct T
{
    int k=0,l=0,r=0,idx=0;

}Q[N];


int segTree[4*N];

void build (int v=1, int tl=0, int tr=n-1) 
{
    if (tl == tr)
        segTree[v] = 1;
    else {
        int tm = (tl + tr)>>1;
        build (v<<1, tl, tm);
        build (v<<1|1, tm+1, tr);
        segTree[v] = (segTree[v<<1] + segTree[v<<1|1]);
    }
}

int sum (int l,int r, int v=1, int tl=0, int tr=n-1) 
{
    if (l > r)
        return 0;
    if (l == tl && r == tr)
        return segTree[v];
    int tm = (tl + tr)>>1;
    return sum ( l, min(r,tm),v<<1, tl, tm) +
           sum ( max(l,tm+1), r, v<<1|1, tm+1, tr);
}

void update (int pos, int value, int v=1, int tl=0, int tr=n-1)
{
    if (tl == tr)
        segTree[v] = value;
    else {
        int tm = (tl + tr)>>1;
        if (pos <= tm)
            update (pos, value , v<<1, tl, tm);
        else
            update (pos, value , v<<1|1, tm+1, tr);
        segTree[v] =(segTree[v<<1] + segTree[v<<1|1]);
    }
}
// build();
// update(position,value);
// sum(l,r);
// min(l,r);
// max(l,r);

bool comp( T a, T b )
{
    // if( a.k == b.k ) return a.l < b.l;
    return a.k < b.k;
}

bool cmp ( DD a , DD b)
{
    return a.v < b.v;
}

void go()
{
    cin>>n;

    build();

    fo(i,0,n)
    {
        cin>>D[i].v;
        D[i].pos = i;
    }

    sort(D, D+n , cmp);

    // return;

    cin>>q;

    fo(i,0,q)
    {
        int ll,rr,kk;
        cin>>ll>>rr>>kk;
        --ll,--rr;
        Q[i].k = kk; 
        Q[i].l = ll;
        Q[i].r = rr;
        Q[i].idx = i;
    }

    sort(Q, Q+q, comp);

    int po = 0;
    fo(i,0,q)
    {
        int xx = Q[i].idx;

        while( po < n and D[po].v <= Q[i].k ) update( D[po].pos , 0 ) , po++;

        ans[xx] = sum( Q[i].l , Q[i].r );
    }

    fo(i,0,q)
    {
        cout << ans[i] <<endl;
    }

}

int32_t main()
{    
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t=1; 
    // cin>>t;
    test(t) go();
}