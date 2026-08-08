#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* validSequence(char* word1, char* word2, int* returnSize) {
    int n = strlen(word1);
    int m = strlen(word2);
    
    // suf[i] will store the starting index in word2 such that word2[suf[i]:] 
    // can be formed as a subsequence of word1[i:]
    int* suf = (int*)malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++) {
        suf[i] = m; // m means empty suffix
    }
    
    // Fill suffix matching table from right to left
    int j = m - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (j >= 0 && word1[i] == word2[j]) {
            j--;
        }
        suf[i] = j + 1; // First unmatched index in word2 from suffix i
    }
    
    int* res = (int*)malloc(m * sizeof(int));
    int res_size = 0;
    
    j = 0; // Current index in word2 we want to match
    int changed = 0; // Flag to track if we used our single character change
    
    for (int i = 0; i < n && j < m; i++) {
        if (word1[i] == word2[j]) {
            res[res_size++] = i;
            j++;
        } else if (!changed && suf[i + 1] <= j + 1) {
            // We can change word1[i] to word2[j] if the remaining suffix can still be matched
            res[res_size++] = i;
            changed = 1;
            j++;
        }
    }
    
    if (res_size < m) {
        free(suf);
        free(res);
        *returnSize = 0;
        return NULL;
    }
    
    free(suf);
    *returnSize = m;
    return res;
}
