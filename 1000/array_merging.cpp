/* Simple find the longest subarray of each occurence in A and B. Add them if both are matched and take 
max among all of them*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        vector<long long>a(n,0),b(n,0);
        set<long long>elements;
        for(int i=0;i<n;i++){
            cin >> a[i];
            elements.insert(a[i]);
        }
        for(int i=0;i<n;i++){
            cin >> b[i];
            elements.insert(b[i]);
        }
        
        unordered_map<long long, long long>mp1,mp2;
        mp1[a[0]]=1;
        long long count = 1;
        for(int i=1;i<n;i++){
            if(a[i]==a[i-1]){
                count++;
            }
            else{
                count =1;
            }
            mp1[a[i]]=max(mp1[a[i]],count);
        }
        
        mp2[b[0]]=1;
        count = 1;
        for(int i=1;i<n;i++){
            if(b[i]==b[i-1]){
                count++;
            }
            else{
                count =1;
            }
            mp2[b[i]]=max(mp2[b[i]],count);
        }
        long long res=1;
        for(auto e : elements){
            res = max(res,mp1[e]+mp2[e]);
        }
        cout << res << endl;
    }
}