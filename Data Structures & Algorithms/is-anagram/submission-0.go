func isAnagram(s string, t string) bool {
    Smap, Tmap := make(map[rune]int), make(map[rune]int)
    chars := make(map[rune]bool)

    for _,val := range s {
        Smap[val]++
        chars[val]=true
    }
    for _,val := range t {
        Tmap[val]++
        chars[val]=true
    }
    for key,_ := range chars{
        if Smap[key] != Tmap[key]{
            return false
        }
    }
    return true
}
