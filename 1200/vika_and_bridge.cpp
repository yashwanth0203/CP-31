/*WHat do we need to find? Minimum max distance vika could jump, so Vika starts jump before 0 and lands at n+1;
She has to jump on same color. So this difference should be minimised, so what do you do? Check the max difference for each 
color. How you do this? Take a colors array which stores all the indices of its presence along with 0 and n+1, why 0 and n+1?
Because she will jump from 0 to first occurence and lands at n+1 from last occurence, so these are also jumps. So make an array 
noting occurence of each color with respective indices along with start(0) and end(n+1). Whats next, finding max jump in each color?
How to calculate this difference between two elements - 1 ? Why - 1? When we are calculating jumps , we should see only the planks
between source and destination, now ok, you found max at each color, whats next? In question it says one plank can be repainted
so what do yu do? Lets say there is plank 1 and plank 6 , painting at which plank would minimise jumps value? Ofcourse middle.
Now 2 cases arise, if max jump is odd or even , if its odd, then two jumps would be of equal.size. If its odd, one jump would be of size (n/2)
and other would be (n/2) -1 , now since the older jump is no longer there, remove max jump and insert these new two jumps. Now to find max
its lengthy to sort everytime, so take priority queue, so its easy to take max jump, calculate two jumps from it, insert back and find max
from resultant array. This way you do it for all the colors and you would get the max among all the colors.*/

#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        vector<int>v(n+1);
        for(int i=1;i<=n;i++)
            cin >> v[i];
        vector<int>colors[k+1];
        for(int i=1;i<=k;i++){
            colors[i].push_back(0);
        }
        for(int i=1;i<=n;i++){
            colors[v[i]].push_back(i);
        }
        for(int i=1;i<=k;i++){
            colors[i].push_back(n+1);
        }
        priority_queue<int>jumps[k+1];
        int ans = INT_MAX;
        
        for(int i = 1;i<=k;i++){
            for(int j = 0; j < (int)colors[i].size()-1; j++){  // Fix: j < size-1
                jumps[i].push(colors[i][j+1] - colors[i][j] -1);
            }
            if(!jumps[i].empty()){  // Fix: Check if queue is not empty
                int max_val = jumps[i].top();
                jumps[i].pop();
                if(max_val % 2 ==0){
                    jumps[i].push(max_val/2);
                    jumps[i].push((max_val/2) - 1);
                }
                else{
                    jumps[i].push(max_val/2);
                    jumps[i].push(max_val/2);
                }
                if(!jumps[i].empty()){  // Fix: Check again before accessing top
                    ans = min(ans, jumps[i].top());
                }
            }
        }
        cout << ans << endl;
    }
}