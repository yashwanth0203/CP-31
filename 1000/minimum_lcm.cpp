/*Due to TC solution should be less than or equal to O(sqrt(n)). Now if b is
factor of a,lcm is b. If lcm is b, then n%a ==0(a+b =n , a+ax=n,a(1+x)=n,i.e, a is factor of n).
This is the only case where least LCM is possible which is b.*/


#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        int a =1;
        for(long long i=2;i*i <= n;i++){
            if(n%i==0){
                a = n/i;
                break;
            }
        }
        cout << a << " " << n-a << endl;
    }
    
    return 0;
}
