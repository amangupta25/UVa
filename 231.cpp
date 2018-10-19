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

ll longest_non_increasing(vector<ll>seq)
{
	vector<ll> tail;
	tail.push_back(seq[0]);

	for(int i=1;i<seq.size();i++)
	{
		if(seq[i]>tail[0])
			tail[0]=seq[i];
		else if(seq[i]<=tail.back())
		{
			tail.push_back(seq[i]);
		}
		else
		{
			ll pos = upper_bound(tail.begin(),tail.end(),seq[i],greater<int>())-tail.begin();
			//cout<< pos;
			tail[pos]=seq[i];
		}
	}

	return tail.size();

}

int main()
{
    io
  	int ctr=0;
  	ll n;
    while(cin>>n)
    {
    	vector<ll>seq;
    	if(n==-1)
    		break;
    	seq.push_back(n);
    	if(ctr!=0)
    		cout<<"\n";
    	ctr++;
    	ll num;
    	cin>>num;
    	
    	while(num!=-1)
    	{
    		seq.push_back(num);
    		cin>>num;
    	}

    	ll ans = longest_non_increasing(seq);
    	cout<<"Test #"<<ctr<<":\n"<<"  maximum possible interceptions: "<<ans<<"\n";
    }

}
