/*Simple if there are even negatives, they can be ruled out with each other and we would everything positive, so sum is array sum.
Now if there is odd negatives, we are trying to maximise sum, so we are trying to push that one negative sign to the absolute least.
So we will calculate sum, make all elements positive, if its odd subtract 2*a[0] since you would have added it already else print array sum*/



#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        ll sum = 0;
        int negs = 0;
        for(int i = 0; i < n; ++i) {//N
            cin >> a[i];
            if(a[i] < 0) {
                ++negs;
                a[i] = -a[i];
            }
            sum += a[i];
        }
        sort(a.begin(), a.end());//NLOGN
        if(negs & 1) sum -= 2 * a[0];
        cout << sum << "\n";
    }
    // T.C :- O(nlogn)
    // S.C :- O(n)
}