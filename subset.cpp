

class Solution {
public:
   vector<int> spiralOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        
        // Edge case: empty matrix
        if (mat.empty() || mat[0].empty()) {
            return ans;
        }

        int m = mat.size(), n = mat[0].size();
        int srow = 0, scol = 0, erow = m - 1, ecol = n - 1;
        
        while (srow <= erow && scol <= ecol) {
            
            // 1. Traverse Top Row
            for (int j = scol; j <= ecol; j++) {
                ans.push_back(mat[srow][j]);
            }
            
            // 2. Traverse Right Column
            for (int i = srow + 1; i <= erow; i++) {
                ans.push_back(mat[i][ecol]);
            }
            
            // 3. Traverse Bottom Row
            for (int j = ecol - 1; j >= scol; j--) {
                // Prevent duplicate traversal if there's only one row left
                if (srow == erow) {
                    break;
                }
                ans.push_back(mat[erow][j]);
            }
            
            // 4. Traverse Left Column
            for (int i = erow - 1; i >= srow + 1; i--) {
                // Prevent duplicate traversal if there's only one column left
                if (scol == ecol) {
                    break;
                }
                ans.push_back(mat[i][scol]);
            }
            
            // Shrink the boundaries
            srow++;
            erow--;
            scol++;
            ecol--;
        }

        return ans;
    }
};