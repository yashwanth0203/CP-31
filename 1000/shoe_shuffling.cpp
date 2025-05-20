/*One simple logic is unique , if there is unique size, solution is invalid. Why?Even if you exchange your size with greater than yours
Who would they exchange with? They need someone of same size right. So now if they are of same size, we have to shuffle , how? Keep track
of left and right pointers. Iterate r until [l,r] elements are same.rotate function in STL left shift elements by middle parameter in the range
(left,right) parameters. Now since all this is done, what if last two elements are similar and didnt rotate because they couldnt go to else
rotate outside again, done*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        vector<long long>sizes(n);
        for(int i=0;i<n;i++)
            cin >> sizes[i];
        map<long long,long long>freq;
        for(int i=0;i<n;i++)
            freq[sizes[i]]++;
        long long flag=0;
        for(auto i:freq){
            if(i.second==1){
                flag=1;
                break;
            }
        }
        if(flag){
            cout << -1 << endl;
            continue;
        }
        vector<long long>students(n);
        for(int i=0;i<n;i++)
            students[i]=i+1;
        long long l=0,r=0;
        while(r<n){
            if(sizes[l]==sizes[r])r++;
            else{
                rotate(students.begin()+l,students.begin()+l+1,students.begin()+r);
                l=r;
            }
        }
        rotate(students.begin()+l,students.begin()+l+1,students.begin()+r);
        for(auto x:students)
            cout << x << " ";
        cout << endl;
    }
}