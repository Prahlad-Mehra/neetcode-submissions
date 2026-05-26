func majorityElement(nums []int) int {
    curr,count:=nums[0],0
    for _,num := range nums{
        if count==0{
            curr=num
        }
        if num == curr{
            count++
        }else{
            count--
        }
    }
    return curr
}
