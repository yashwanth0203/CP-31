/*Basically the problem states to calculate minimum deletions of none or more occurences of a single character to make
the string palindrome. So we will iterate from a to z and take two pointers and try to remove them if those dont match with each
and add count, if left and right , not even one of them is equal to iterating char, you cant remove so just assign a max value and break.*/



#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        string s;
        cin >> s;
        long long ans = 1e9;
        
        for(int i ='a';i<='z';i++){
            long long change =0;
            long long low =0,right = n-1;
            while(low<= right){
                if(s[low] != s[right]){
                    if(s[low] == i){
                        change++;
                        low++;
                    }
                    else if(s[right] == i){
                        change++;
                        right--;
                    }
                    else {
                        change = 1e9;
                        break;
                    }
                }
                else{
                    low++;
                    right--;
                }
            }
            ans = min(ans,change);
        }
        if (ans == 1e9)cout << -1 << endl;
        else cout << ans << endl;
    }
}