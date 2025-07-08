package Code_PTIT.Practice.Matrix;


public class Matrix {
    private int  row, col, a[][];

    public Matrix(int row, int col, int[][] a) {
        this.row = row;
        this.col = col;
        this.a = a;
    }

    public void Sort(int x) {
        for(int i = 0; i < row - 1; ++i) {
            for(int j = i + 1; j < row; ++j) {
                if(a[i][x] > a[j][x]) {
                    int tmp = a[i][x];
                    a[i][x] = a[j][x];
                    a[j][x] = tmp;
                }
            }

        }
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder("");
        for(int i = 0; i < row; ++i) {
            String res = "";
            for (int j = 0; j < col; ++j) {
                res += String.valueOf(a[i][j]);
                if(j < col - 1) res += " ";
            }
            sb.append(res + "\n");
        }
        return sb.toString();
    }
}
