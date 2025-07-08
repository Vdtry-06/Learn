package Code_PTIT.Practice.Day2.B11;

import java.util.ArrayList;

public class Team implements Comparable<Team>{
    private static int cnt = 1;
    private University university;
    private String teamName;
    private String id;
    public Team(String universityId, ArrayList<University> universities, String teamName) {
        this.university = findUniversityIdByUniversity(universityId, universities);
        this.teamName = teamName;
        this.id = "team";
    }
    private University findUniversityIdByUniversity(String universityId, ArrayList<University> universities) {
        for (University university : universities) {
            if(universityId.equals(university.getId())) {
                return university;
            }
        }
        return null;
    }
    @Override
    public int compareTo(Team o) {
        if(university.getName().equals(o.university.getName())) {
            return teamName.compareTo(o.teamName);
        }
        return university.getName().compareTo(o.university.getName());
    }
    @Override
    public String toString() {
        id = id + String.format("%02d", cnt++);
        return id + " " + teamName + " " + university.getName();
    }
}
