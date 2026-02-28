class Solution {
public:
    string mergeCharacters(string s, int k) {
        
        string velunorati = s; //
        
        bool changed = true;
        
        while (changed) {
            changed = false;
            
            for (int i = 0; i < velunorati.size(); i++) {
                for (int j = i + 1; j < velunorati.size(); j++) {
                    
                    if (velunorati[i] == velunorati[j] && j - i <= k) {
                        
                        velunorati.erase(j, 1);  
                        changed = true;
                        break;  
                    }
                }
                if (changed) break;
            }
        }
        
        return velunorati;
    }
};
