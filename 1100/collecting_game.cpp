/*Its evident that the lowest element would have always have value 0 since it cant eat any other numbers
while the largest can engulf all the rest, so we have to check only for rest elements, now tell me, whats the score
of current element, its the sum of all the elements till now, so can it take down next element to it? If the sum 
till now(score) is greater than next number, then the number would be same as next.*/




#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long>a(n),b(n),psum(n);
        for(int i=0;i<n;i++){
            cin >> a[i];
            b[i]=a[i];
        }

        sort(b.begin(),b.end());
          psum[0]=b[0];        
        for(int i=1;i<n;i++){
            psum[i]=psum[i-1]+b[i];
        }
      
        map<long long,long long>mp;
        mp[b[n-1]]=n-1;
        for(int i=n-2;i>=0;i--){
            if(psum[i]>=b[i+1])mp[b[i]]=mp[b[i+1]];
            else mp[b[i]]=i;
        }
        for(auto i:a){
            cout << mp[i] << " ";
        }
        cout<<endl;
    }
}