//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
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

map<int, map<int, int>> mp;
set<int> visited;

void Anivia_kid(){
	int n;
	cin>>n;
	vector<int> res(n + 1);
	map<int, int> mpp;
	
	for(int i = 0; i < n - 2; i++){
		int a, b, c;
		cin>>a>>b>>c;
		++mp[a][b];
		++mp[a][c];
		++mp[b][a];
		++mp[b][c];
		++mp[c][a];
		++mp[c][b];
		++mpp[a];
		++mpp[b];
		++mpp[c];
	}
	int first;
	for(auto x : mpp){
		if(x. se == 1){
			first = x.fi;
			break;
		}
	}
	res[1] = first;
	for(auto x : mp[first]){
		if(mpp[x.fi] == 2) res[2] = x.fi;
		if(mpp[x.fi] == 3) res[3] = x.fi;
	}
	visited.insert(res[1]);
	visited.insert(res[2]);
	visited.insert(res[3]);
	int i = 3;
	while(i < n - 2){
		for(auto x : mp[res[i]]){
			if(x.se == 2 && visited.find(x.fi) == visited.end()){
				res[++i] = x.fi;
				visited.insert(x.fi);
			}
		}
	}
	for(auto x : mpp){
		if(x.se == 1 && visited.find(x.fi) == visited.end()) res[n] = x.fi;
		if(x.se == 2 && visited.find(x.fi) == visited.end()) res[n - 1] = x.fi;
	}

	for(int i = 1; i <= n; i++)
		cout<<res[i]<<" ";
	cout<<endl;
	//3 2 1 7 6 5 4
 
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