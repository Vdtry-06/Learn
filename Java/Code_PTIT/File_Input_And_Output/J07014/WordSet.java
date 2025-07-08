package Code_PTIT.File_Input_And_Output.J07014;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.TreeSet;

public class WordSet {
    private TreeSet<String> words;

    private WordSet(TreeSet<String> words) {
        this.words = words;
    }

    public WordSet(String filename) throws IOException {
        words = new TreeSet<>();
        BufferedReader br = new BufferedReader(new FileReader(filename));
        String line;
        while ((line = br.readLine()) != null) {
            // Tách các từ trong dòng và thêm vào TreeSet
            String[] parts = line.toLowerCase().split("\\s+");
            words.addAll(Arrays.asList(parts));
        }
        br.close();
    }

    public WordSet intersection(WordSet other) {
        TreeSet<String> result = new TreeSet<>(words);
        result.retainAll(other.words);
        return new WordSet(result);
    }

    public WordSet union(WordSet other) {
        TreeSet<String> result = new TreeSet<>(words);
        result.addAll(other.words);
        return new WordSet(result);
    }

    @Override
    public String toString() {
        return String.join(" ", words);
    }
}
