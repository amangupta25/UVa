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
    vector<ll>seq;
    ll num;
    while(cin>>num)
    	seq.push_back(num);

    int n = seq.size();
	vector<ll>tail;
	ll parent[n];

	tail.push_back(seq[0]);
	parent[0]=INT_MIN;
	for(int i=1;i<n;i++)
	{
		if(seq[i]<tail[0])
		{
			tail[0]=seq[i];
			parent[i]=INT_MIN;
		}
		else if(seq[i]>tail.back())
		{
			tail.push_back(seq[i]);
			parent[i]=tail[tail.size()-2];
		}
		else
		{
			ll pos = lower_bound(tail.begin(),tail.end(),seq[i])-tail.begin();
			tail[pos]=seq[i];
			parent[i]=tail[pos-1];
		}

	}

	cout<<tail.size()<<"\n";
	cout<<"-\n";

	ll to_find=tail.back();
	vector<ll> lis;
	for(int i=n-1;i>=0;i--)
	{
		if(seq[i]==to_find)
		{
			lis.push_back(seq[i]);
			to_find=parent[i];
		}
	}

	for(int i=lis.size()-1;i>=0;i--)
		cout<<lis[i]<<"\n";


}
