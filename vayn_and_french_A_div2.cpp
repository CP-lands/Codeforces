#include<iostream>

using namespace std;

int main()
{
	int n,h;
	int count = 0;
	cin>>n>>h;
	for(int i = 0; i < n; i++)
	{
		int temp;
		cin>>temp;
		if(temp>h)
			count = count + 2;
		else
			count++;
	}
	cout<<count<<endl;
	return 0;
}