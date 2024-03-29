class Solution {
public:
    int trap(vector<int>& height) {
        // We have 2 solutions for this problem
        // Both solutions will have time complexity of O(n)
        // The first solution will have space complexity of O(n)
        // The second solution will have space complexity of O(1)

        // The first solution is about keeping the maxLeft, maxRight arrays for each ith position

        // vector<int> maxLeft(height.size());
        // vector<int> maxRight(height.size());

        // int water = 0;

        // int max = 0;
        // for(int i = 1; i < height.size(); ++i)
        // {
        //     if(height[i - 1] > max)
        //     {
        //         max = height[i - 1];
        //     }

        //     maxLeft[i] = max;
        // }

        // max = 0;
        // for(int i = height.size()-2; i >= 0; --i)
        // {
        //     if(height[i + 1] > max)
        //     {
        //         max = height[i + 1];
        //     }

        //     maxRight[i] = max;
        // }
        
        // for(int i = 0; i < height.size(); ++i)
        // {
        //     if(min(maxLeft[i], maxRight[i]) <= height[i])
        //     {
        //         continue;
        //     }
        //     else
        //     {
        //         water += min(maxLeft[i], maxRight[i]) - height[i];
        //     }
        // }
        // return water;



        // The second solution is about using two pointers technique
        // The trick in this problem is that we actually need to know the
        // min(maxLeft, maxRight) which will be the bottleneck of current position
        // 양 끝에서 더 작은 bottleneck을 가지고 있는 바운더리 바로 앞(전)에서 그 위치에서
        // 담을 수 있는 물을 계산 하겠다는 것. 가장 작은 바운더리에서 담을 수 있는 물은
        // 어차피 정해져 있기 때문에 그 바운더리 이외의 것은 신경쓰지 않아도 된다.

        int l = 0;
        int r = height.size() - 1;
        int maxLeft = height[l];
        int maxRight = height[r];

        int water = 0;

        while(l < r)
        {
            if(maxLeft <= maxRight)
            {
                ++l;
                maxLeft = max(maxLeft, height[l]);
                water += maxLeft - height[l];
            }
            else
            {
                --r;
                maxRight = max(maxRight, height[r]);
                water += maxRight - height[r];
            }
        }

        return water;

    }
};