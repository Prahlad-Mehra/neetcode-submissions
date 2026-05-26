func groupAnagrams(strs []string) [][]string {
    mp := make(map[[26]int]int)
    ans := [][]string{}
    for _,str := range strs{
        var arr [26]int
        for _,ch := range str{
            arr[ch-'a']++
        }
        val,ok := mp[arr]
        if ok{
            ans[val] = append(ans[val],str)
        }else{
            push := []string{str}
            ans = append(ans,push)
            mp[arr]=len(ans)-1
        }
    }
    return ans
}
