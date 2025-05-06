/*Essentially you need to find the number of subarrays of length atleast k with all 1's.
 Here 1 represents value less than or equal to k.Now the formula of different ways is (n*n+1)/2,
 where n is count of ones-k+1 for one subarray*/


#include <bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin >> t;
    while(t--){
        long long n,k,q;
        cin >> n >> k >> q;
        vector<int>a(n,0);
        for(int i=0;i<n;i++){
            cin >> a[i];
            a[i] = (a[i]>q) ? 0 : 1;
        }
        
        long long count_ones=0;
        long long ways =0;
        for(int i=0;i<n;i++){
            if(a[i]==1){
                count_ones++;
            }
            else{
                if(count_ones >= k){
                    long long diff = count_ones-k+1;
                    ways+=(diff*(diff+1))/2;
                }
                count_ones=0;
            }
        }
        if(count_ones >= k){
                    long long diff = count_ones-k+1;
                    ways+=(diff*(diff+1))/2;
                }
        cout << ways << endl;
    }
    return 0;
}