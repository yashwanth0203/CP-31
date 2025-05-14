/*Simple thing is we are dividing each element by k and add all these it should be b.
Sum of all elements must be a. So essentially (a1/k + a2/k ... = b , a1+a2+a3 = s),hence k*b=s.
Now they will give a certain k b and s, you have to make an array out of these for n elements.
Think of what could be the minimum sum, it should be when each element is divisible by k so sum is k*b.
When the sum is max, what does that mean? It means we have to make ai/k 0 as much as possible. So why not ai be k-1
Ok also one number must be k*b+(k-1) because this number gives min sum + k-1 means essentially same b value.
So check if any sum is in this range, if yes form an array*/




#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n,k,b,s;
        cin >> n >> k >> b >> s;
        long long minimum_s = k*b;
        long long maximum_s = k*b + n*(k-1);
        
        if(s > maximum_s || s<minimum_s){
            cout << -1 << endl;
        }
        else{
            vector<long long>a(n,0);
            a[0] = minimum_s;
            s-=minimum_s;
            for(long long i=0;i<n;i++){
                long long num=min(k-1,s);
                a[i]+=num;
                s-=num;
            }
            for(long long i=0;i<n;i++){
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}