/* How to ensure equal distribution of boxes, all trucks must be divisior of total number of boxes.
Lets say there are 6 boxes, it can be loaded into 6 trucks of 1 box each, 2 trucks of 3 box each and 3 trucks of 2 box each.
Now we shouldnt alter the order, so we need to maximum abs difference between any possibility.
For 1 box in each truck , the max is largest box minus smallest box, for 2 boxes each in 3 trucks it would also be same and so on.
Now we need to find all those possibilities,we will take prefix sum because the sums of each combo can be found in O(1) time, 
lets say 3 and 4th box is loaded in a truck of combo having 3 trucks , whats the sum , its difference of prefix_sum at 4th box - prefix sum at 2nd box, since we need to
eliminate first 2 boxes,in the code we followed 1 based indexing for psum, also i denotes no of boxes, so it makes sense to start at 1
*/



#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long b,n,resMax=0;
        cin >> n;
        vector<long long>pre;
        long long sum=0;
        pre.push_back(0);
        for(long long i=0;i<n;i++){
            cin >>b;
            sum+=b;
            pre.push_back(sum);
        }
        
        for(long long i=1;i<=n;i++){
            vector<long long>v;
            if(n%i == 0){
                for(long long j=i;j<=n;j+=i){
                    sum = pre[j]-pre[j-i];
                    v.push_back(sum);
                }
                sort(v.begin(),v.end());
                resMax=max(resMax,v[(long long)v.size() - 1] - v[0]);
            }
        }
        cout << resMax << endl;
    }
}