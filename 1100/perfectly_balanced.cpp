/*As long as the string is periodic, no matter the substring you take, all the consecutive elements are present atleast once,
So find if string is periodically unique or not*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = (int)s.size();
        set<char> char_set; 
        int k = 0;
        
        for(k = 0; k < n; k++){
            if(char_set.find(s[k]) == char_set.end()){
                char_set.insert(s[k]);
            }
            else{
                break;
            }
        }
        

        bool valid = true;
        for(int i = k; i < n; i++){
            if(s[i] != s[i - k]){ 
                valid = false;
                break;
            }
        }
        
        if(valid){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}