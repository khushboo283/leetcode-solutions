class Solution {
public:
    int minInsertions(string s) {
        int insertions = 0;
        int open_count = 0;

        int i = 0;
        while (i < s.length()) {
            if (s[i] == '(') {
                open_count++;
            } else {
                if (i + 1 < s.length() && s[i + 1] == ')') {
                    i++;
                } 
                else {
                    insertions++;
                }

                if (open_count > 0) {
                    open_count--;
                } else {
                    insertions++;
                }
            }
            i++;
        }
        insertions += open_count * 2;

        return insertions;
    }
};