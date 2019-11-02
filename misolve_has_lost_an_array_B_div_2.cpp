#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	int n, l, r;
	int min = 0;
	int max = 0;
	cin>>n>>l>>r;
	for(int i = 0; i < l; i++)
		min = min + pow(2,i);
	min = min + (n - l);
	for(int i = 0; i < r; i++)
		max = max + pow(2,i);
	max = max + (n - r) * pow(2, r - 1);
	cout<<min<<" "<<max<<endl;
	return 0;
}