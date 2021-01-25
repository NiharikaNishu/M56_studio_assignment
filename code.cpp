#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>arr, int p, int r, int num) {
   if (p <= r) {
      int mid = (p + r)/2;
      if (arr[mid] == num)
      return mid ;
      if (arr[mid] > num)
      return binarySearch(arr, p, mid-1, num);
      if (arr[mid] > num)
      return binarySearch(arr, mid+1, r, num);
   }
   return -1;
}
 
int main() {
	// your code goes here
	int n,m;
	cin>>n>>m;
	vector<int>tournament_run(n),temp;
	vector<int>david(m);
	for(int i=0;i<n;i++)
	{
		cin>>tournament_run[i];
		if(i==0) temp.push_back(tournament_run[i]);
		else if(tournament_run[i]!=tournament_run[i-1]) temp.push_back(tournament_run[i]);
	}
	for(int i=0;i<m;i++) cin>>david[i];
	reverse(temp.begin(),temp.end());
	for(int i=0;i<m;i++)
	{
		int flag=0;
		int pos = lower_bound(temp.begin(),temp.end(),david[i])-temp.begin();
		if(binarySearch(temp,0,temp.size()-1,david[i])) flag=1;
		cout<<temp.size()-pos+2-flag<<" ";
	}
	return 0;
}
