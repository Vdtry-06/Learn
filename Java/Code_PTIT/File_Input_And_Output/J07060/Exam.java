package Code_PTIT.File_Input_And_Output.J07060;

import java.text.ParseException;
import java.text.SimpleDateFormat;

public class Exam {
    private static int cnt = 1;
    private String id;
    private String day;
    private String hour;
    private String time;
    private int room;
    public Exam(String day, String hour, int room) throws ParseException {
        this.id = String.format("C%03d", cnt++);
        this.day = day;
        this.hour = hour;
        this.room = room;
        time = this.day + " " + this.hour;
        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy HH:mm");
        this.time = sdf.format(sdf.parse(time));

    }
    public String getId() {return this.id;}
    public String getTime() {return this.time;}
    @Override
    public String toString() {
        return day + " " + hour + " " + room;
    }
}
