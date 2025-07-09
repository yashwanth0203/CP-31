/*This is just kadane algo with extra condition*/


#include <bits/stdc++.h>
using namespace std;

void solve() 
{
	long long n;
	cin >> n;
 
	long long arr[n];
	for(long long i=0;i<n;i++){
	    cin >> arr[i];
	}
 
	long long curr = 0;
	long long ans = INT_MIN;
 
	bool f = true;
	for(long long i = 0; i < n; i++) {
		if(arr[i] > 0) f = false;
	}
 
	if(f) {
		for(auto i : arr) ans = max(ans, i);
		cout << ans << '\n';
		return;
	}
 
	for(long long i = 0; i < n; i++) {
		curr += arr[i];
		if(i != 0 && abs(arr[i]) % 2 == abs(arr[i - 1]) % 2) curr = arr[i];
		if(curr < 0) curr = 0;
		ans = max(ans, curr);
	}
 
	cout << ans << '\n';
 
}
 
int main()
{
	int t = 1;
	cin >> t;
	while(t--)
	{
		solve();
	}
	return 0;
}