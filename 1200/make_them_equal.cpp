/*Lets see the solution, we have te replace char only if its not divisible by chosen x.Lets count no of chars which are not c
If its 0, then no need to replace. Also, a trick we can understand is larger the number the less divisible the elements would be.
So check last char, if it doesnt need replacement, the number should be n since none of other indices would be divisible by that.
So essentially we are finding last proper character index. Now if last isnt expected char, come from end and check which index has expected character.
If that index is greater than n/2, then we can assume output is 1. Why? Becuase the next multiple of that number would be greater than n. So all the 
elements arent divisible by this index. If the index found is < n/2,it means a multiple exist for it in the index itself, but we are not sure how many, there
can be more than 2. Whats the safe bet? Lets take last two indices values n and n-1, if we take n-1 everything would be changed except n-1 and in the next
iteration take n and n-1 can also be replaced and thus output is 2.*/



#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
signed main(){
  fastio();
#ifndef ONLINE_JUDGE
freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif
    int t ; cin>>t;
    while(t--){
        int n; cin>>n;
        char c; cin>>c;
        string s; cin>>s;
        int ct=0;
        for(int i=0; i<n ; i++){
          if(s[i]!=c){
           ++ct; 
        }
        }
        if(ct==0){
          cout<<0<<endl;
        }
        else if(s[n-1]==c){
          cout<<1<<endl;
          cout<<n<<endl;
        }
        else{
          int flag=0;
          for(int i=n-1; i>=0; i--){
            if(s[i]==c){flag=i+1; break;}
          }
          if(flag>n/2){
            cout<<1<<endl;
            cout<<flag<<endl;
          }
          else{
            cout<<2<<endl;
            cout<<n-1<<" "<<n<<endl;
          }
        }
        }    
return 0;
}