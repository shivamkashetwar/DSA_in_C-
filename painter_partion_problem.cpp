class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        int n = a.size();
        if (n == 1) return a[0];

        // Boundary checks for first and last elements
        if (a[0] != a[1]) return a[0];
        if (a[n - 1] != a[n - 2]) return a[n - 1];

        // Search in the range [1, n - 2] to safely access mid - 1 and mid + 1
        int st = 1, end = n - 2;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            // Found the single element
            if (a[mid] != a[mid - 1] && a[mid] != a[mid + 1]) {
                return a[mid];
            }

            // Decide which half to search
            if (mid % 2 == 0) {
                if (a[mid] == a[mid + 1]) {
                    st = mid + 1; // Partner is on the right, single element is further right
                } else {
                    end = mid - 1; // Partner is on the left, single element is on the left
                }
            } else {
                if (a[mid] == a[mid - 1]) {
                    st = mid + 1; // Partner is on the left, single element is further right
                } else {
                    end = mid - 1; // Partner is on the right, single element is on the left
                }
            }
        }

        return -1;
    }
};