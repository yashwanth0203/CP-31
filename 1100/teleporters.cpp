/*We are to maximise teleports, so what would we do ? Come back to 0 as many times possible. Whats the cost to come 
back from index i, i+arr[i]. Are these dependent on each other?No., you have to start from 0 everytime. So sort according to
their costs and iterate until you run out of c, print out the no of iterations*/


#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n,c;
        cin >> n >> c;
        vector<long long>cost;
        long long x;
        for(long long i=1;i<=n;i++){
            cin >> x;
            cost.push_back(x+i);
        }
        sort(cost.begin(),cost.end());
        long long i=0;
        long long ans=0;
        while(i<n && cost[i] <= c){
            c-=cost[i];
            ans++;
            i++;
        }
        cout << ans << endl;
    }
    return 0;
}