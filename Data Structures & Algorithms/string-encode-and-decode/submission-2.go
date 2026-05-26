type Solution struct{}

func (s *Solution) Encode(strs []string) string {
    var ans strings.Builder
    for _,str := range strs{
        ans.WriteString("(")
        ans.WriteString(str)
        ans.WriteString(")")
    }
    return ans.String()
}

func (s *Solution) Decode(encoded string) []string {
    ans := make([]string,0)
    if len(encoded)==0{
        return ans
    }
    i:= 0
    for i<len(encoded){
        var deco strings.Builder
        if encoded[i]=='('{
            i++
        }
        for{
            if i+1>=len(encoded){
                i++
                break
            }
            if encoded[i]==')' && encoded[i+1]=='('{
                i++
                break
            } else{
                deco.WriteByte(encoded[i])
                i++
            }
        }
        ans = append(ans,deco.String())
    }
    return ans
}
