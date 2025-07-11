/*Now what would you think initially, lets take the first element where is difference and last element and 
print both the indices. But there are some other cases, lets say you have 1 7 5 3 0 and a' is 1 3 5 7 0 .
Now what we would have done since difference started at 7 and ended at 3 we will print 2 and 4, but they asked largest,
wouldnt we have sorted from 1 to 4, it would also be the same right? So first find left and right indices where elements
are differed and iterate left and right accordingly as long as its sorted.*/
#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int main()
{
    fio;
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        int brr[n];
        for(int i = 0; i < n; i++)
            cin >> brr[i];
        int len = 0;
        int l = -1, r = -1;
        for (int i = 0; i < n; i++)
        {
            if(arr[i] != brr[i])
            {
                if(l == -1) l = i;
                r = i;
            }
        }
        while(l > 0 && brr[l - 1] <= brr[l])l--;
        while(r + 1 < n && brr[r + 1] >= brr[r])r++;
        cout << l + 1 << ' ' << r + 1 << '\n';
    }

    return 0;
}
