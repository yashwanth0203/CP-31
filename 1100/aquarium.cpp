/*Well the question says it height should be maximum at the same time fulfilling max extra water constraint
So what would you do ? Iterate linearly and check at every height if max water is fulfilled along with it
Now that wouldnt work because of constraints, so just do binary search, phew done*/





#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n,x;
        cin >> n >> x;
        vector<long long>tank(n);
        for(long long i=0;i<n;i++)
            cin >> tank[i];
        long long l=0,r=1e10;
        while(l < r-1) {
            long long total_water =0;
            long long curr_height = l +(r-l)/2;
            for(long long i=0;i<n;i++){
                if(tank[i] < curr_height){
                    total_water += (curr_height - tank[i]);
                }
            }
            if(total_water > x){
                r = curr_height;
            }
            else {
                l = curr_height;
            }
        }
            cout<< l << endl;
    }
}