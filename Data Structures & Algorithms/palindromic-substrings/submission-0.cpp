class Solution {
private:
    bool f(int i, int j, string& s){
        //base case
        if(i >= j) return 1;

        if(s[i] == s[j]){
            return f(i+1, j-1, s);
        }

        return 0;
    }
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(f(i, j, s) == true){
                    count++;
                }
            }
        }
        return count;
    }
};
