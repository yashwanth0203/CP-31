/*Minimizing costs mean to make as many swaps as possible. So for that there needs to equal ones and zeros. Swap until then then rest difference is the result*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int count_ones=0;
        int count_zeros=0;
        
        for(int i=0;i<s.length();i++){
            if(s[i]=='0')count_zeros++;
            else count_ones++;
        }
        
        int ts=0;
        for(int i=0;i<s.length();i++){
            if(s[i]== '0' && count_ones > 0){
                count_ones--;
                ts++;
            }
            else if(s[i]== '1' && count_zeros > 0){
                count_zeros--;
                ts++;
            }
            else 
                break;
        }
        cout << s.length() - ts << endl;
    }
    return 0;
}