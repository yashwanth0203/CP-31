/*We need sum of pairwise differences of all arrays, but the arrays we have are of each player. What if we just rotate matrix, like we get array of 
1st number in one row and so on. It would be easy to calculate right? Now within same position on each card what do we do ? Take absolute difference for each 
nmber right. Lets say you have 1,2,3 how many times 1 would be subtracted?2 times because 2 numbers are greater than it, for 3 its 0 but it gets added 2 times.
Now you may say 3 adding 2 times doesnt count into (3-1) or (3-2) right, but these -2 and -1 we would have already subtracted from sum as stated previously*/



#include <bits/stdc++.h>
using namespace std;


void solve()
{
    
    long long n,m; 
    cin>>n>>m;
    long long i,j;
    vector<vector<long long>>v(n,vector<long long>(m));
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    long long cnt=0;
    for(j=0;j<m;j++){
        vector<long long>tmp;
        for(i=0;i<n;i++) tmp.push_back(v[i][j]);
        sort(tmp.begin(),tmp.end());
        for(i=0;i<n;i++) {
            cnt+=i*tmp[i];
            cnt-=(n-i-1)*tmp[i];
        }
 
    }
    cout<<cnt<<endl;
 
 
    
}
 
 
int main(){
    long long t=1;
    cin>>t;
    cout<<setprecision(16);
    for(int i=1; i<=t; i++){
       solve();
    }
    return 0;
}