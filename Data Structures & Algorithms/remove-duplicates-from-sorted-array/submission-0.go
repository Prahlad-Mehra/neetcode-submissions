func removeDuplicates(nums []int) int {
    if len(nums)==1{
        return 1
    }
    pt1,pt2 := 1,1
    for pt2<len(nums){
        if nums[pt2]!=nums[pt2-1]{
            nums[pt1]=nums[pt2]
            pt1++
        }
        pt2++
    }
    return pt1
}