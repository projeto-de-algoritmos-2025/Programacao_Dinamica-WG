class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> count(26, 0);
        for (char c : letters) {
            count[c - 'a']++;
        } 
        return backtrack(words, score, count, 0);
    }
    int backtrack(vector<string>& words, vector<int>& score, vector<int>& count, int index) {
        if (index == words.size()) {
            return 0;
        }
        int maxScore = backtrack(words, score, count, index + 1);
        int currentWordScore = 0;
        vector<int> tempCount = count;
        bool canForm = true;

        for (char c : words[index]) {
            int i = c - 'a';
            if (tempCount[i] > 0) {
                tempCount[i]--;
                currentWordScore += score[i];
            } else {
                canForm = false;
                break;
            }
        }
        if (canForm) {
            maxScore = max(maxScore, currentWordScore + backtrack(words, score, tempCount, index + 1));
        }
        return maxScore;
    }
};