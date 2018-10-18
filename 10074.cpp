/**
*	Username : bryancode
*	Name : Aman Gupta
*	Institute : Birla Institute of Technology & Science,Pilani
*/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define scani(n) scanf("%d",&n);
#define EPS 1e-9
#define FOR(i,n) for(int i=0; i<n; i++)
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define X first
#define Y second
#define for0(i,n) for(int i=0; i<n; i++)
#define for1(i,n) for(int i=1; i<=n; i++)
#define forr(i,n) for(int i=n-1; i>=0; i--)

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int MOD = 1e9+7;
const int n_ = 1e5+1000;
const long double PI = acos(-1.0);

ll gcd (ll a, ll b) {return ( a ? gcd(b%a, a) : b );}
ll power(ll a, ll n) {ll p = 1;while (n > 0) {if(n%2) {p = p * a;} n >>= 1; a *= a;} return p;}
ll power(ll a, ll n, ll mod) {ll p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;}

int main()
{
    io
    ll n,m;
    while(true)
    {

    	cin>>n>>m;

    	if(n==0&&m==0)
    		break;
    	ll arr[n][m];
    	for(int i=0;i<n;i++)
    	{
    		for(int j=0;j<m;j++)
    		{
    			cin>>arr[i][j];
    			arr[i][j]=!arr[i][j];
    			if(i>0)
    				arr[i][j]+=arr[i-1][j];
    			if(j>0)

    				arr[i][j]+=arr[i][j-1];
    			if(i>0&&j>0)
    				arr[i][j]-=arr[i-1][j-1];
    		}
    	}

    	ll sub_rec,max_val=0;
    	for(int i=0;i<n;i++)
    	{
    		for(int j=0;j<m;j++)
    		{
    			for(int k=i;k<n;k++)
    			{
    				for(int l=j;l<m;l++)
    				{
    					sub_rec=arr[k][l];
    					if(i>0)
    						sub_rec-=arr[i-1][l];
    					if(j>0)
    						sub_rec-=arr[k][j-1];
    					if(i>0&&j>0)
    						sub_rec+=arr[i-1][j-1];

    					if(sub_rec==(k-i+1)*(l-j+1))
    					{
    						if(sub_rec>max_val)
    							max_val=sub_rec;

    					}
    				}
    			}
    		}

    	}

    	cout<<max_val<<"\n";
    }


}
