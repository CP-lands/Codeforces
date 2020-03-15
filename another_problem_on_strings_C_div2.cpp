#include<bits/stdc++.h>
 
using namespace std;

//https://codeforces.com/problemset/problem/165/C
void Solve(){
	int k;
	string s;
	cin>>k>>s;
	vector<int> index;
	index.push_back(-1);
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '1') index.push_back(i);
	}
	if(index.size() - 1< k){
		cout<<0<<'\n';
		return;
	}
	long long res = 0;
	if(k == 0){
		int i = 0;
		while(i < s.size()){
			int count = 0;
			while(i < s.size() && s[i] == '0'){
				count++;
				i++;
			}
			res += (long long)count * (count + 1) / 2;
			i++;
		}
		cout<<res<<'\n';
		return;
	}
	index.push_back(s.size());

	//long long res = 0;
	for(int i = 1; i < index.size() - k; i++){
		int left = index[i] - index[i - 1];
		int right = index[i + k] - index[i + k - 1];
		res += (long long)left * right;
		//cout<<left<<" "<<right<<'\n';
	}
	cout<<res<<'\n';

	return;
}
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q = 1;
    //cin>>q;
    while(q--){
    	Solve();
    }
}