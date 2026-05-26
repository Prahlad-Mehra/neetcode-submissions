func trap(height []int) int {
	n := len(height)
	leftMax,rightMax := height[0],height[n-1]
	l,r := 0,n-1
	total := 0
	for l<=r{
		if leftMax>rightMax{
			rightMax = max(rightMax,height[r])
			total += rightMax - height[r]
			r--
		} else{
			leftMax = max(leftMax,height[l])
			total += leftMax - height[l]
			l++
		}
	}
	return total
}
