func trap(height []int) int {
    if len(height) == 0{
        return 0
    }
    l,r := 0,len(height)-1
    leftMax,rightMax := height[l],height[r]
    total := 0
    for l<r{
        if leftMax<rightMax{
            l++
            leftMax = max(leftMax,height[l])
            total+= leftMax - height[l]
        } else{
            r--
            rightMax = max(rightMax,height[r])
            total+= rightMax - height[r]
        }
    }
    return total
}