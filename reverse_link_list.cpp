class Solution {
public:
    unordered_map<pair<int, int>, bool> cache;

    bool dfs(int i, int j, string& s, string& p) {
        // Check cache
        if (cache.find({i, j}) != cache.end()) {
            return cache[{i, j}];
        }

        // Both strings are completely matched
        if (i >= s.length() && j >= p.length()) {
            return true;
        }

        // Pattern is finished, but string is not
        if (j >= p.length()) {
            return false;
        }

        // Check if current characters match
        bool match = i < s.length() &&
                     (s[i] == p[j] || p[j] == '.');

        bool result;

        // If next pattern character is '*'
        if (j + 1 < p.length() && p[j + 1] == '*') {
            result = dfs(i, j + 2, s, p) ||
                     (match && dfs(i + 1, j, s, p));
        }
        // Normal character match
        else if (match) {
            result = dfs(i + 1, j + 1, s, p);
        }
        else {
            result = false;
        }

        // Store result in cache
        cache[{i, j}] = result;

        return result;
    }

    bool isMatch(string s, string p) {
        return dfs(0, 0, s, p);
    }
};