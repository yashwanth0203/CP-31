/*Simple , find the length of longest common substring and subtract extra ones
from both strings, thats the answer. Revise again b/w this and LCS. Standard DP questions*/

#include <bits/stdc++.h>
using namespace std;

int solve(string &a, string &b) {
    int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    
    for(int i = 0; i <= n; i++) dp[i][0] = 0;
    for(int j = 0; j <= m; j++) dp[0][j] = 0;
    
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                ans = max(ans, dp[i][j]);
            }
            else {
                dp[i][j] = 0;
            }
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        string a, b;
        cin >> a >> b;
        int res = solve(a, b);
        cout << a.size()+b.size()- 2*res << endl; 
    }
    return 0; 
}