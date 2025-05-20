/*As per the question, each element can be of range [ai-x,ai+x] to be satsified by V presence.
Now the number of lines which has intersection atleast at a point in this range can use same value.
Here each line represents range of each element.So as long as there is intersection you can use the same V value.
How to know the overlap take 5 lines of different range, how do you find intersection,you will take the max of all left
and min of all right to get the point. In the same way take l,r of first segment initially, and compare with subsequent intervals
If any point l is greater than r means there is no intersection and increase count */


#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n,x;
        cin >> n >> x;
        vector<long long>a(n);
        for(int i=0;i<n;i++)
            cin >> a[i];
        vector<pair<long long,long long>>segments(n);
        for(int i=0;i<n;i++){
            segments[i]={a[i]-x,a[i]+x};
        }
        long long l=segments[0].first;
        long long r=segments[0].second;
        long long ans=0;
        for(int i=1;i<n;i++){
            l=max(l,segments[i].first);
            r=min(r,segments[i].second);
            
            if(l>r){
                ans++;
                l=segments[i].first;
                r=segments[i].second;
            }
        }
        cout << ans << endl;
        
    }
    return 0;
}