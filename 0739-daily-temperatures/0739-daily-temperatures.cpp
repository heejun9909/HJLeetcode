class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // Monotonic Decreasing Stack Problem
        // we will use the mono stack to store the INDEX of the temp values
        // and use them in subtraction to get the distance between the
        // first-encountered greater value in the given array of temp
        stack<int> mono;

        // initialize a vector with a size of temperatures and a value of 0        
        vector<int> res(temperatures.size(), 0);

        for(int i=0; i<temperatures.size(); ++i)
        {
            // when the stack is empty at first, we can do nothing but push the index to the helper stack, mono
            if(mono.empty())
            {
                mono.push(i);
            }

            // if the upcoming value is greater, it means we don't need to store the mono.top() index anymore
            // because it has got its answer now
            else if(!mono.empty() && temperatures[i] > temperatures[mono.top()])
            {
                // do the subtraction to calculate the distance
                res[mono.top()] = i - mono.top();

                // then pop the mono.top() index which became useless
                mono.pop();

                // we will see if there are more awaiting values in the mono stack that is smaller than
                // the upcoming value. If so, we will do the same calculation and pop them
                while(!mono.empty() && temperatures[i] > temperatures[mono.top()])
                {
                    res[mono.top()] = i - mono.top();
                    mono.pop();
                }

                // out of the while loop means there are no more values that are smaller than the upcoming value
                // so push the upcoming value to the stack
                mono.push(i);
            }

            // when the mono.top() value is greater than the upcoming value, we can do nothing but just
            // push the upcoming value for the next one
            else
            {
                mono.push(i);
            }
        }

        return res;
    }
};