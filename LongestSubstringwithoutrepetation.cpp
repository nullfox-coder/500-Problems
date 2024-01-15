#include<bits/stdc++.h>
using namespace std;

class solution{
public:
    int lengthOfLongestSubstring(string s){
        auto r = 0;
        int l = 0;
        int ans = 0;
        unordered_map<char, int> map;
        while (r < s.size()) {
            char c = s[r];
            if (auto it = map.find(c); it != map.end() && it->second >= l) {
                l = map[c] + 1;
            }
            else {
               ans = max(ans, r - l + 1); 
            }
            map[c] = r++;
        }
        return ans;
    }
    /* 2nd method -
    int lengthOfLongestSubstring(string s) {
        vector<char>chars(128);
        int left=0,right=0, maxi=0;
        while(right<s.size())
        {
            chars[s[right]]++;
            while(chars[s[right]]>1)
            {
                chars[s[left]]--;
                left++;
            }
            maxi=max(maxi,right-left+1);
            right++;
        }
        return maxi;
    }*/
};

int main(){
    string s;
    getline(cin,s);
    solution obj;
    int ans = obj.lengthOfLongestSubstring(s);
    cout<<ans;
    return 0;
}