#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        sort(nums.begin(), nums.end()); 
        for(int i = 0; i < n; i++) {
            if(i > 0 && nums[i] == nums[i-1]) {
                continue;  
            }
            int j = i + 1;
            int k = n - 1;
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < 0) {
                    j++;  
                } else if(sum > 0) {
                    k--;  
                } else {
                    result.push_back({nums[i], nums[j], nums[k]});
                    // Move the left pointer right and skip duplicates
                    j++;
                    while(j < k && nums[j] == nums[j-1]) {
                        j++;
                    }
                    // Move the right pointer left and skip duplicates
                    k--;
                    while(j < k && nums[k] == nums[k+1]) {
                        k--;
                    }
                }
            }
        }

        return result;
    }
};