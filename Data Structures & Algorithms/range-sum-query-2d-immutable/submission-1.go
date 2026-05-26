type NumMatrix struct {
    presum [][]int
}


func Constructor(matrix [][]int) NumMatrix {
    if len(matrix) == 0 || len(matrix[0]) == 0 {
        return NumMatrix{}
    }

    m, n := len(matrix), len(matrix[0])
    presum := make([][]int, m)
    for i := range presum {
        presum[i] = make([]int, n)
    }

    for i:=0;i<len(matrix);i++{
        for j:=0;j<len(matrix[i]);j++{
            up,left,diagonal := 0,0,0
            if i-1>=0{
                up=presum[i-1][j]
            }
            if j-1>=0{
                left=presum[i][j-1]
            }
            if i-1>=0 && j-1>=0{
                diagonal= presum[i-1][j-1]
            }
            presum[i][j]=matrix[i][j]+up+left-diagonal
        }
    }
    return NumMatrix{
        presum : presum,
    }
}


func (this *NumMatrix) SumRegion(row1 int, col1 int, row2 int, col2 int) int {
    up,left,diagonal := 0,0,0
    if row1-1>=0{
        up=this.presum[row1-1][col2]
    }
    if col1-1>=0{
        left=this.presum[row2][col1-1]
    }
    if row1-1>=0 && col1-1>=0{
        diagonal = this.presum[row1-1][col1-1]
    }

    ans := this.presum[row2][col2] + diagonal - (up + left)
    return ans
}