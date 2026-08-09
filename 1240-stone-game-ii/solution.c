int dp[101][101];

int solve(int* piles, int n, int i, int M, int* suffix) {
    if (i >= n)
        return 0;

    if (dp[i][M] != -1)
        return dp[i][M];

    int ans = 0;

    for (int X = 1; X <= 2 * M && i + X <= n; X++) {
        int newM = M > X ? M : X;

        int opponent = solve(piles, n, i + X, newM, suffix);

        int currentPlayer = suffix[i] - opponent;

        if (currentPlayer > ans)
            ans = currentPlayer;
    }

    return dp[i][M] = ans;
}

int stoneGameII(int* piles, int pilesSize) {
    int suffix[101];

    memset(dp, -1, sizeof(dp));

    suffix[pilesSize] = 0;

    for (int i = pilesSize - 1; i >= 0; i--) {
        suffix[i] = suffix[i + 1] + piles[i];
    }

    return solve(piles, pilesSize, 0, 1, suffix);
}
