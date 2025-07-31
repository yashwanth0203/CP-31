/*Whats the question? Find the max no of groups wherein the diff is positive(bought(x) < capacity(x)).
The min size of group is always 2. So take difference and store it in a array. Now sort it, the highesht diff
would be at extreme ends, if the left most are negatives, you know that they had to paired with something positive in right to get that group
What if i+j is still negative? we have to add another from right so 2 rights+ one left. But it makes no groups less , so just ignore left and move on*/


#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>x(n),y(n);
        for(int i=0;i<n;i++)
            cin >> x[i];
        for(int i=0;i<n;i++)
            cin >> y[i];
        vector<int> diff(n);
        for(int i=0;i<n;i++)
            diff[i] = y[i] - x[i];
        sort(diff.begin(),diff.end());
        int i=0,j=n-1;
        int ans=0;
        while(i<j){
            int sum = diff[j]-diff[i];
            if(sum < 0) i++;
            else{
                i++;
                j--;
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}