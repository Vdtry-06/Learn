package Basic_java.Bai15_date_time;

import java.text.SimpleDateFormat;
import java.util.Calendar;

public class Date_time {
    public static void main(String[] args) {
        Calendar cal = Calendar.getInstance();
        // System.out.println(cal);

        // lay ngay thang nam
        // int day = cal.get(Calendar.DAY_OF_MONTH);
        // int month = cal.get(Calendar.MONTH);
        // int year = cal.get(Calendar.YEAR);
        // System.out.println(day);
        // System.out.println(month);
        // System.out.println(year);

        // set ngay thang nam theo y muon
        // cal.set(Calendar.DAY_OF_MONTH, 19);
        // cal.set(Calendar.MONTH, 11); // thang chi chay tu 0 -> 11
        // cal.set(Calendar.YEAR, 2023);
        // ktra ngay thang
        // int day = cal.get(Calendar.DAY_OF_MONTH);
        // int month = cal.get(Calendar.MONTH);
        // int year = cal.get(Calendar.YEAR);
        // System.out.println(day + "/" + month + "/" + year);

        // xuat theo dinh dang
        SimpleDateFormat dinhDang = new SimpleDateFormat("dd/MM/yyyy hh:mm:ss a");
        // tao 1 doi tuong date de get time trong doi tuong cal
        java.util.Date d = cal.getTime();
        String s = dinhDang.format(d);
        System.out.println(s);
    }
}
