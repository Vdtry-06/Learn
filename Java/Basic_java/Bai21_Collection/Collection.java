package Basic_java.Bai21_Collection;

import java.net.spi.InetAddressResolver;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Collection {
    public static void main(String[] args) {
        // khai bao danh sach
        ArrayList<Integer> lst = new ArrayList<>();

        // khai bao voi so luong phan tu ban dau
        ArrayList<Integer> lst2 = new ArrayList<>(5);

        // khoi tao list voi cac phan tu ban dau
        ArrayList<Integer> lst3 = new ArrayList<>(List.of(1, 2, 3, 4, 5, 6));

        // xuat list
        System.out.println(lst);
        System.out.println(lst2);
        System.out.println(lst3);

        // add: them phan tu
        ArrayList<Integer> lst4 = new ArrayList<>();
        lst4.add(7);
        lst4.add(8);
        lst4.add(11);
        System.out.println(lst4);
        lst4.add(1, 99);
        System.out.println(lst4);

        // size(): tra ve so phan tu cua list

        // get(int index): tra ve gtri list tai vi tri index
        System.out.println(lst4.get(3));

        // remove(index): xoa tai vi tri index
        lst4.remove(2);
        lst4.remove(Integer.valueOf(99));
        System.out.println(lst4);

        // set(index, element): thay doi thong tin
        ArrayList<Integer> lst6 = new ArrayList<>(List.of(1, 2, 3, 4, 5, 6));
        System.out.println(lst6);
        lst6.set(2, 99);
        System.out.println(lst6);

        // contains(): kiem tra collection co chua phan tu nao do hay khong
        ArrayList<Integer> lst7 = new ArrayList<>(List.of(1, 2, 3, 4, 5, 6));
        boolean ktra = lst7.contains(10);
        System.out.println(ktra);

        // collections.sort(list): sx tang dan
        ArrayList<Integer> lst8 = new ArrayList<>(List.of(19, 2, 38, 4, 5, 6));
        Collections.sort(lst8);
        System.out.println(lst8);

        // indexOf(): tim vi tri dau tien cua element trong list
        // neu 0 ton tai tra ve -1
        ArrayList<Integer> lst9 = new ArrayList<>(List.of(19, 2, 30, 4, 5, 6));
        System.out.println(lst9.indexOf(4));

        // Duyet list
        // c1:
        ArrayList<Integer> lst10 = new ArrayList<>(List.of(19, 2, 30, 4, 5, 6, 4));
        for(int vl : lst10){
            System.out.print(vl + " ");
        }
        //c2:
        System.out.println();
        for(int i = 0; i < lst10.size(); i++){
            int vl = lst10.get(i);
            System.out.print(vl + " ");
        }
    }
}
