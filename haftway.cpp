#include<bits/stdc++.h>

using namespace std;
//https://codeforces.com/gym/101652/attachments
 
void Solve()
{
	long long n;
	cin>>n;
	long long tmp = n * (n - 1) / 2;
	long long way = (tmp + 1) / 2;
	int low = 1, high = n - 1;
	int res = 0;
	int exit = 0;
	//cout<<tmp<<" "<<way<<endl;
	long long tmp1 = 0;
	if(n == 2){
		cout<<1<<endl;
		return;
	}
	//cout<<low<<" "<<high<<endl;
	while(low < high){
		long long mid = (low + high) / 2;
		if(exit == 2) mid = high;
		long long target = (n - mid - 1) * (n - mid) / 2;
		long long ans = tmp - target;
		//long long target2 = (n - mid) * (n - mid + 1) / 2;
		//long long ans2 = tmp - target2;
		//cout<<low<<" "<<high<<" "<<mid<<" "<<ans<<endl;
		if(ans <= way){
			res = mid;
			low = mid;
		}
		else{
			high = mid;
		}
		if(high - low == 1){
			exit++;
		}
		if(exit == 2) tmp1 = ans + 1;
		if(exit == 3){
			//cout<<tmp1<<" "<<way<<" "<<ans<<endl;
			if(way >= tmp1 && way < ans) res = mid;
			break;
		}
		//cout<<res<<'\n';
	}
	cout<<res<<'\n';
 
}
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T = 1;
	//cin>>T;
	while(T--){
		Solve();
	}
}