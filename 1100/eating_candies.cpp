/*Self explanatory*/


#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>candies(n,0);
        for(int i=0;i<n;i++){
            cin >> candies[i];
        }
        int left=0;
        int right = n-1;
        int left_sum=candies[0];
        int right_sum=candies[n-1];
        int res = 0;
        while(left<right){
            if(left_sum < right_sum){
                left++;
                left_sum+=candies[left];
            }
            else if(left_sum > right_sum){
                right--;
                right_sum+=candies[right];
            }
            else{
                int curr_max = left+1 + (n-right);
                res= max(res,curr_max);
                left++;
                left_sum+=candies[left];
                right--;
                right_sum+=candies[right];
            }
        }
        cout << res << endl;
    }
}