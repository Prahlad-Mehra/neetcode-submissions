func longestConsecutive(nums []int) int {
    mp := make(map[int]bool)
    for _,val:= range nums{
        mp[val]= true
    }
    ans := 0
    for key,_ := range mp{
        ok := mp[key-1]
        if ok==false{
            count,curr := 0,key
            for mp[curr]==true{
                count++
                curr++
            }
            ans=max(ans,count)
        }
    }
    return ans
}