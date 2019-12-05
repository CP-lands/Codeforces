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
map<int, int> my_map;

void Anivia_kid(){
	int a, b;
	cin>>a>>b;
	stack<int> s;
	s.push(b);
	while(!s.empty()){
		int n = s.top();
		s.pop();
		if(n == a) break;
		if(n < a) continue;
		if(n % 2 == 0){
			int x = n / 2;
			s.push(x);
			my_map[x] = n;
		} 
		if((n - 1) % 10 == 0){
			int y = (n - 1) / 10;
			s.push(y);
			my_map[y] = n;
		}
	}
	if(my_map[a] == 0){
		cout<<"NO"<<endl;
		return;
	}
	vector<int> res;
	res.pb(a);
	while(a != b){
		res.pb(my_map[a]);
		a = my_map[a];
	}
	cout<<"YES"<<endl;
	cout<<res.size()<<endl;
	for(auto x: res)
		cout<<x<<" ";
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