class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int> hash(256, -1);

        int l = 0;
        int maxLen = 0;

        for (int r = 0; r < n; r++) {

            if (hash[s[r]] >= l) {
                l = hash[s[r]] + 1;
            }

            hash[s[r]] = r;

            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};