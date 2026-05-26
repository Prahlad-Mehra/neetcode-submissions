func abs(num int) int{
    if num < 0{
        return -num
    }
    return num
}
func firstMissingPositive(nums []int) int {
	for idx,val:= range nums{
        if (val <= 0) || (val > len(nums)){
            // nums[idx] = -1 * abs(math.MaxInt)
            nums[idx] = math.MaxInt
        } 
        // else {
        //     nums[idx-1] = abs(nums[idx-1])
        // }
    }
    fmt.Println(nums)
    for _,val := range nums{
        val = abs(val)
        if val > 0 && val <= len(nums){
            // val = abs(val)
            nums[val-1] = -1*abs(nums[val-1])
            // fmt.Println(val,"changed value",nums[val-1],"nums=",nums)
        }
    }
    for idx,val := range nums{
        if val > 0{
            return idx+1
        }
    }
    return len(nums)+1
}
