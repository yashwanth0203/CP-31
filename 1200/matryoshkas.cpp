/*Here we are just finding no of non consecutive non-repetitive groups, thats the answer. 
Lets say we have 5,6,6,8,9,11,12,14,15. What are the groups? (5,6)(6)(8,9)(11,12)(14,15)
We will start with 5 , there is no four so 1-0 = 1, so it means 1 group has started with 5 in it.
Next when it comes to 6 its 2 -1 =1 , so one more group started with 6 in it, the other 6 is been subtracted.
Similarly it goes to 8 , there is no previous , so new chain starts, then goes to 9 diff is 0 . so chain continue.
Again it breaks after 9,13,16. */



#include <bits/stdc++.h>

using namespace std;

int main()
{
   int t;
   cin >> t;

   while (t--)
   {
      int n;
      cin >> n;

      vector<int> v(n);

      for (int i = 0; i < n; i++)
         cin >> v[i]; //? O(N)

      map<int, int> cnt;

      for (int i = 0; i < n; i++)
         cnt[v[i]]++; //? O(N log N)

      int ans = 0; //! x

      for (auto &[ele, fre] : cnt) //! ele = .first, fre = .second
      {
         ans += max(0, cnt[ele] - cnt[ele - 1]);
      } //? O(N log N)

      cout << ans << "\n";
   }
}

//! Total time complexity : O(N log N)
//! Total space complexity : O(N)