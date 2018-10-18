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
    int ctr=0;
    while(t--)
    {	
    	if(ctr!=0)
    		cout<<"\n";
    	ctr++;
    	ll a,b,c;
    	cin>>a>>b>>c;
    	ll  arr[a][b][c];
    	for(int i=0;i<a;i++)
    	{
    		for(int j=0;j<b;j++)
    		{
    			for(int k=0;k<c;k++)
    			{
    				cin>>arr[i][j][k];
    				if(j>0)
    					arr[i][j][k]+=arr[i][j-1][k];
    				if(k>0)
    					arr[i][j][k]+=arr[i][j][k-1];
    				if(j>0&&k>0)
    					arr[i][j][k]-=arr[i][j-1][k-1];
    			}
    		}
    	}

    	ll sub_rec=0,max_val=INT_MIN,max_val_temp;
    	for(int j=0;j<b;j++)
    	{
    		for(int k=0;k<c;k++)
    		{
    			for(int j1=j;j1<b;j1++)
    			{
    				for(int k1=k;k1<c;k1++)
    				{
						ll sum;
    					max_val_temp=INT_MIN;
    					for(int i=0;i<a;i++)
    					{
    						sub_rec=arr[i][j1][k1];
    						if(j>0)
    							sub_rec-=arr[i][j-1][k1];
    						if(k>0)
    							sub_rec-=arr[i][j1][k-1];
    						if(j>0&&k>0)
    							sub_rec+=arr[i][j-1][k-1];
    						
    						if(i==0)
    							sum =sub_rec;
    						else
    						{
    							if(sum<0)
    								sum=0;
    							
    							sum+=sub_rec;
    						}
    						if(sum>max_val_temp)
    							max_val_temp=sum;

    					}

    					if(max_val_temp>max_val)
    						max_val=max_val_temp;
    				}
    			}
    		}
    	}

    	cout<<max_val<<"\n";	
    }

}
