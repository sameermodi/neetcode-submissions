class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        if (m > n) return "";
        
        unordered_map<char, int> need, have;
        for (char c : t) {
            need[c]++;
        }

        int i = 0, j = 0;
        int formed = 0, required = need.size();
        int minLen = INT_MAX, start = 0;

        while (j < n) {
            char c = s[j];
            have[c]++;

            // check if this char satisfies requirement
            if (need.count(c) && have[c] == need[c])
                formed++;

            // shrink window when valid
            while (formed == required) {
                if (j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    start = i;
                }

                have[s[i]]--;
                if (need.count(s[i]) && have[s[i]] < need[s[i]])
                    formed--;

                i++;
            }
            j++;
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};