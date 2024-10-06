class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> words1 = splitSentence(sentence1);
        vector<string> words2 = splitSentence(sentence2);

        if (words1.size() > words2.size()) swap(words1, words2);
        
        int m = words1.size();
        int n = words2.size();

        int prefixMatch = 0;
        while (prefixMatch < m && words1[prefixMatch] == words2[prefixMatch]) {
            prefixMatch++;
        }

        int suffixMatch = 0;
        while (suffixMatch < m - prefixMatch && words1[m - 1 - suffixMatch] == words2[n - 1 - suffixMatch]) {
            suffixMatch++;
        }

        return prefixMatch + suffixMatch == m;
    }

private:
    vector<string> splitSentence(const string &sentence) {
        vector<string> result;
        stringstream ss(sentence);
        string word;
        while (ss >> word) {
            result.push_back(word);
        }
        return result;
    }
};
