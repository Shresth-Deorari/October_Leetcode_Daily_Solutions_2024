class Solution {
    void getUniqueStrings(string& s, unordered_set<string>& uniqueStringSet, int i, int& ans){
        if(i == s.size()){
            int n = uniqueStringSet.size();
            ans = max(ans,n);
            return;
        }
        string temp = "";
        for(int j = i;j<s.size();j++){
            temp += s[j];
            if(uniqueStringSet.count(temp)==0){
                uniqueStringSet.insert(temp);
                getUniqueStrings(s,uniqueStringSet, j+1, ans);
                uniqueStringSet.erase(temp);
            }
        }
    }
public:
    int maxUniqueSplit(string s) {
        unordered_set<string>uniqueStringSet;
        int ans = 0;
        getUniqueStrings(s,uniqueStringSet,0,ans);
        return ans;
    }
};