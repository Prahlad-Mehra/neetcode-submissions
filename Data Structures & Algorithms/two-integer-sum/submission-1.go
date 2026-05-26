func twoSum(nums []int, target int) []int {
    ans,mp:= make([]int,0),make(map[int]int)
    for idx,val:= range nums{
        find:= target - val
        idx2,ok := mp[find]
        if ok {
            ans = append(ans,idx2,idx)
            break
        }
        mp[val]=idx
    }
    return ans
}
