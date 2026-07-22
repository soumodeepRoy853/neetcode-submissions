class Solution {
private:
    int f(int ind1, int ind2, string &text1, string &text2){
        if(ind1 < 0 || ind2 < 0) return 0;

        if(text1[ind1] == text2[ind2]){
            return 1 + f(ind1-1, ind2-1, text1, text2);
        }

        return max(f(ind1-1, ind2, text1, text2), f(ind1, ind2-1, text1, text2));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();

        return f(n-1, m-1, text1, text2);
    }
};
