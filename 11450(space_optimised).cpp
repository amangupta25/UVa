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


void max_money(ll m,ll c,ll price[25][25])
{
	bool reachable[2][201];
	memset(reachable,false,sizeof(reachable));

	for(int i=1;i<=price[0][0];i++)
	{
		if(m-price[0][i]>=0)
			reachable[0][m-price[0][i]]=true;
	}

	ll curr=1;
	for(int i=1;i<c;i++)
	{
		memset(reachable[curr],false,sizeof(reachable[curr]));
		for(int money=0;money<=m;money++)
		{
			if(reachable[!curr][money])
			{

				for(int j=1;j<=price[i][0];j++)
				{
					if(money-price[i][j]>=0)
						reachable[curr][money-price[i][j]]=true;
				}



					
			}

		
		}

		curr=!curr;
	}

	ll money;
	for(money=0;money<=m&&!reachable[!curr][money];money++);

	if(money==m+1)
		cout<<"no solution\n";
	else
		cout<<m-money<<"\n";	

}


int main()
{
    io

    ll n;
    cin>>n;
    while(n--)
    {
    	ll price[25][25];
    	ll m,c;
    	cin>>m>>c;
    	for0(i,c)
    	{
    		cin>>price[i][0];
    		for1(j,price[i][0])
    		{
    			cin>>price[i][j];
    		}
    	}

    	max_money(m,c,price);

    }


}
