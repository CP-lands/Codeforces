#include<iostream>

using namespace std;

int main()
{
	int n,a;
	cin>>n>>a;
	int b[n];
	for(int i = 0; i < n; i++)
		cin>>b[i];
	int count1 = a - 1;
	int count2 = a - 1;
	int result = b[a - 1];
	while(count1 >= 0 || count2 < n)
	{
		if(count1 >= 0 && count2 < n)
		{
			if((b[count1] + b[count2]) % 2 == 0 && count1 != count2)
				result = result + b[count1] + b[count2];
			count1--;
			count2++;
		}
		else if(count1 < 0 && count2 < n)
		{
			result = result + b[count2];
			count2++;
		}
		else if(count1 >= 0 && count2 >= n)
		{
			result = result + b[count1];
			count1--;
		}
	}
	cout<<result<<endl;
	return 0;
}