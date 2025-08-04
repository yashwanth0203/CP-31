#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int &ai : a) cin >> ai;
        sort(a.begin(), a.end());

        // Prefix sum of a[i]
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i)
            prefix[i + 1] = prefix[i] + a[i];

        int ans = 0;
        for (int k = 1; k <= n; ++k) {
            // Check how many days we can buy first k items
            // Price of buying first k items on day d is: prefix[k] + k * (d - 1)
            // Solve: prefix[k] + k * (d - 1) <= x  ->  d <= (x - prefix[k]) / k + 1
            if (prefix[k] > x) continue;
            int max_days = (x - prefix[k]) / k + 1;
            ans += max_days;
        }

        cout << ans << "\n";
    }

    return 0;
}
