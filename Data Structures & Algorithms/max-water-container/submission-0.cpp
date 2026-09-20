class Solution {
public:
    int maxArea(vector<int>& heights)
    {
        size_t leftPtr = 0, rightPtr = heights.size() - 1;
        int maxArea = 0, width = heights.size() -1, area = 0;

        while( leftPtr < rightPtr)
        {
            if(heights[leftPtr] <= heights[rightPtr])
            area = width * heights[leftPtr];
            else area = width * heights[rightPtr];

            if(maxArea < area)
            maxArea = area;

            if(heights[leftPtr] < heights[rightPtr])
                leftPtr++;
            else rightPtr--;
            width--;
        }
        return maxArea;
    }
};
