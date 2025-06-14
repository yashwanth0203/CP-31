/*If there must be less reds be consecutive then blue must be distributed evenly. There will be b+1 regions
for red to accommodate, allocate equally among all ,and start adding from first if theres any extra*/


#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,r,b;
        cin >> n >> r >> b;
        string s;
        int red_length = r/(b+1);
        int extra = r%(b+1);
        
        for(int times = 1 ; times <=b+1;times++){
            for(int i=0;i<red_length;i++){
                s+='R';
            }
            if(extra > 0){
                s+='R';
                extra--;
            }
            if(times!=b+1){
                s+='B';
            }
        }
        cout << s << endl;
    }
}