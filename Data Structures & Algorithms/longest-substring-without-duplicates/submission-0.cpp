class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0) return 0;
        unordered_map<char, int> mpp; 
        int i=0, j=0;
        int maxlen = INT_MIN;
        while(j < n){
            while(mpp.find(s[j]) != mpp.end()){// if already present in the map then remove it 
                mpp[s[i]]--;
                if(mpp[s[i]] == 0) mpp.erase(s[i]);
                i++;
            }
            mpp[s[j]]++;
            maxlen = max(maxlen, j-i+1);
            j++;
        }
        return maxlen;
    }
};
