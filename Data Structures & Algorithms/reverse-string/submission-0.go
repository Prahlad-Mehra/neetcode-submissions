func reverseString(s []byte) {
    start,end:=0,len(s)-1
    for start<end{
        s[start]=s[start]+s[end]
        s[end]=s[start]-s[end]
        s[start]=s[start]-s[end]
        start++
        end--
    }
}
