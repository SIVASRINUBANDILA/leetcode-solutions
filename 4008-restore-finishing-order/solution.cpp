class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int> result;  
        
        for(int person : order){          
            for(int fri : friends){
                if(person == fri){
                    result.push_back(person);
                    break;
                }
            }
        }
        
        return result;
    }
};
