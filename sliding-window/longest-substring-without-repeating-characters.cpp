class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        }

        set<char> uniq;
        int i = 0, j = 0, temp = 0, result = INT_MIN;

        for (i = 0; i < n; i++) {
            uniq.insert(s[i]);
            int size = uniq.size();

            if (size == temp) {
                while (i != j) {
                    if (s[i] == s[j]) {
                        uniq.erase(s[j]);
                        j++;
                        break;
                    }
                    uniq.erase(s[j]);
                    j++;
                }
                uniq.insert(s[i]);
            }

            int len = i - j + 1;
            temp = len;
            result = max(len, result);
        }

        return result;
    }
};