class Solution {
public:
    //this is the function for twoSum
    vector<int> twoSum(vector<int>& a, int t) {
         vector<int> ans;
  
          int n=a.size();
          unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
                 mp[t-a[i]]=i;
        
        for(int i=0;i<n;i++)
              if(mp.find(a[i])!=mp.end()&&(i!=mp[a[i]]))
              {
                  ans.push_back(i);
                  ans.push_back(mp[a[i]]);
                  break;
              }
                  
        sort(ans.begin(),ans.end());
        return ans;
    }
};
