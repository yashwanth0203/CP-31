/*Brute force approach is to find for each element corresponding right most green light which is 
O(n^2). Better approach is think of iterating from right. You get present greeen index everytime
you encounter green. When you come across the color subtract the green index from color.Thats 
because you update green to nearest right everytime. Now take max among all these and thats the 
answer*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        char color;
        cin >> color;
        string s;
        cin >> s;
        s+=s;
        n*=2;
        long long last_green_index = -1;
        long long max_time = INT_MIN;
        
        for(int i=n-1;i>=0;i--){
            if(s[i]== 'g')
                last_green_index = i;
            if(s[i]==color){
                long long diff = last_green_index - i;
                max_time = max(max_time,diff);
            }
        }
        cout << max_time << endl;
    }
    return 0;
}