bool winnerSquareGame(int n) {
    bool* dp = (bool*)calloc(n + 1, sizeof(bool));
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j * j <= i; ++j) {
            if (!dp[i - j * j]) {
                dp[i] = true;
                break;
            }
        }
    }
    
    bool result = dp[n];
    free(dp);
    return result;
}
