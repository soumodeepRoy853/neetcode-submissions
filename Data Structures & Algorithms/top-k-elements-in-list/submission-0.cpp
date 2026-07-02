class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Solution:
        // Use hashmap + heap

        unordered_map<int, int> freq;
        for(auto num : nums){
            freq[num]++;
        }

        // Initialize min heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(auto &elem : freq){
            pq.push({elem.second, elem.first});

            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
