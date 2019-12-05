//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long ll; 
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 100;
 
bool isPrime(ll n)
{
	if(n < 2) return false;
	if(n == 2) return true;
	for(ll i = 2; i * i <= n; i++)
		if(n % i == 0) return false;
	return true;
}
ll power(ll a, ll k)
{
	if (k == 0) return 1;
	if (k == 1) return a;
	ll tmp = power(a, k >> 1);
	tmp = (tmp * tmp) % MOD;
	return k % 2 ? (tmp * a) % MOD : tmp;
}
string int_to_string(int n)
{
	string res = "";
	while(n / 10 > 0)
	{
		res += n % 10 + '0';
		n /= 10;
	}
	res += n % 10 + '0';
	string ans = "";
	for(int i = res.size() - 1; i >= 0; i--)
		ans += res[i];
	return ans;
}
ll string_to_int(string s)
{
	ll res = 0;
	for(int i = 0; i < s.size(); i++)
		res += (s[i] - '0') * power(10, s.size() - 1- i);
	return res;
}
int get_gcd(int a, int b)
{
	if(b == 0) return a;
	return get_gcd(b, a % b);
}

void Anivia_kid(){
	int n, m, k;
	cin>>n>>m>>k;
	int x = 1, y = 1;
	vector<pair<int, int>> res;
	int count = 0;
	int direct = 1;
	while(true){
		//if(count < n * m - 2 * (k - 1) && count / 2 < k) res[count / 2].pb({x, y});
		res.pb({x, y});
		if(count % 2 == 1 &&  count / 2 < k - 1){
			cout<<2<<" ";
			for(auto x: res)
				cout<<x.fi<<" "<<x.se<<" ";
			cout<<"\n";
			res.clear();
		}
		if(count == n * m - 1) break;
		if(direct == 1){
			if(y == m){
				x++;
				direct = -1;
			}
			else y++;
			count++;
		}
		else if(direct == -1){
			if(y == 1){
				x++;
				direct = 1;
			}
			else y--;
			count++;
		}
	}
	cout<<n * m - 2 * (k - 1)<<" ";
	for(auto x: res)
		cout<<x.fi<<" "<<x.se<<" ";

	return;
}
 
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int q = 1;
	//cin>>q;
	while(q--){
		Anivia_kid();
	}
	return 0;
}