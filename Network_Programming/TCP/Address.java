package TCP;

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

        // Tách theo ký tự không phải chữ hoặc số
        String[] parts = addressLine.trim().split("[^a-zA-Z0-9]+");
        StringBuilder result = new StringBuilder();

        // Đếm số lượng nhóm số
        int numberCount = 0;
        for (String part : parts) {
            if (!part.isEmpty() && part.matches("\\d+")) {
                numberCount++;
            }
        }

        int currentNumberIndex = 0;
        for (int i = 0; i < parts.length; i++) {
            String part = parts[i];
            if (part.isEmpty()) continue;

            if (part.matches("\\d+")) {
                currentNumberIndex++;

                if (numberCount == 1) {
                    // Nếu chỉ có 1 nhóm số: luôn thêm khoảng trắng sau số
                    result.append(part).append(" ");
                } else {
                    // Nếu có nhiều hơn 1 nhóm số
                    if (currentNumberIndex == 1) {
                        // Nhóm số đầu tiên: thêm khoảng trắng sau
                        result.append(part).append(" ");
                    } else {
                        // Các nhóm số tiếp theo: dính liền với từ trước đó
                        result.append(part);
                        // Thêm khoảng trắng sau số nếu không phải số cuối cùng
                        if (i < parts.length - 1) {
                            result.append(" ");
                        }
                    }
                }
            } else {
                // Nếu là chữ thì chuẩn hóa viết hoa chữ cái đầu
                String word = part.substring(0, 1).toUpperCase() + part.substring(1).toLowerCase();
                result.append(word).append(" ");
            }
        }

        return result.toString().trim();
    }

    public static String processPostalCode(String postalCode) {
        if (postalCode == null) return "";

        String cleaned = postalCode.replaceAll("[^0-9-]", "");
        return cleaned;
    }
}