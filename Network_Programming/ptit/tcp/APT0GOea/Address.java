package ptit.tcp.APT0GOea;


import java.io.Serializable;

public class Address implements Serializable {
    private static final long serialVersionUID = 20180801L;

    private int id;
    private String code;
    private String addressLine;
    private String city;
    private String postalCode;

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getCode() {
        return code;
    }

    public void setCode(String code) {
        this.code = code;
    }

    public String getAddressLine() {
        return addressLine;
    }

    public void setAddressLine(String addressLine) {
        this.addressLine = addressLine;
    }

    public String getCity() {
        return city;
    }

    public void setCity(String city) {
        this.city = city;
    }

    public String getPostalCode() {
        return postalCode;
    }

    public void setPostalCode(String postalCode) {
        this.postalCode = postalCode;
    }

    @Override
    public String toString() {
        return "Address{id=" + id +
                ", code='" + code + '\'' +
                ", addressLine=" + addressLine +
                ", city=" + city  +
                ", postalCode=" + postalCode + '}';
    }

    public static String processAddressLine(String addressLine) {
        if (addressLine == null || addressLine.isEmpty()) {
            return "";
        }

        String[] parts = addressLine.split("[^a-zA-Z0-9]+");
        StringBuilder result = new StringBuilder();
        for (String part : parts) {
            if (part.isEmpty()) continue;

            if (part.matches("\\d+")) {
                // Nếu là số => giữ nguyên
                result.append(part).append(" ");
            } else {
                // Nếu là chữ => viết hoa chữ cái đầu
                String word = part.substring(0, 1).toUpperCase() + part.substring(1).toLowerCase();
                result.append(word).append(" ");
            }
        }
        System.out.println(result);
        return result.toString().trim();
    }

    public static String processPostalCode(String postalCode) {
        if (postalCode == null) return "";

        String cleaned = postalCode.replaceAll("[^0-9-]", "");
        return cleaned;
    }
}
