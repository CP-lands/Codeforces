//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/contest/716/problem/B
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back

typedef long long ll; 
const int MOD = 1e9 + 7;

void Anivia_kid(){
	string s;
	cin>>s;
	set<char> c;
	map<char, int> mp;
	int q = 0;
	if(s.size() < 26){
		cout<<-1<<endl;
		return;
	}
	for(int i = 0; i < 26; i++){
		if(s[i] != '?'){
			c.insert(s[i]);
			++mp[s[i]];
		}
		else q++;
	}
	int low = 0;
	int high = 26;
	while(high <= s.size()){
		if(c.size() + q == 26){
			for(int i = 0; i < low; i++){
				if(s[i] == '?') cout<<"A";
				else cout<<s[i];
			}
			for(int i = low; i < high; i++){
				if(s[i] != '?') cout<<s[i];
				else{
					for(char k = 'A'; k <= 'Z'; k++){
						if(c.find(k) == c.end()){
							cout<<k;
							c.insert(k);
							break;
						}
					}
				}
			}
			for(int i = high; i < s.size(); i++){
				if(s[i] == '?') cout<<"A";
				else cout<<s[i];
			}
			return;
		}
		if(s[low] == '?') q--;
		else{
			if(mp[s[low]] == 1) c.erase(s[low]);
			mp[s[low]]--;
		}
		if(s[high] == '?') q++;
		else{
			c.insert(s[high]);
			++mp[s[high]];
		}
		low++;
		high++;
	}
	cout<<-1<<"\n";

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
}
