type MyHashMap struct {
    arr []int
}

func Constructor() MyHashMap {
    tmp := make([]int,1000001)
    for idx := range tmp{
        tmp[idx]=-1
    }
    return MyHashMap{
        arr : tmp,
    }
}

func (this *MyHashMap) Put(key int, value int) {
    this.arr[key]=value
}

func (this *MyHashMap) Get(key int) int {
    return this.arr[key]
}

func (this *MyHashMap) Remove(key int) {
    this.arr[key]=-1
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Put(key,value);
 * param_2 := obj.Get(key);
 * obj.Remove(key);
 */