package Code_PTIT.File_Input_And_Output.J07025;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.temporal.ChronoUnit;
import java.util.Date;

public class Customer implements Comparable<Customer> {
    private static int cnt = 1;
    private String code;
    private String name;
    private String sex;
    private String birth;
    private String address;
    private Long time;
    private LocalDate date;

    public Customer(String name, String sex, String birth, String address) throws ParseException {
        this.code = String.format("KH%03d", cnt++);
        this.name = name.toLowerCase().trim();
        this.sex = sex;
        this.birth = birth;
        this.address = address;
        this.name = processName();
        this.birth = processBirth();
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");
        this.date = LocalDate.parse(this.birth, formatter);
    }
    public String processName() {
        String[] parts = this.name.split("\\s+");
        StringBuilder sb = new StringBuilder();
        for(String part : parts) {
            sb.append(Character.toUpperCase(part.charAt(0))).append(part.substring(1).toLowerCase()).append(" ");
        }
        sb.deleteCharAt(sb.length() - 1);
        return sb.toString();
    }
    public String processBirth() throws ParseException {
        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
        this.birth = sdf.format(sdf.parse(this.birth));
        return this.birth;
    }
    @Override
    public int compareTo(Customer o) {
        return this.date.compareTo(o.date);
    }
    @Override
    public String toString() {
        return code + " " + name + " " + sex + " " + address + " " + birth;
    }
}
