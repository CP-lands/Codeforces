//--------Anivia_kid---------//
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
 
void Anivia_kid(){
	int n;
	cin>>n;
	vector<int> v(n), res;
	for(int i = 0; i < n; i++)
		cin>>v[i];
	set<int> in, out;
	int days = 0;
	for(int i = 0; i < n; i++){
		if(v[i] > 0){
			if(in.find(v[i]) == in.end()) in.insert(v[i]);
			else{
				if(in.size() == out.size()){
					days++;
					res.pb(in.size() * 2);
					in.clear();
					out.clear();
					in.insert(v[i]);
				}
				else{
					cout<<-1<<endl;
					return;
				}
			}
		}
		else{
			if(out.find(v[i]) == out.end() && in.find(-v[i]) != in.end()) out.insert(v[i]);
			else{
				cout<<-1<<endl;
				return;
			}
		}
		if(!in.empty() && in.size() == out.size()){
			days++;
			res.pb(in.size() * 2);
			in.clear();
			out.clear();
		}
	}
	if(in.size() != out.size()){
		cout<<-1<<endl;
		return;
	}

	cout<<days<<"\n";
	for(int i = 0; i < res.size(); i++)
		cout<<res[i]<<" ";
 
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