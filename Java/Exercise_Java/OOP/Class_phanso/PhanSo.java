package Exercise_Java.OOP.Class_phanso;

public class PhanSo {
    private int tu;
    private int mau;
    public int gcd(int a, int b){
        if(b == 0) return a;
        return gcd(b, a % b);
    }
    public PhanSo(int tu, int mau) {
        this.tu = tu;
        this.mau = mau;
    }
    public void process(){
        int g = gcd(tu, mau);
        tu /= g;
        mau /= g;
    }

    @Override
    public String toString() {
        return tu + "/" + mau;
    }
}
