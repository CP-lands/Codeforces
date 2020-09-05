#include<iostream>
#include<string.h>
#include<vector>
#include<math.h>
#include<algorithm>

//https://codeforces.com/problemset/problem/437/B
using namespace std;

long long lowbit(int n) {
	int count = 0;
	while(n > 0) {
		if(n % 2 == 1)
			return (long long)pow(2, count);
		n /= 2;
		count++;
	}
}
int main() {
	int sum, limit;
	vector<int> res;
	int summ = 0;
	cin>>sum>>limit;
	vector<vector<int>> v(limit, vector<int>(2));
	for(int i = 0; i < limit; i++) {
		v[i][0] = lowbit(i + 1);
		v[i][1] = i + 1;
	}
	sort(v.begin(), v.end());
	int i = v.size() - 1;
	while(summ < sum && i >= 0) {
		if(summ + v[i][0] <= sum) {
			summ += v[i][0];
			res.push_back(v[i][1]);
		}
		if(summ == sum)
			break;
		i--;
	}
	if(summ != sum) {
		cout<<-1<<endl;
		return 0;
	}
	cout<<res.size()<<endl;
	for(auto x : res)
		cout<<x<<" ";
	return 0;
}
