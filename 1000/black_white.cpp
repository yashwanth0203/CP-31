/*Solution is simple, you need to find the segments with minimum W, it can be done in O(n**2)
with two loops from i=0 to n and j=i to i+k. Efficient approach would be count all these in prefix 
sum and access it in O(1) time*/


#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<long long>prefix(n+1,0);
        for(int i=0;i<n;i++){
            prefix[i+1] = prefix[i] + (s[i]=='W');
        }
        long long min_cells = INT_MAX;
        for(int i=0;i<=n-k;i++){
            long long diff = prefix[i+k]-prefix[i];
            min_cells = min(min_cells,diff);
        }
        cout << min_cells << endl;
    }
}