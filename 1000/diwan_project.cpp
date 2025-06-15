/*Simple solution sort in descending order, keep owner building in middle.
Keep largest elements closer to either side of owner building*/


#include <bits/stdc++.h>
using namespace std;

void solve(){
	
	int n;
	cin>>n;

	vector<pair<int, int>> visits(n+1);//first : #times to visit; second: id(1...n)
	for(int i=1; i<=n; i++){
		cin>>visits[i].first;
		visits[i].second = i;
	}

	sort(visits.rbegin(), visits.rend()-1);

	long long total_time = 0;
	long long cur_coord = 1;
	vector<long long>config(n+1);//config[0] = 0 ;config[i] = x[i]
	for(int i=1; i<=n; i++){
		total_time+= 2*cur_coord*visits[i].first;

		if(i%2 == 1){
			config[visits[i].second] = cur_coord;
		}else{
			config[visits[i].second] = -cur_coord;
			cur_coord++;
		}

	}
	cout<<total_time<<endl;
	for(auto pos:config)
		cout<<pos<<" ";
	cout<<endl;
}	

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t=1;
	cin>>t;
	while(t--)
		solve();
}