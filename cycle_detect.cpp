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

const int MAX=5e18;

const int N=1e6+5;

const int mx=20;

int n,m;

vector<int>arr[N];

int vis[N];

bool dfs(int n , int par)
{
    vis[n] = 1;
    for(int i : arr[n])
    {
        if(!vis[i])
        {
            if(dfs(i,n))
                return true;
        }
        else
            if(i!=par)
                return true;
    }
    return false;
}

signed main()
{

    ios_base::sync_with_stdio(false); cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    

    return 0;
   
}