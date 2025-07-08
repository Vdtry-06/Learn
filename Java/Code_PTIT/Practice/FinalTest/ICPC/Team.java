package Code_PTIT.Practice.FinalTest.ICPC;

import java.io.Serializable;
import java.util.ArrayList;

public class Team implements Comparable<Team>, Serializable {
    private static int cnt = 1;
    private School school;
    private String name;
    private String schoolId;
    public Team(String name, String schoolId, ArrayList<School> schools) {
        this.name = name;
        this.schoolId = schoolId;
        this.school = findSchoolIdBySchools(schoolId, schools);
    }

    private School findSchoolIdBySchools(String id, ArrayList<School> schools) {
        for (School school : schools) {
            if(schoolId.equals(school.getId())) {
                return school;
            }
        }
        return null;
    }

    public int compareTo(Team o) {
        if(this.school.getName().equals(o.school.getName())) {
            return this.name.compareTo(o.name);
        }
        return this.school.getName().compareTo(o.school.getName());
    }

    public String toString() {
        return String.format("team%02d", cnt++) + " " + name + " " + school;
    }
}
