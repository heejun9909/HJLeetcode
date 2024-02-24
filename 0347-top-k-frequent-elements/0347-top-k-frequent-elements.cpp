class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>                         ans;
        unordered_map<int, vector<int>>     mp1;
        multimap<int, int, greater<int>>    mp2;

        map<int, int, greater<int>>::iterator iter;

        for(auto x:nums)
        {
            mp1[x].push_back(x);
        }

        for(auto y:mp1)
        {
            mp2.insert(make_pair((y.second).size(), y.first));
        }

        iter = mp2.begin();
        for(int i=0;i<k;++i)
        {
            ans.push_back(iter->second);
            ++iter;
        }

        return ans;
    }
};