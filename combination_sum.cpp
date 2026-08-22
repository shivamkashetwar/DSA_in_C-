class Solution {
public:
    void allcom(vector<int>& arr, int idx, int tar, vector<vector<int>>& ans, vector<int>& combin) {
        // Base case: if target is exactly 0, we found a valid combination
        if (tar == 0) {
            ans.push_back(combin);
            return;
        }
        
        // Base case: if we went out of bounds or the target became negative
        if (idx == arr.size() || tar < 0) {
            return;
        }

        // Branch 1: Include the current element
        // Notice how we subtract arr[idx] from tar, and keep idx the same
        combin.push_back(arr[idx]);
        allcom(arr, idx, tar - arr[idx], ans, combin);
        
        // Backtrack: remove the element to explore the next branch
        combin.pop_back();

        // Branch 2: Exclude the current element and move to the next index
        allcom(arr, idx + 1, tar, ans, combin);
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> combin;
        allcom(arr, 0, target, ans, combin);
        return ans;   
    }
};