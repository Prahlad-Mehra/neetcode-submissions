class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)
        onePresent = False
        for i in range(0,n):
            if nums[i]==1:
                onePresent = True
            if nums[i]<=0:
                nums[i] = 1
        
        if onePresent==False:
            return 1
        
        #print(nums)
        for i in range(0,n):
            curr = abs(nums[i])
            if curr<=n:
                nums[curr-1] = abs(nums[curr-1])*(-1)
        
        #print(nums)
        for i in range(1,n+1):
            if nums[i-1]>0:
                return i
        
        return n+1
        