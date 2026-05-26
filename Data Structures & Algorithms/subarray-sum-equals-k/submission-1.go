func subarraySum(nums []int, k int) int {
    presum := make([]int,len(nums))
    cnt :=0
    for i:=0;i<len(nums);i++{
        cnt+=nums[i]
        presum[i]=cnt
    }
    mp := make(map[int]int)
    ans:=0
    for i:=0;i<len(nums);i++{
        val,ok := mp[presum[i]-k]
        if presum[i]==k{
            ans++
        }
        if ok{
            ans+= val
        }
        mp[presum[i]]++
    }
    return ans
}
