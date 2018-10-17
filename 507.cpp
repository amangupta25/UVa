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
    ll b;
    cin>>b;
    ll temp=1;
	while(temp<=b)
	{
		ll s;
		cin>>s;
		ll nice[s-1];
		for0(i,s-1)
			cin>>nice[i];

		ll sum;
		pair<ll,ll> dp[s-1];
		if(nice[0]<0)
		{
			dp[0].first=0;
			dp[0].second=0;
		}
		else
		{
			dp[0].first=1;
			dp[0].second=nice[0];
		}	
		for(int i=1;i<s-1;i++)
		{
			if(dp[i-1].second<0)
			{
				dp[i].first = 1;
				dp[i].second=nice[i];
			}
			else
			{
				dp[i].first = dp[i-1].first + 1;
				dp[i].second=dp[i-1].second+nice[i];
			}
		}

		ll max_val = INT_MIN;
		ll start=0,end=0;


		for(int i=0;i<s-1;i++)
		{

			if(dp[i].second>max_val)
			{
				max_val = dp[i].second;
				end = i;
				start = end-dp[i].first;

			}
			else if(dp[i].second==max_val)
			{
				if(dp[i].first>(end-start))
				{
					end = i;
					start = end- dp[i].first;
				}
			}
		}

		if(max_val==0)
			cout<<"Route "<<temp<<" has no nice parts\n";
		else
			cout<<"The nicest part of route "<<temp<<" is between stops "<<start+2<<" and "<<end+2<<"\n";


		temp++;
	}    

}
