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

//--------------------------------------------------------------------------------------------//
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>                         ans;
        unordered_map<int, vector<int>>     mp1;

        // Using priority queue
        // priority queue will store the biggest key as the root node and down to smallest key as default
        priority_queue<pair<int,int>> pq;

        for(auto x:nums)
        {
            mp1[x].push_back(x);
        }

        for(auto y:mp1)
        {
            pq.push(make_pair((y.second).size(), y.first));
        }

        for(int i=0;i<k;++i)
        {
            // pq.top().second will pull out the values of the biggest keys for k times
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
