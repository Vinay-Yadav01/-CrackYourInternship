class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0;
        int n = s.size();
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                left++;
            else
                right++;
            if (left == right)
                maxi = max(maxi, 2 * left);
            else if (right > left)
                left = right = 0;
        }
        left = 0;
        right = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '(')
                left++;
            else
                right++;
            if (left == right)
                maxi = max(maxi, 2 * left);
            else if (left > right)
                left = right = 0;
        }
        return maxi;
    }
};