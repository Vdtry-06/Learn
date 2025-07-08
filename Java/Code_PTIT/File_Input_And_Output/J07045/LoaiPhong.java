package Code_PTIT.File_Input_And_Output.J07045;

public class LoaiPhong implements Comparable<LoaiPhong>{
    private String signPoint, name;
    private Integer unit;
    private Float frais;
    public LoaiPhong(String LoaiPhong) {
        String[] parts = LoaiPhong.split("\\s+");
        this.signPoint = parts[0];
        this.name = parts[1];
        this.unit = Integer.parseInt(parts[2]);
        this.frais = Float.parseFloat(parts[3]);
    }
    @Override
    public int compareTo(LoaiPhong o) {
        return this.name.compareTo(o.name);
    }
    @Override
    public String toString() {
        return signPoint + " " + name + " " + unit + " " + frais;
    }
}
