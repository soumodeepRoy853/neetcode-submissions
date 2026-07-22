class Solution {
private:
    bool f(int i, int j, string& s, vector<vector<int>>& dp){
        if(i >= j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == s[j]){
            return dp[i][j] = f(i+1, j-1, s, dp);
        }

        return 0;
    }
public:
    string longestPalindrome(string s) {
        int n = s.size();

        vector<vector<int>>dp (n, vector<int>(n, -1));

        int maxLen = INT_MIN;
        int startPoint = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(f(i, j, s, dp) == true){
                    if(j-i+1 > maxLen){
                        maxLen = j-i+1;
                        startPoint = i;
                    }
                }
            }
        }
        return s.substr(startPoint, maxLen);
    }
};
