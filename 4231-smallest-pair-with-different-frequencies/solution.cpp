class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        
        unordered_map<int,int> freq;
        
    
        for(int num : nums)
            freq[num]++;
        
  
        vector<int> values;
        for(auto &p : freq)
            values.push_back(p.first);
        
        sort(values.begin(), values.end());
        
        // Try all pairs
        for(int i = 0; i < values.size(); i++){
            for(int j = i + 1; j < values.size(); j++){
                if(freq[values[i]] != freq[values[j]]){
                    return {values[i], values[j]};
                    
                }
            }
        }
        
        return {-1, -1};
    }
};
