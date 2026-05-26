func mergeAlternately(word1 string, word2 string) string {
    var ans strings.Builder
    i,j:= 0,0
    for (i<len(word1)) && (j<len(word2)){
        ans.WriteByte(word1[i])
        ans.WriteByte(word2[j])
        i++
        j++
    }
    for i<len(word1){
        ans.WriteByte(word1[i])
        i++
    }
    for j<len(word2){
        ans.WriteByte(word2[j])
        j++
    }
    return ans.String()
}