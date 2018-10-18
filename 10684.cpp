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
    ll n;
    while(cin>>n)
    {
    	if(n==0)
    		break;
    	ll arr[n];
    	for0(i,n)
    		cin>>arr[i];

    	ll max_val=arr[0];
    	ll dp[n];
    	dp[0]=arr[0];
    	for(int i=1;i<n;i++)
    	{
    		if(dp[i-1]>=0)
    			dp[i]=dp[i-1]+arr[i];
    		else
    			dp[i]=arr[i];
    		if(dp[i]>max_val)
    			max_val=dp[i];
    	}		

    	if(max_val<=0)
    		cout<<"Losing streak.\n";
    	else
    		cout<<"The maximum winning streak is "<<max_val<<".\n";
    }



}
