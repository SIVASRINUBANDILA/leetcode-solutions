class Solution {
public:
    vector<string> result;

    vector<string> keypad = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void backtrack(string &digits, int index, string current) {
        // 1️⃣ Base case
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }

        // 2️⃣ Get letters for current digit
        int digit = digits[index] - '0';
        string letters = keypad[digit];

        // 3️⃣ Try each letter
        for (char ch : letters) {
            backtrack(digits, index + 1, current + ch);
        }
    }

    vector<string> letterCombinations(string digits) {
        // Edge case
        if (digits.empty()) return {};

        backtrack(digits, 0, "");
        return result;
    }
};

