// C++ program to find longest sub-array having sum k
// using Hash Map and Prefix Sum

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Function to find longest sub-array having sum k
int longestSubarray(vector<int>& arr, int k) {
    unordered_map<int, int> mp;
    int res = 0;
    int prefSum = 0;

    for (int i = 0; i < arr.size(); ++i) {
        prefSum += arr[i];

        // Check if the entire prefix sums to k
        if (prefSum == k) 
            res = i + 1;

        // If prefixSum - k exists in the map then there exist such 
      	// subarray from (index of previous prefix + 1) to i.
        else if (mp.find(prefSum - k) != mp.end()) 
            res = max(res, i - mp[prefSum - k]);

        // Store only first occurrence index of prefSum
      	if (mp.find(prefSum) == mp.end())
            mp[prefSum] = i;
    }

    return res;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n,s;
        cin >> n >> s;
        vector<int>v(n);
        for(int i=0;i<n;i++)
            cin >> v[i];
        int len = longestSubarray(v, s);
        if (len == 0)
            cout << -1 << endl;
        else
            cout << n - len << endl;
    }
    return 0;
}