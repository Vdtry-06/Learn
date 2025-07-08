package Basic_java.Bai22_HashMap;

import java.util.HashMap;

public class Hashmap {
    public static void main(String[] args) {
        // khai bao
        HashMap<Integer, String> map = new HashMap<>();
        HashMap<Integer, Float> map2 = new HashMap<>();

        // them cac phan ti vao hashmap
        map.put(1, "apple");
        map.put(2, "banana");
        map.put(3, "cherry");

        // lay gia tri cua 1 phan tu
        String value = map.get(1);
        System.out.println(value);

        // xoa phan tu khoi hasmap
        map.remove(2);
        System.out.println(map.get(2));
        
        // Kiem tra xem 1 phan tu co ton tai trong map hay ko
        boolean check = map.containsKey(4);
        System.out.println(check);

        // kiem tra 1 gia tri co ton tai trong map hay ko
        boolean check1 = map.containsValue("cherry");
        System.out.println(check1);

        // kiem tra hasmap co rong hay khong
        boolean bien = map.isEmpty();
        System.out.println(bien);

        // lay so luong phan tu trong hasmap
        int slpt = map.size();
        System.out.println(slpt);

        // duyet hasmap
        for(Integer key: map.keySet()){
            String vl = map.get(key);
            System.out.println(key + " " + vl);
        }
    }
}
