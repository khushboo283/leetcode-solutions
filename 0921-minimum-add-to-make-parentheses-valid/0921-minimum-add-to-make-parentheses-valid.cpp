class Solution {
public:
    int minAddToMakeValid(string s) {
        int balance = 0;
        int insertions = 0;

        for (char ch : s) {
            if (ch == '(') {
                balance++;
            } else {
                if (balance > 0) {
                    balance--;
                } else {
                    insertions++;
                }
            }
        }
        return insertions + balance;
    }
};
