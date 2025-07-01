/*We can use DP but constraints dont allow that. Here we need to find no of distinct strings at each level.
Like length n,n-1,n-2 ...1. Length n there will always be 1 because removal of any element would lead to lesser length.
Now from next level lets say distinct length of n-1 , you have to remove either first or second, rest string will be
common for all the combinations. So the number would depend on first n letters(where n is level). Lets say we have
abcab, first level is 1, second level is two (bcab and acab), but at third level its 3 with one repetition(cab,bab,cab,aab).
Here whats 3 ? The number of distinct letters till n(level). Add all these distinct each level. This is answer*/


#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        map<char,int>freq;
        int count=0;
        int res=0;
        for(int i=0;i<n;i++){
            freq[s[i]]++;
            if(freq[s[i]]==1)count++;
            res+=count;
        }
        cout << res << endl;
    }
}