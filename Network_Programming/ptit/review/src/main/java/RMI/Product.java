package RMI;

import java.io.Serializable;
import java.math.BigDecimal;
import java.math.RoundingMode;

import static java.lang.Math.pow;
import static java.lang.Math.round;

public class Product implements Serializable {
    private static final long serialVersionUID = 20151107L;

    private String id;
    private String code;
    private double importPrice;
    private double exportPrice;

    public Product () {

    }

    public Product(String id, String code, double importPrice, double exportPrice) {
        this.id = id;
        this.code = code;
        this.importPrice = importPrice;
        this.exportPrice = exportPrice;
    }


    public void updateCode() {
        this.code = this.code.toUpperCase();
    }

    public void updateExportCode() {
        this.exportPrice = round( this.importPrice * 1.2 * 100.0) / 100.0;
    }
}
