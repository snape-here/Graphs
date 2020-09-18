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

vector<int> G[N],Gr[N];

vector<int>order;

int vis[N]={0};

void dfs(int p)
{
    vis[p]=1;

    for(int child: G[p])
        if(!vis[child])
            dfs(child);

    order.pb(p);
}

void dfs2(int p)
{
    vis[p]=1;

    for(int child: Gr[p])
        if(!vis[child])
            dfs2(child);
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
        Gr[v].pb(u);
    }

    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
            dfs(i);
    }

    for(int i=1; i<=n; i++)
        vis[i]=0;

    int ans = 0;

    for(int i=1; i<=n; i++)
    {
        int b = order[n-i];
        if(!vis[b])
        {
            dfs2(b);
            ans++;
        }
    }

    cout<<ans<<endl;
 
    return 0;
   
}