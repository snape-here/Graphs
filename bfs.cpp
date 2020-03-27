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

int n,c;

vector<int>arr[N];

int vis[N];

void bfs(int n)
{
    queue<int>q;
    q.push(n);
    vis[n]=1;
    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        for(int i: arr[curr])
        {
            if(!vis[i])
            {
                q.push(i);
                vis[i]=1;
                cout<<i<<" "<<curr<<endl;
            }
        }
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

    int md=0;

    int src=0;

    for(int i=1;i<=n;i++)
    {
        if(arr[i].size()>md)
        {
            md=arr[i].size();
            src=i;
        }
    }

    bfs(src);


    return 0;
   
}