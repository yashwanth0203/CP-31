/* We will start iterating from 1 to n , and check at each multiple if its removed or not, if its not removed
it means any number further cant use the current number as its divisor


Example:
For s = "0010"

Position 1 → '0' → removed by 1 → add 1

Position 2 → '0' → removed by 1 → add 1

Position 3 → '1' → stop removing further multiples

Position 4 → '0' → removed by 2 → add 2

Total = 1 + 1 + 2 = 4 ✅

We stop checking a position's multiples if we find a '1' — like we stop at position 3 here.*/



#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        long long ans = 0;

        vector<bool> isRemoved(n + 1, false); //! stores whether an element is removed or not

        for (int i = 1; i <= n; i++) //? k = 2, 6 s[5] = '1',cannot delete multiples of 2 after 6
        {
            for (int j = i; j <= n; j += i)
            {
                if (s[j - 1] == '1')
                    break;

                if (isRemoved[j])
                    continue;
                else
                {
                    isRemoved[j] = true;
                    ans += i;
                }
            }
        } //! O(n log n)

        cout << ans << "\n";
    }

    return 0;
}

//! Total time complexity : O(n log n)
//! Total space complexity : O(n)