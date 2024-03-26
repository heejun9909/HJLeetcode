class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // if the car in the front has higher speed than the one behind, it will never be able to catch up.
        vector<pair<int, int>> tracker;
        stack<pair<int, int>> helper;

        for(int i=0; i<position.size(); ++i)
        {
            tracker.push_back(make_pair(position[i], speed[i]));
        }

        // sort the tracker vector to identify which car is at the very front at which speed
        sort(tracker.begin(), tracker.end());

        // get the time for each car to arrive at the target
        // (target - position) / speed

        // iterating from the furthest car, we push to the stack
        // when pushing new car, we calculate the time and if the time is less, it will catch up and there is no need to push it into the stack
        // since they are combined as one fleet with lower speed (speed of the car that was ahead).

        for(int i=tracker.size()-1; i>=0; --i)
        {
            if(helper.empty())
            {
                helper.push(tracker[i]);
            }
            else
            {
                double timetop = (((double)target - (double)helper.top().first) / (double)helper.top().second);
                double timenew = (((double)target - (double)tracker[i].first) / (double)tracker[i].second);

                if(timetop >= timenew)
                {
                    continue;
                }
                else
                {
                    helper.push(tracker[i]);
                }
            }
        }

        return helper.size();
    }
};