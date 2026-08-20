class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int tar) {
        vector<vector<int>> ans;
        int n = nums.size();
        
        // Sorting is required for the two-pointer approach and handling duplicates
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            // Skip duplicates for the first number
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n; j++) {
                // Skip duplicates for the second number
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int p = j + 1, q = n - 1;

                while (p < q) {
                    // Use long long to prevent integer overflow when adding 4 large numbers
                    long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[p] + (long long)nums[q];

                    if (sum > tar) {
                        q--;
                    } else if (sum < tar) {
                        p++;
                    } else {
                        // Match found
                        ans.push_back({nums[i], nums[j], nums[p], nums[q]});
                        p++;
                        q--;
                        
                        // Skip duplicates for the third and fourth numbers
                        while (p < q && nums[p] == nums[p - 1]) p++;
                        while (p < q && nums[q] == nums[q + 1]) q--;
                    }
                }
            }
        }
        
        // Correctly placed inside the function
        return ans;
    }
};