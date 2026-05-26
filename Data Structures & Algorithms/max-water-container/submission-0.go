func maxArea(heights []int) int {
    l,r := 0,len(heights)-1
    ans := -1
    for l < r{
        amount := min(heights[l],heights[r]) * (r-l)
        ans = max(ans,amount)
        if heights[l] < heights[r]{
            l++
        } else{
            r--
        }
    }
    return ans
}
