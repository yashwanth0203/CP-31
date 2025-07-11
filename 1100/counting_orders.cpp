/*First we need to find the number of elements greater than each element of array b in array a.
So sort both these arrays and iterate on b array and check the no of elements greaqter than it from a
. Since its sorted it can be done in one iteration.

Now after finding again sort the result, because the current element combo will always have numbers
which are already present.

So lets say we have 2,2,4,6(usually the values can be assumed as lesser the result value, greater the number).
So lets say we use one of 2 numbers, we are left with 2 choices(2-0), similarly in the next2 already one must have already been used so only choice(2-1),
next in 4 ,2 must have been used already(4-2) ..

The pattern is res[i]-i, so multiply for all numbers and thats the answer
 */




#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long>a(n),b(n),res(n);
        for(long long i=0;i<n;i++)
            cin >> a[i];
        for(long long i=0;i<n;i++)
            cin >> b[i];
        int j=0;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        for(int i=0;i<n;i++){
            while(a[j]<=b[i] && j!=n)
                j++;
            if(j!=n)
                res[i]=n-j;
        }
        sort(res.begin(),res.end());
        long long ans=1;
        for(long long i=0;i<n;i++){
            ans = ans%mod * ((res[i]-i)%mod)%mod;
        }
        cout << ans << endl;
    }
}