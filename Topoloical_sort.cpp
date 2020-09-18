#include<bits/stdc++.h> 
using namespace std;
 
#define ull unsigned long long
#define int long long
#define ld long double
#define pb push_back
#define pi  pair< int,int >
#define ff first
#define ss second
#define mod 1000000007
#define endl "\n"
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N=1e5+5;

vector<int> G[N];

int vis[N]={0};

vector<int> order;

void dfs(int p)
{
    vis[p] = 1;

    for(int child: G[p])
        if(!vis[child])
            dfs(child);

    order.pb(p);
}

signed main()
{
 
    FIO

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n,m,u,v;

    cin>>n>>m;

    for(int i=0; i<m; i++)
    {
        cin>>u>>v;
        G[u].pb(v);
    }

    for(int i=1; i<=n; i++)
        if(!vis[i])
            dfs(i);

    reverse(order.begin(), order.end());

    for(int i: order)
        cout<<i<<" ";
    cout<<endl;

    return 0;
   
}