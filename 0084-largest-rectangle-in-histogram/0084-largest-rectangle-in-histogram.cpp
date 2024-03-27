class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> helper; // index:value
        int ans = 0;

        for(int i=0; i<heights.size(); ++i)
        {
            if(helper.empty())
            {
                helper.push(make_pair(i, heights[i]));
            }
            else if(heights[i] < helper.top().second)
            {
                int start;
                while(!helper.empty() && heights[i] < helper.top().second)
                {
                    int area = ((i - helper.top().first) * helper.top().second);

                    ans = max(ans,area);
                    start = helper.top().first;
                    helper.pop();
                }
                helper.push(make_pair(start, heights[i]));
            }
            else
            {
                helper.push(make_pair(i, heights[i]));
            }
        }

        while(!helper.empty())
        {
            int area = ((heights.size() - helper.top().first) * helper.top().second);
            ans = max(ans,area);
            helper.pop();
        }

        return ans;
    }
};