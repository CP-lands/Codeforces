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
	int n, m;
	cin>>n;
	vector<vector<int>> tg(n, vector<int>(3));
	
	for(int i = 0; i < n; i++){
		cin>>tg[i][0]>>tg[i][1];
		tg[i][2] = i;
	}
	sort(tg.begin(), tg.end());
	cin>>m;
	int shot[m][2];
	for(int i = 0; i < m; i++)
		cin>>shot[i][0]>>shot[i][1];
	vector<int> res(n);
	int ans = 0;
	for(int i = 0; i < m; i++){
		//if(shot[i][0] > tg[n - 1][0] + tg[n - 1][1] || shot[i][0] < tg[0][0] + tg[0][1]) continue; 
		int st = 0; int end = n - 1;
		while(end > st + 1){
			int mid = st + (end - st) / 2;
			if(tg[mid][0] > shot[i][0]) end = mid;
			else st = mid; 
		}

		ll l1 = (shot[i][0] - tg[st][0]) * (shot[i][0] - tg[st][0]) + shot[i][1] * shot[i][1];

		if(l1 <= tg[st][1] * tg[st][1] && res[tg[st][2]] == 0){
			res[tg[st][2]] = i + 1;
			ans++;
		}
		if(st < n - 1){
			ll l2 = (shot[i][0] - tg[st + 1][0]) * (shot[i][0] - tg[st + 1][0]) + shot[i][1] * shot[i][1];
			if(l2 <= tg[st + 1][1] * tg[st + 1][1] && res[tg[st + 1][2]] == 0){
				res[tg[st + 1][2]] = i + 1;
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	for(int i = 0; i < n; i++){
		if(res[i] == 0) cout<<-1<<" ";
		else cout<<res[i]<<" ";
	}

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
