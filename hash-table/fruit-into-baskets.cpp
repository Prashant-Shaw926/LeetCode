class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        if(n==1){
            return 1;
        }
        int i = 0, j = 0, count = 0;
        int tempA = fruits[i], tempB = fruits[i];
        int result = INT_MIN;

        for (i = 0; i < n; i++) {
            count++;
            tempA = fruits[i];
            tempB = fruits[i];
            for (j = i + 1; j < n; j++) {
                if (tempA != fruits[j] && tempB != fruits[j]) {
                    count++;
                    tempB = fruits[j];
                }
                if (count > 2) {
                    count = 0;
                    break;
                } else {
                    int length = j - i + 1;
                    result = max(result, length);
                }
            }
            count = 0;
        }

        return result;
    }
};