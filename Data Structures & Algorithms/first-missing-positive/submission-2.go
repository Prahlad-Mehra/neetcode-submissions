func abs(num int) int{
    if num < 0{
        return -num
    }
    return num
}
func firstMissingPositive(nums []int) int {
	for idx,val:= range nums{
        if (val <= 0) || (val > len(nums)){
            nums[idx] = math.MaxInt
        } 
    }
    for _,val := range nums{
        val = abs(val)
        if val > 0 && val <= len(nums){
            nums[val-1] = -1*abs(nums[val-1])
        }
    }
    for idx,val := range nums{
        if val > 0{
            return idx+1
        }
    }
    return len(nums)+1
}
