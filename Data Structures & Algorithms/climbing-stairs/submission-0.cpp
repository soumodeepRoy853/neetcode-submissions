class Solution {
private:
    int f(int n){
        if(n == 0) return 1;
        if(n < 0) return 0;
        return f(n-1)+f(n-2);
    }
public:
    int climbStairs(int n) {
        return f(n);
    }
};
