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
    ll t;
    cin>>t;
    int ctr=1;
    while(t--)
    {
    	
    	ll n,m,r;
    	cin>>n>>m>>r;
    	ll arr[n][m];
    	ll price[n][m];

    	for(int i=0;i<n;i++)
    	{
    		for(int j=0;j<m;j++)
    		{
    			cin>>price[i][j];
    			arr[i][j]=1;
    			if(i>0)
    			{
    				price[i][j]+=price[i-1][j];
    				arr[i][j]+=arr[i-1][j];
    			}
    			if(j>0)
    			{
    				price[i][j]+=price[i][j-1];
    				arr[i][j]+=arr[i][j-1];
    			}
    			if(i>0&&j>0)
    			{
    				price[i][j]-=price[i-1][j-1];
    				arr[i][j]-=arr[i-1][j-1];
    			}

    		}
    	}

    	ll sub_price,sub_area,max_arr=0,min_pr=0;
    	for(int i=0;i<n;i++)
    	{
    		for(int j=0;j<m;j++)
    		{
    			for(int k=i;k<n;k++)
    			{
    				for(int l=j;l<m;l++)
    				{
    					sub_price=price[k][l];
    					sub_area=arr[k][l];
    					if(i>0)
    					{
    						sub_price-=price[i-1][l];
    						sub_area-=arr[i-1][l];
    					}
    					if(j>0)
    					{
    						sub_price-=price[k][j-1];
    						sub_area-=arr[k][j-1];
    					}
    					if(i>0&&j>0)
    					{
    						sub_price+=price[i-1][j-1];
    						sub_area+=arr[i-1][j-1];
    					}

    					//cout<<"sub_arr: "<<sub_area<<" sub_price: "<<sub_price<<"\n";
    					if(sub_price<=r)
    					{

    						if(sub_area>max_arr)
    						{
    							max_arr=sub_area;
    							min_pr=sub_price;
    						}
    						else if(sub_area==max_arr)
    						{
    							if(sub_price<min_pr)
    								min_pr=sub_price;
    						}
    					}
    				}
    			}
    		}
    	}

    	cout<<"Case #"<<ctr++<<": "<<max_arr<<" "<<min_pr<<"\n";

    }

}

