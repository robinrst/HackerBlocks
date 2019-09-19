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

int n,m,k,q,e,src;
vpii adj[N];
int vis[N],par[N],a[N],dis[N];

void bfs()
{
	queue<pii> q;

	fo(i,1,n+1) dis[i] = inf,vis[i] = 0; // Assigning distance and visited array

	dis[src] = 0; // making starting point distance as zero

	q.push({src,dis[src]}); // pushing source in queue
	vis[src] = 1; // marking source as visited

	while(!q.empty())
	{
		auto u = q.front(); // u is of  datatype pair<int,int>
							// u.f denotes the vertex and u.sc denotes the distance
		q.pop();

		for ( auto i : adj[u.f] ) // traversing all direct edges in adjacency list
		{

			auto v = i.f; // v is vertex directly connceted 
			int w = i.sc; // weight of edges u-v

			if( vis[v] ) continue;

			if( dis[v] > dis[u.f] + w ) // if distance from u to v is smaller than the  distance then update it
			{
				dis[v] = dis[u.f] + w; 
				q.push({v,dis[v]});
				vis[v] = 1;
			}
		}
	}

}

void go()
{
	cin>>n>>e;

	fo(i,0,e) // loop for inputing edges
	{
		int u,v;
		cin>>u>>v;
		adj[u].pb({v,6}); // edge from u to v 
		adj[v].pb({u,6});// edge from v to u
	}

		cin>>src; // inputing source

		bfs(); // calling bfs ( source is global as src so no need to pass in bfs)

		fo(i,1,n+1)
		{
			if( i == src ) continue; // source is not required to print
			if( dis[i] != inf ) cout << dis[i] <<' ';
			else cout << -1 << ' ';
		}
		cout << endl ;

		fo(i,1,n+1) adj[i].clear(); // clearing adjacency list for next test case

}

int32_t main()
{	
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t=1; 
	cin>>t;
	test(t) go();
}