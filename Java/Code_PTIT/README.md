hasNext() : còn có mã thông báo nào nữa không

hasNextDouble() : liệu mã thông báo tiếp theo có thể được hiểu là loại double không

hasNextInt() : liệu mã thông báo tiếp theo có thể được diễn giải là kiểu int không

hasNextLine() : còn dòng nào nữa không

File đầu vào:
    Scanner input = new Scanner(new File("<file name 1>"));

File đầu ra:
    PrintWriter output = new PrintWriter(new File("<file name 2>""));

File BINARY:
![img.png](img.png)
FileInputStream <name> = new FileInputStream(new File("<file name>"));

PrintStream <name> = new PrintStream(new File("<file name>"));

1.FileInputStream và FileOutputStream: Dùng để xử lý dữ liệu nhị phân thô từ/đến file.
Các file nhị phân như hình ảnh, tệp âm thanh, hoặc các loại dữ liệu không phải văn bản

2.DataInputStream và DataOutputStream: Dùng để đọc/ghi dữ liệu nguyên thủy từ/đến file hoặc stream.
Dữ liệu nguyên thủy (primitive) như int, float, double từ tệp hoặc luồng nhị phân.

3.BufferedInputStream và BufferedOutputStream: Dùng để tăng tốc độ xử lý bằng cách sử dụng bộ đệm.
Một lượng lớn dữ liệu từ file hoặc luồng

4.PrintStream: Dùng để ghi dữ liệu văn bản và định dạng nó một cách dễ dàng.
Dữ liệu văn bản vào file hoặc console, và không cần sử dụng định dạng nhị phân.

5.ObjectOutputStream: Dùng để ghi các đối tượng Java thành dữ liệu nhị phân.
Một đối tượng (cùng các thuộc tính của nó) vào file hoặc gửi qua mạng. 
Điều này thường được dùng trong việc lưu trữ đối tượng Java hoặc thực hiện serialization.

Exception Handel: xử lý ngoại lệ
![img_1.png](img_1.png)

try{
}

catch(FileNotFoundException exception) {
    sout("Khong tim thay file");
} 

catch(IOException exception) {
    sout("Khong the ghi vao file");
}

catch(IOException ioe) {
    sout("Loi doc file");
}

finally {
    // <Tên file>.close(); // Nhưng bản thân close là 1 exception nên:
    
    try {
    }

    catch(IOException ioe){
        sout("Lỗi đóng file");
    }
}


getLocalizedMessage(): chuỗi mô tả lỗi

getStackTrace()      : mảng đối tượng: chứa thông tin nơi xảy ra lỗi

printStackTrace()    :  hiển thị stacktrace trên bảng điều khiển


Encapsulation: đóng gói
    - Quản lý mã nguồn và tái sử dụng code
    - Đóng gói vật lý
    import: là gói
    - impotant: MVC
    Ex: Đóng gói server
    - Ẩn giấu thông tin: private
    accessor: get() : lấy thông tin ra bên ngoài
    immutable: object ko thay đổi từ khi tạo ra (ko có method set)
    mutable: set()
    protect: có thể thay đổi hoàn toàn bên trong, nhưng ko thay đổi bên ngoài

Inheritance: kế thừa
    - is-a relationship: có mối quan hệ với nhau
    - Lớp con <subclass> có thể kế thừa từ lớp cha <superclass>
    - inheritance hierarchy: tính phân cấp
    - protected vẫn có thể truy cập được bên ngoài
    - final type: lớp con không thể thay đổi được nó
    - final getvalue: lớp con không thể ghi đè lên được nó
    - final class name: không có lớp con nào cả
    - Nếu bạn không muốn các lớp khác kế thừa từ một lớp, hãy sử dụng final

Polymorphism: đa hình:
    1. Đa hình biến: ép kiểu
    2. Đa hình hàm: - nạp chồng: append nhiều tham số 
                    - ghi đè: thay thế tạo tính riêng biệt cho lớp con override
    3. Đa hình đối tượng: shadow: làm thuộc tính super ẩn đi và hiện sub: 
                                  phương thức có thể bị ghi đè, còn thuộc tính thì không
    - giao diện 2 người user và admin đều có username, password:
    Tính kế thừa từ interface có thuộc tính và hành vi chung, 
    vẫn giữ được sự độc lập về tính năng của từng lớp
    Interface:
        - 3 loại kết thừa:  1. Kế thừa trực tiếp
                            2. Kế thừa khuôn mẫu
                            3. Kế thừa đặc tính

Abstraction: trừu tượng
    - là lớp bị hạn chế không thể sử dụng để tạo đối tượng (để truy cập vào lớp này, 
    phải kế thừa từ một lớp khác).
    - không có định nghĩa phương thức
    - nếu 1 lớp có phương thức trừu tượng, hoặc kế thừa phương thức trừu tượng
    mà không ghi đè, thì lớp đó phải được khai báo trừu tượng
    - không thể có 1 hàm tạo, không thể xây dựng đối tượng, nhưng có thể khai báo
    tham chiếu
    Ex: Employee e; yes 
        e = new Employee(); no constructor


DateTimeFormatter myFormatObj = DateTimeFormatter.ofPattern("dd-MM-yyyy HH:mm:ss");
Định dạng thời gian: ví dụ: 20-10-2024 12:59:24
ofPattern()chấp nhận mọi loại giá trị:
    - yyyy-MM-dd: 1988-09-29
    - dd/MM/yyyy: 29/09/1988
    - dd-MMM-yyyy: 29-Sep-1988
    - E, MMM dd yyyy: Thu, Sep 29 1988

import java.text.SimpleDateFormat;
import java.text.ParseException;
SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
this.checkIn = sdf.format(sdf.parse(checkIn));
chuẩn hóa ngày tháng năm

import java.time.format.DateTimeFormatter;
import java.time.temporal.ChronoUnit;
// định dạng theo formatter
DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");
LocalDate startDate = LocalDate.parse(this.come, formatter);
LocalDate endDate = LocalDate.parse(this.leave, formatter);
long between = ChronoUnit.DAYS.between(startDate, endDate);
// tính số ngày giữa 2 thời gian đã cho

ArrayList để lưu trữ, truy cập dữ liệu
LinkedList thao tác dữ liệu:
    addFirst(), removeFirst(), getFirst(): thêm, xóa, lấy đầu danh sách
    tương tự Last(): thêm, xóa, lấy cuối danh sách

Collections: sắp xếp theo danh sách
    thuận: Collections.sort(<Name ArrayList>)
    ngược: Collections.sort(<Name ArrayList>, Collections.reverseOrder())

HashMap: key/value: các giá trị khác nhau => TreeMap: sắp xếp 
    put(key, value): thêm mục vào lớp
    get(key): tham chiếu đến khóa của nó = value
    remove(key): xóa 1 mục
    clear(): xóa tất cả
    size(): kích thước
    keySet(): lấy khóa : <name hashmap>.get(i): lấy giá trị
    values(): lấy giá trị

HashSet: không có thứ tự, các giá trị khác nhau
    add(value): thêm 1 mục vào lớp
    contains(value): kiểm tra xem 1 mục có tồn tại không
    remove(value): xóa 1 mục
    clear(): xóa tất cả

Iterator: vòng lặp
    hasNext()
    next()

Wrapper:
    primitive(nguyên thủy): byte, short, int, long, float, double, boolean, char
    wrapper(bao bọc): Byte, Short, Integer, Long, Float, Double, Boolean, Character

Regular Expressions: biểu thức chính quy
    Pattern Lớp - Xác định một mẫu (được sử dụng trong tìm kiếm)
    Matcher Lớp - Được sử dụng để tìm kiếm mẫu
    PatternSyntaxException Lớp - Chỉ ra lỗi cú pháp trong mẫu biểu thức chính quy

Flags:
    Pattern.CASE_INSENSITIVE- Viết hoa chữ thường sẽ bị bỏ qua khi thực hiện tìm kiếm.
    Pattern.LITERAL- Các ký tự đặc biệt trong mẫu sẽ không có ý nghĩa đặc biệt nào và sẽ được coi như các ký tự thông thường khi thực hiện tìm kiếm.
    Pattern.UNICODE_CASE- Sử dụng kết hợp với CASE_INSENSITIVEcờ để bỏ qua trường hợp các chữ cái nằm ngoài bảng chữ cái tiếng Anh
    
Threads: luồng: thực hiện nhiều việc cùng một lúc, không làm gián đoạn chương trình chính.
Lambda: chúng không cần tên và có thể được triển khai ngay trong thân phương thức.
    parameter -> expression
    (parameter1, parameter2) -> expression
    (parameter1, parameter2) -> { code block }

public class Student implements Comparable<Student> {
    public int compareTo(Student o) {
        return msv.compareTo(o.msv);
    }
}

Chuyển đổi đúng tên
public String getName() {
    String [] parts = name.split("\\s+");
    StringBuilder res = new StringBuilder();
    for(String part: parts) {
        res.append(Character.toUpperCase(part.charAt(0))).append(part.substring(1)).append(" ");
    }
    res.deleteCharAt(res.length() - 1);
    return res.toString();
}

khi dùng parse: thì cần thêm trường hợp ParseException:
trường hợp ngoại lệ
trim(): loại bỏ khoảng trắng ở đầu và cuối

Trong Java, Serializable là một giao diện (interface) đánh dấu (marker interface), nghĩa là nó không có bất kỳ 
phương thức nào cần triển khai. Khi một lớp thực hiện giao diện Serializable, điều đó cho phép các đối tượng của 
lớp này có thể được chuyển đổi thành một chuỗi byte, từ đó có thể lưu trữ hoặc truyền qua mạng.

queue: interface: Queue<Integer> q = new LinkedList<>();
stack: class : linkedlist: chậm

Generic Methods: