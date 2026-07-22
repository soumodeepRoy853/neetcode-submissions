class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mpp;
        vector<vector<string>>ans;
        //sort all the elems
        for(auto x : strs){
            //store every letter of strs in trmp variable
            string temp = x;
            //now sorting
            sort(x.begin(), x.end());
            //x -> key
            //temp -> value
            mpp[x].push_back(temp);
        }
        //Store all the values into ans variable from map
        for(auto x : mpp){
            vector<string> val = x.second;
            ans.push_back(val);
        }
        return ans;
    }
};
