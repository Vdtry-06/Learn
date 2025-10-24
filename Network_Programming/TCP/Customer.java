package TCP;

import java.io.Serializable;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

public class Customer implements Serializable {
    private static final long serialVersionUID = 20170711L;
    private int id;
    private String code;
    private String name;
    private String dayOfBirth;
    private String userName;

    public void updateName() {
        String []parts = name.toLowerCase().split(" ");
        String newName = parts[parts.length - 1].toUpperCase() + ", ";
        for (int i = 0; i < parts.length - 1; i++) {
            newName += parts[i].substring(0, 1).toUpperCase() + parts[i].substring(1) + " ";
        }
        newName = newName.substring(0, newName.length() - 1);
        this.name = newName;
    }

    public void updateDate() {
        DateTimeFormatter in = DateTimeFormatter.ofPattern("MM-dd-yyyy");
        DateTimeFormatter out = DateTimeFormatter.ofPattern("dd/MM/yyyy");
        LocalDate date = LocalDate.parse(dayOfBirth, in);
        String format = date.format(out);
        this.dayOfBirth = format;
    }

    public void updateUsername() {
        String []parts = name.toLowerCase().split(" ");
        String usernname = "";
        for (int i = 0; i < parts.length - 1; i++) {
            usernname += parts[i].substring(0, 1);
        }
        usernname += parts[parts.length - 1];
        this.userName = usernname;
    }

}
