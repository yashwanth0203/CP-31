/*Initially, the leader chooses the resident with the lowest sharing cost (B[i]) to inform directly, ensuring cost-effective future sharing. 
From there, the announcement is propagated by always selecting the informed resident who can share to others at the lowest cost, while respecting 
their limit (A[i]) on how many people they can notify. A priority mechanism is used to determine the next best person to share with, prioritizing 
cheaper propagation paths. If necessary, the leader may inform additional residents directly if it reduces the overall cost.*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, p;
        cin >> n >> p;
        vector<pair<long long, long long> > v(n);
        vector<long long> a(n), b(n);

        for (int i = 0; i < n; i++) // n
            cin >> a[i];

        for (int i = 0; i < n; i++) // n
            cin >> b[i];

        for (int i = 0; i < n; i++) // n
            v[i] = {b[i], a[i]};

        sort(v.begin(), v.end()); // nlogn

        long long minimum_cost = p;
        long long already_shared = 1;

        for (auto it : v) // n
        {
            long long can_be_shared = it.second;
            long long sharing_cost = it.first;

            if (sharing_cost >= p)
                break;

            if (already_shared + can_be_shared > n)
            {
                minimum_cost += (n - already_shared) * sharing_cost;
                already_shared = n;
                break;
            }
            else
            {
                minimum_cost += can_be_shared * sharing_cost;
                already_shared += can_be_shared;
            }
        }

        minimum_cost += (n - already_shared) * p; // chief sharing
        cout << minimum_cost << endl;
    }
    return 0;
}

// TC - O(nlogn) = O(10^5(log2(10^5))) = O(10^5 * 17) = O(1.7 * 10^6)
// SC - O(n) = O(10^5)