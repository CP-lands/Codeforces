//--------Anivia_kid---------//
//https://codeforces.com/contest/1196/problem/D2
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
 
typedef long long ll; 
const int MOD = 1e9 + 7;
 
void Anivia_kid(){
	int n, k;
	string s;
	cin>>n>>k>>s;
	if(k == 1){
		cout<<0<<'\n';
		return;
	}
	if(k == 2){
		for(int i = 0; i < n; i++){
			if(s[i] == 'R'){
				if((i > 0 && s[i - 1] == 'B') || (i < n - 1 && s[i + 1] == 'G')){
					cout<<0<<'\n';
					return;
				}
			}
			if(s[i] == 'G'){
				if((i > 0 && s[i - 1] == 'R') || (i < n - 1 && s[i + 1] == 'B')){
					cout<<0<<'\n';
					return;
				}
			}
			if(s[i] == 'B'){
				if((i > 0 && s[i - 1] == 'G') || (i < n - 1 && s[i + 1] == 'R')){
					cout<<0<<'\n';
					return;
				}
			}
		}
		cout<<1<<'\n';
		return;
	}
	int res = INT_MAX;
	int count = 0;
	//case1 RGB
	//case2 GBR
	//case3 BRG
	vector<bool> c1(n), c2(n), c3(n);
	for(int i = 0; i < n; i = i + 3){
		if(s[i] == 'R') c1[i] = true;
		else if(s[i] == 'G') c2[i] = true;
		else c3[i] = true;
		if(i + 1 < n && s[i + 1] == 'G') c1[i + 1] = true;
		else if(i + 1 < n && s[i + 1] == 'B') c2[i + 1] = true;
		else if(i + 1 < n && s[i + 1] == 'R') c3[i + 1] = true;
		if(i + 2 < n && s[i + 2] == 'B') c1[i + 2] = true;
		else if(i + 2 < n && s[i + 2] == 'R') c2[i + 2] = true;
		else if(i + 2 < n && s[i + 2] == 'G') c3[i + 2] = true;
	}
	//c1
	int tmp1 = 0, tmp2 = 0, tmp3 = 0;
	for(int i = 0; i < k; i++){
		if(!c1[i]) tmp1++;
		if(!c2[i]) tmp2++;
		if(!c3[i]) tmp3++;
	}
	res = min(tmp1, tmp2);
	res = min(res, tmp3);
	for(int i = k; i < n; i++){
		if(!c1[i]) tmp1++;
		if(!c2[i]) tmp2++;
		if(!c3[i]) tmp3++;
		if(!c1[i - k]) tmp1--;
		if(!c2[i - k]) tmp2--;
		if(!c3[i - k]) tmp3--;
		res = min(res, tmp1);
		res = min(res, tmp3);
		res = min(res, tmp2);
	}
	cout<<res<<'\n';

	return;
}
 
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int q;
	cin>>q;
	while(q--){
		Anivia_kid();
	}
}