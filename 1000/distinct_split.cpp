/*Brute force is check in all possible splits(by forming substring) and find the best split.
Better approach is to take two maps left and right. Let right contain all the elements with their
frequency initially. As we iterate, add elements to left and remove from right accordingly. If the
count is 1 in right, it means element is no longer present after iteration hence remove that element.
At each step take lengths of two maps and find max among all iterations*/


#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        vector<char>s(n,'0');
        for(int i=0;i<n;i++)
            cin >> s[i];
        unordered_map<char, int> mp1, mp2;
        
     
        for(int i = 0; i < n; i++) {
            mp2[s[i]]++;
        }

        int maxi = 2;  
        
        for(int i = 0; i < n-1; i++) {
            mp1[s[i]]++;
            if(mp2[s[i]] == 1) {
                mp2.erase(s[i]);
            } else {
                mp2[s[i]]--;
            }
            int candidate = mp1.size()+mp2.size();
            maxi = max(maxi, candidate);
        }
        
        cout << maxi << endl;
    }
    
    return 0;
}
