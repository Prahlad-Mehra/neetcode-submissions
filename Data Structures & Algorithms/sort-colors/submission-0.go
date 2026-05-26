func sortColors(nums []int)  {
    st,end,curr := 0,len(nums)-1,0
    for curr <= end{
        if nums[curr]==0{
            nums[st],nums[curr]=nums[curr],nums[st]
            st++
            curr++
            continue
        }
        if nums[curr]==1{
            curr++
            continue
        }
        if nums[curr]==2{
            //nums[curr]==2
            nums[end],nums[curr]=nums[curr],nums[end]
            end--
        }
    }
}