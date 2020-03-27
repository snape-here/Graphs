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

const int N=2e5+5;

const int mx=20;

int n;

vector<int>arr[N];

int LCA[N][mx+1];

int dist[N];

void dfs(int n , int d , int par)
{
    dist[n]=d;
    LCA[n][0]=par;

    for(int i : arr[n])
        if(i != par)
            dfs(i,d+1,n);
}

void build(int n)
{
    dfs(1,0,-1);
    for(int j=1;j<=mx;j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(LCA[i][j-1]!=-1)
            {
                int p = LCA[i][j-1];
                LCA[i][j] = LCA[p][j-1];
            }
        }
    }
}

int find_LCA(int a , int b)
{
    if(dist[a]>dist[b])
        swap(a,b);
    int f = dist[b]-dist[a];
    while(f)
    {
        int i = log2(f); 
        b = LCA[b][i];
        f -= (1<<i);
    }
    if(a==b)
        return a;

    for(int i=mx;i>=0;i--)
        if(LCA[a][i] !=- 1 && (LCA[a][i] != LCA[b][i]))
            a=LCA[a][i] , b=LCA[b][i];

    return LCA[a][0];
}

int get_dist(int a , int b)
{
    return dist[a]+dist[b]-2*find_LCA(a,b);
}

signed main()
{

    ios_base::sync_with_stdio(false); cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n,a,b,k,q,x;
    cin>>n>>q;

    for(int i=1;i<N;i++)
        for(int j=0;j<=mx;j++)
            LCA[i][j]=-1;

    for(int i=0;i<n-1;i++)
    {
        cin>>a>>b;
        arr[a].pb(b);
        arr[b].pb(a);
    }

    build(n);        //Initializing the Sparse Table

    vector<int>v;

    while(q--)
    {
        cin>>k;
        v.clear();
        for(int i=0;i<k;i++)
        {
            cin>>x;
            v.pb(x);
        }

        int lowest=0,bot_node;
        for(int i=0;i<k;i++)
        {
            if(dist[v[i]]>lowest)
            {
                lowest=dist[v[i]];
                bot_node=v[i];
            }
        }
        //cout<<bot_node<<endl;
        int flag=1;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]==bot_node)
                continue;
            int lc=find_LCA(bot_node,v[i]);
            int dst=abs(dist[lc]-dist[v[i]]);
            //cout<<dst<<endl;
            if (dst>1)
                flag=0;
        }
        if (flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }


    //If you want to get Distance b/w 2 nodes ----> dist[a]+dist[b]-2*lca(a,b)

    return 0;
   
}