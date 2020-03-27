#include<bits/stdc++.h> 
using namespace std;
 
#define ull unsigned long long
#define int long long
#define ld long double
#define pb push_back
#define pi  pair< int,int >
#define pl  pair< ll,ll >
#define f first
#define s second 
#define mx 10000004
//#define endl "\n"

const int N=1e5+5;

int n,a,b;

const int mod=1e9+7;

int par[N];

int R[N];

int find(int n)
{
	if(n==par[n])
		return n;
	return par[n]=find(par[n]);
}

void make_set(int v)
{
    par[v] = v;
    R[v] = 0;
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if (R[a] < R[b])
            swap(a, b);
        par[b] = a;
        if (R[a] == R[b])
            R[a]++;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++)
        make_set(i);

    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        merge(a,b);
    }

    int f=1;

    if(n!=m)
        f=0;

    for(int i=1;i<n;i++)
        if(find(i)!=find(i+1))
            f=0;

    if (f)
        cout<<"FHTAGN!";
    else
        cout<<"NO";

    return 0;
   
}