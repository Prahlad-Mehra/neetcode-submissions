class Solution:
    def trap(self, height: List[int]) -> int:
        lft, right = 0, len(height)-1

        water = 0
        while lft<right:
            if height[lft] < height[right]:
                #something
                idx = lft
                while idx<= right and height[idx]<=height[lft]:
                    water += height[lft] - height[idx]
                    idx += 1
                
                lft = idx
            else:
                #base case
                idx = right
                while idx>=lft and height[idx]<=height[right]:
                    water += height[right] - height[idx]
                    idx -= 1
                
                right = idx
        
        return water
