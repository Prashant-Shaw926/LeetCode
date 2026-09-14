class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        if (n == 1) {
            return 1;
        }
        int i = 0, j = 0;
        int temp;
        int result = INT_MIN;
        unordered_map<int, int> freq;

        while (j < n) {
            freq[fruits[j]]++;
            if (freq.size() > 2) {
                temp = fruits[i];
                while (freq[temp] != 0 && fruits[i] == temp) {
                    freq[temp]--;
                    i++;
                }
                if(freq[temp] == 0){
                    freq.erase(temp);
                }
            }
            int length = j - i + 1;
            result = max(result, length);
            j++;
        }

        return result;
    }
};

// for (i = 0; i < n; i++) {
//     count++;
//     tempA = fruits[i];
//     tempB = fruits[i];
//     for (j = i + 1; j < n; j++) {
//         if (tempA != fruits[j] && tempB != fruits[j]) {
//             count++;
//             tempB = fruits[j];
//         }
//         if (count > 2) {
//             count = 0;
//             break;
//         } else {
//             int length = j - i + 1;
//             result = max(result, length);
//         }
//     }
//     count = 0;
// }