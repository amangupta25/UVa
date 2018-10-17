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

ll memo[201][25];



ll max_money(ll m,ll c,ll curr_c,ll curr_m,ll price[25][25])
{

	if(curr_m<0)
		return -1000000;

	if(curr_c==c)
		return m-curr_m;
	
	if(memo[curr_m][curr_c]!=-1)
		return memo[curr_m][curr_c];



	ll ans=-1;
	for(int model=1;model<=price[curr_c][0];model++)
	{
		ans = max(ans,max_money(m,c,curr_c+1,curr_m-price[curr_c][model],price));


	}
		return memo[curr_m][curr_c] = ans;

}

int main()
{
    io
    ll n;
    cin>>n;
    while(n--)
    {
    	ll m,c;
    	cin>>m>>c;
    	ll price[25][25];
    	memset(memo,-1,sizeof(memo));
    	for0(i,c)
    	{
    		ll k;
    		cin>>k;
    		price[i][0]=k;
    		for1(j,k)
    		{
    			cin>>price[i][j];
    		}
    	}

    	ll score = max_money(m,c,0,m,price);

    	if(score<0)
    		cout<<"no solution\n";
    	else
    		cout<<score<<"\n";

    }   


}
