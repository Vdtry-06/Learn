package UDP;

import java.io.Serializable;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

public class Book implements Serializable {
    private static final long serialVersionUID = 20251107L;
    private String id;
    private String title;
    private String author;
    private String isbn;
    private String publishDate;

    public Book(String id, String title, String author, String isbn, String publishDate) {
        this.id = id;
        this.title = title;
        this.author = author;
        this.isbn = isbn;
        this.publishDate = publishDate;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        String[] parts = title.split(" ");
        String newTitle = "";
        for (String s :parts){
            newTitle += s.substring(0, 1).toUpperCase() + s.substring(1).toLowerCase() + " ";
        }
        newTitle = newTitle.substring(0, newTitle.length() - 1);
        this.title = newTitle;
    }

    public String getAuthor() {
        return author;
    }

    public void setAuthor(String author) {
        String[] parts = author.split(" ");
        String newAuthor = parts[0].toUpperCase() + ", ";
        for (int i = 1; i < parts.length; i++){
            newAuthor += parts[i].substring(0, 1).toUpperCase() + parts[i].substring(1).toLowerCase() + " ";
        }
        newAuthor = newAuthor.substring(0, newAuthor.length() - 1);
        System.out.println(newAuthor);
        this.author = newAuthor;
    }

    public String getIsbn() {
        return isbn;
    }

    public void setIsbn(String isbn) {
        String newIsbn = isbn.substring(0, 3) +
                "-" + isbn.substring(3, 4) +
                "-" + isbn.substring(4, 6) +
                "-" + isbn.substring(6, 12) +
                "-" + isbn.substring(12);
        this.isbn = newIsbn;
    }

    public String getPublishDate() {
        return publishDate;
    }

    public void setPublishDate(String publishDate) {
        DateTimeFormatter in = DateTimeFormatter.ofPattern("yyyy-MM-dd");
        DateTimeFormatter out = DateTimeFormatter.ofPattern("MM/yyyy");
        LocalDate date = LocalDate.parse(publishDate, in);
        String formatDate = date.format(out);
        this.publishDate = formatDate;
    }
}
