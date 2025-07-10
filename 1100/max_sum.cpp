#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        // Sort the array
        sort(a.begin(), a.end());
        
        // Build prefix sum array
        vector<long long> pr(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pr[i + 1] = pr[i] + a[i];
        }
        
        long long ans = 0;
        
        // Try all possible combinations of operations
        // i = number of "remove two minimums" operations
        // (k-i) = number of "remove one maximum" operations
        for (int i = 0; i <= k; i++) {
            // Check if we have enough elements to remove
            if (2 * i + (k - i) <= n) {
                // Remaining elements are from index 2*i to n-1-(k-i)
                // Sum = pr[n-(k-i)] - pr[2*i]
                ans = max(ans, pr[n - (k - i)] - pr[2 * i]);
            }
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}