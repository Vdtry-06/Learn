package Code_PTIT.Practice.Day2.B3;

import java.util.Arrays;
import java.util.Collections;
import java.util.Set;
import java.util.TreeSet;
import java.util.stream.Collectors;

public class WordSet {
    private Set<String> word;
    public WordSet(String input) {
        word = Arrays.stream(input.toLowerCase().split("\\s+")).collect(Collectors.toCollection(TreeSet::new));
    }
    public String union(WordSet other) {
        TreeSet<String> union = new TreeSet<>(word);
        union.addAll(other.word);
        return String.join(" ", union);
    }
    public String intersection(WordSet other) {
        TreeSet<String> intersection = new TreeSet<>(word);
        intersection.retainAll(other.word);
        return String.join(" ", intersection);
    }
}
