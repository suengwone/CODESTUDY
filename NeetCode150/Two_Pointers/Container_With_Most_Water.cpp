class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int left = 0, right = height.size() - 1;
        int area = 0, temp;

        while(left < right)
        {
            temp = min(height[left], height[right]) * (right - left);

            if(area < temp)
            {
                area = temp;
            }

            if(height[left] > height[right])
            {
                right--;
            }
            else if(height[left] < height[right])
            {
                left++;
            }
            else
            {
                int n_right = right;
                int n_left = left;
                
                while(n_left < n_right)
                {
                    n_left++;
                    n_right--;

                    if(height[n_right] > height[n_left])
                    {
                        right = n_right;
                        break;
                    }
                    else if(height[n_right] < height[n_left])
                    {
                        left = n_left;
                        break;
                    }
                    else
                    {
                        if(height[right] > height[n_right])
                        {
                            right = n_right;
                            left = n_left;
                        }
                        else
                        {
                            right = n_right;
                            left = n_left;
                            break;
                        }
                    }
                }
            }
        }

        return area;
    }
};
