func isPalindrome(s string) bool {
    var low strings.Builder
    for _,ch := range s{
        if ch>='A' && ch<='Z'{
            low.WriteRune(unicode.ToLower(ch))
        }
        if ch>='a' && ch<='z'{
            low.WriteRune(ch)
        }
        if ch>='0' && ch<='9'{
            low.WriteRune(ch)
        }
    }
    ans := low.String()
    st,end :=0,len(ans)-1
    for st<end{
        if ans[st] != ans[end]{
            return false
        }
        st++
        end--
    }
    return true
}
