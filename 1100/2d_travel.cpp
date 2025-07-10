/*Need to fly b/w two cities, if traveled through major cities at both ends, its free.
So you will try to find nearest major to source and calculate fare, same with destination.
Now compare this with what if you went directly from source to destination. Pick the one
with least total fare.




Also remember to use LLONG_MAX/2 for initial min, dont use LLONG*/




#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n,k,a,b;
        cin >> n >> k >> a >> b;
        vector<long long>x(n+1),y(n+1);
        for(long long i=1;i<=n;i++){
            cin >> x[i] >> y[i];
        }
        long long price = abs(x[a] - x[b]) + abs(y[a] - y[b]);
        long long min_a = LLONG_MAX/2;
        long long min_b = LLONG_MAX/2;
        for(long long maj = 1;maj <=k;maj++){
            min_a = min(min_a,abs(x[a] - x[maj])+abs(y[a] - y[maj]));
            min_b = min(min_b,abs(x[b] - x[maj])+abs(y[b] - y[maj]));
        }
        cout << min(price,min_a + min_b) << endl;
    }
}