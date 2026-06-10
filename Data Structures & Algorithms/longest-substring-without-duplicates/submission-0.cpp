class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int>mp;
        int l = 0, r = 0;
        int maxLen = 0;

        while(r < n){
            if(mp.find(s[r]) != mp.end() && mp[s[r]] >= l){
                l = mp[s[r]]+1;
            }
            int len = r - l + 1;
            maxLen = max(len, maxLen);
            mp[s[r]] = r;
            r++;
        }
        return maxLen;
    }
};
