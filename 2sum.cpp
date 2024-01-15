#include <bits/stdc++.h>
using namespace std;

class solution{
public:
    vector<int>twosum(vector<int>&nums,int target){
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(target-nums[i])==mp.end()) mp[nums[i]]=i;
            else return {mp[target-nums[i]],i};
        }
        return {-1,-1};
    }
};

int main(){
    string s;
    getline(cin,s);
    int num=0;
    vector<int>nums;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='[') continue;
        else if( s[i]==','||s[i]==']')
        {
            nums.push_back(num);
            num=0;
        }
        else
        {
            num=num*10 +(s[i]-'0');
        }
    }
    int target;
    cin>>target;
    solution obj;
    vector<int>ans = obj.twosum(nums,target);
    cout<<'[';
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<']';
    cout<<"\n";

    return 0;
}