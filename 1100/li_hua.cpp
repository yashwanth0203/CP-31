/*After rotating by 180 deg, (i,j) will become (n-1-i,n-j-1).
So check if these are same , else add it to count, then half the total count coz u need to change any one cell
Now see if count is greater than no of ops, print false, if there are more and still left check if the rest is even,
if its even applying the same on any cell doesnt change color for even n unlike odd(it works only for odd where middle cell remains same irrespective of rotation), so print likewise*/


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n,k;
        cin >> n >> k;
        ll arr[n][n];
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                cin >> arr[i][j];
            }
        }
        ll count =0;
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                if(arr[i][j] != arr[n-1-i][n-1-j])count++;
            }
        }
        count/=2;
        if(count > k)cout << "NO" << endl;
        else{
            ll temp = count-k;
            if(temp%2==0)cout << "YES" << endl;
            else {
                if(n%2)cout << "YES" << endl;
                else cout << "NO" << endl;
            }
        }
    }
}