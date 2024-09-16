class Solution {
    // int solve(int i, int j, string& word1, string& word2,
    //           vector<vector<int>>& dp) {
    //     if (i < 0)
    //         return j + 1;
    //     if (j < 0)
    //         return i + 1;
    //     if (dp[i][j] != -1)
    //         return dp[i][j];
    //     if (word1[i] == word2[j])
    //         return dp[i][j] = solve(i - 1, j - 1, word1, word2, dp);
    //     return dp[i][j] = 1 + min({solve(i - 1, j - 1, word1, word2, dp),
    //                                solve(i, j - 1, word1, word2, dp),
    //                                solve(i - 1, j, word1, word2, dp)});
    // }

    //1-based Indexing

    int solve(int i, int j, string& word1, string& word2,
              vector<vector<int>>& dp) {
        if (i == 0)
            return j;
        if (j == 0)
            return i;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (word1[i-1] == word2[j-1])
            return dp[i][j] = solve(i - 1, j - 1, word1, word2, dp);
        return dp[i][j] = 1 + min({solve(i - 1, j - 1, word1, word2, dp),
                                   solve(i, j - 1, word1, word2, dp),
                                   solve(i - 1, j, word1, word2, dp)});
    }

    

public:
    int minDistance(string word1, string word2) {
        // int n = word1.size();
        // int m = word2.size();
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return solve(n - 1, m - 1, word1, word2, dp);

        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(n, m, word1, word2, dp);
    }
};