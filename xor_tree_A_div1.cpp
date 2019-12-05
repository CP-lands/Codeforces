//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/problemset/problem/429/A
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
	int n;
	cin>>n;
	vector<int> g[n + 1];
	for(int i = 0; i < n - 1; i++){
		int u, v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	vector<int> ini(n + 1), fin(n + 1);
	for(int i = 1; i <= n; i++)
		cin>>ini[i];
	for(int i = 1; i <= n; i++)
		cin>>fin[i];
	vector<int> res;
	vector<bool> visited(n + 1);
	queue<int> q;
	q.push(1);
	visited[1] = true;
	vector<int> odd(n + 1), even(n + 1);
	vector<int> level(n + 1);
	if(ini[1] != fin[1]){
		even[1] = 1;
		res.pb(1);
	}
	while(!q.empty()){
		int current = q.front();
		q.pop();
		for(auto x: g[current]){
			if(!visited[x]){
				visited[x] = true;
				q.push(x);
				level[x] = level[current] + 1;
				if(ini[x] != fin[x]){
					if(level[x] % 2 == 0){
						if(even[current] % 2 == 0){
							res.pb(x);
							even[x] = even[current] + 1;
							odd[x] = odd[current];
						}
						else{
							even[x] = even[current];
							odd[x] = odd[current];
						}
					}
					else{
						if(odd[current] % 2 == 0){
							res.pb(x);
							odd[x] = odd[current] + 1;
							even[x] = even[current];
						}
						else{
							odd[x] = odd[current];
							even[x] = even[current];
						}
					}
				}
				else{
					if(level[x] % 2 == 0){
						if(even[current] % 2 != 0){
							res.pb(x);
							even[x] = even[current] + 1;
						}
						else even[x] = even[current];
						odd[x] = odd[current];
					}
					else{
						if(odd[current] % 2 != 0){
							res.pb(x);
							odd[x] = odd[current] + 1;
						}
						else odd[x] = odd[current];
						even[x] = even[current];
					}
				}
			}
		}
	}
	cout<<res.size()<<"\n";
	for(auto x: res)
		cout<<x<<"\n";

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