class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        mp: Dict[int,int] = {}
        mp[0] = 1

        result = 0
        summ = 0
        for idx in range(0,len(nums)):
            summ += nums[idx]
            if mp.get(summ-k,0)>0:
                result += mp.get(summ-k,0)
            
            mp[summ] = mp.get(summ,0) + 1

        return result
    