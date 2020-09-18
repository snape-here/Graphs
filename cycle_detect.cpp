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
vector<pi> ve;

int vis[N]={0},post[N];

int c=1;

void dfs(int p)
{
    vis[p]=1;

    for(int child: G[p])
        if(!vis[child])
            dfs(child);

    post[p]=c++;
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
        ve.pb({u,v});
    }

    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
            dfs(i);
    }

    int flag = 0;

    for(auto it: ve)
    {
        int a = it.ff;
        int b = it.ss;
        if(post[a]<post[b])
        {
            flag=1;
            break;
        }
    }

    if(flag)
        cout<<"Cycle Present"<<endl;
    else
        cout<<"Acyclic"<<endl;
 
    return 0;
   
}