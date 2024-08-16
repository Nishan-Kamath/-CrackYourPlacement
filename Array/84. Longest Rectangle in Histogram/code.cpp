class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0, currHeight, width, area, top;
        stack<int> s;
        for(int i=0;i<heights.size();i++){
            if(i==0)
                currHeight = i;
            else
                currHeight = heights[i];
            while(!s.empty() && currHeight < heights[s.top()]){
                top = s.top();
                s.pop();
                if(s.empty())
                    width = i;
                else 
                    width = i-s.top()-1;
                area = heights[top] * width;
                maxArea = max(area, maxArea);
            }
            s.push(i);
        }
        while(!s.empty()) {
            top = s.top();
            s.pop();
            if(s.empty())
                width = heights.size();
            else 
                width = heights.size() - s.top() - 1;
            area = heights[top] * width;
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
};