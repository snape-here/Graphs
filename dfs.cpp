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

const int N=1e5+5;

int n,c;

vector<int>arr[N];

int vis[N];

vector<int>freq;

void dfs(int n)
{
    vis[n]=1;
    c++;
    for(int i:arr[n])
    {
        if(!vis[i])
            dfs(i);
    }
}

signed main()
{

    ios_base::sync_with_stdio(false); cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n,a,b,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        arr[a].pb(b);
        arr[b].pb(a);
    }

    for(int i=1;i<=n;i++)
    {
        dfs(i)
    }

    return 0;
   
}