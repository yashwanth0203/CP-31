/*Just like aquarium problem where you had to find height to satisfy atmost max water, here we need to satisy area C
Used same binary search , so byheart this template, only logic changes thats it*/


#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n,c;
        cin >> n >> c;
        vector<long long>board(n);
        for(long long i=0;i<n;i++)
            cin >> board[i];
        long long l=0,r=1e10;
        while(l < r-1) {
            long long total_sum =0;
            long long curr_size = l +(r-l)/2;
            for(long long i=0;i<n;i++){
                    total_sum += (board[i]+2*curr_size)*(board[i]+2*curr_size);
                    if(total_sum > c)break;
            }
            if(total_sum > c){
                r = curr_size;
            }
            else {
                l = curr_size;
            }
        }
            cout<< l << endl;
    }
}