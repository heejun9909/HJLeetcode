class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // Create a helper stack to store the pairs that hold (index:value) of the elements from the heights input
        stack<pair<int,int>> helper; // index:value
        int ans = 0;

        for(int i=0; i<heights.size(); ++i)
        {
            if(helper.empty())
            {
                helper.push(make_pair(i, heights[i]));
            }

            // iterating from the first element, if the upcoming element is smaller than the helper.top(),
            // it means the width of the helper.top() is restricted to that new element's index 
            // which means the maximum area of helper.top() can be calculated
            else if(heights[i] < helper.top().second)
            {
                int start;
                while(!helper.empty() && heights[i] < helper.top().second)     // if !helper.empty() is after the (heights[i] < helper.top().second) condition, runtime error occurs.
                                                                               // because the AND operator will check the first condition and then check for the second one.
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

        // check for the elements that might be left over in the stack.
        // the width is (heights.size() - index of that element)
        while(!helper.empty())
        {
            int area = ((heights.size() - helper.top().first) * helper.top().second);
            ans = max(ans,area);
            helper.pop();
        }

        return ans;
    }
};
