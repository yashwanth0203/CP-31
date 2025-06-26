/*If a number has to be the sum of other numbers, there must be nubers which are repeated
Refer bitwise concepts
*/


#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        vector<long long>values(n,0);
        unordered_set<long long>s;
        for(long long i=0;i<n;i++){
            cin >> values[i];
            s.insert(values[i]);
        }
        if(s.size() < n)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}