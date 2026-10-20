class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int l = 0, mid = 0, r = 0;
        for(size_t i = 0; i < matrix.size(); i++)
        {
            r = matrix[i].size() - 1;
            while(l <= r)
            {
                mid = (l+r)/2;
                if(matrix[i][mid] == target) return true;
                else if(matrix[i][mid] < target) l = mid + 1;
                else r = mid - 1;
            }
            l = 0;
        }
        return false;    
    }
};
