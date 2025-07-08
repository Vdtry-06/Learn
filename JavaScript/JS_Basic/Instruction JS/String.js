// Tạo chuỗi: có 2 cách nên sử dụng cách 1
// c1:
// var fullName = "Vuong Duc Trong";
// console.log(fullName);
// c2:
// var fullName = new String("Vuong Duc Trong");
// console.log(fullName);


// 1 số case sử dụng backslash(\)
// 2 dấu nhập vào "\\" = \ trên màn hình
// var fullName = 'Vuong Duc Trong la \'Sieu Nhan\'';
// console.log(fullName.length);


// var firstName = 'Trong';
// var LastName = 'Vuong';
// c1
// console.log('Toi la ' + firstName + ' ' + LastName);
// c2
// console.log(`Toi la ${firstName} ${LastName}`);


/*
    Thuộc tính của String:
        1. s.length: độ dài chuỗi

        2. s.indexOf('kí tự trong chuỗi s'): vị trí đầu của chuỗi kí tự trong s.
                + in ra vị trí bắt đầu của kí tự
                + nếu không có in ra -1

           s.LastIndexOf('kí tự trong chuỗi s'): vị trí cuối của chuỗi kí tự trong s.

        4. s.search('kí tự trong chuỗi s'): tìm vị trí của chuỗi kí tự trong s.

        5. s.slice(start index, end index); trích chuỗi con trong s.
            có thể cắt 2 hướng trái phải, phải trái:
                ví dụ: [2, 5] or [-3, -1]
        
        6. s.replace('kí tự trong chuỗi s', 'kí tự mới'): thay thế chuỗi kí tự đầu tiên trong s.
           s.replace(/ kí tự trong chuỗi s /g , 'Kí tự mới'): thay thế toàn bộ chuỗi kí tự trong s.
        
        7. s.toUpperCase(): chuyển sang chữ hoa.
           s.toLowerCase(): chuyển sang chữ thường.
        
        8. s.trim(): loại bỏ khoảng trắng đầu và cuối xâu s

        9. s.split(', '): cắt chuỗi string thành Array
            ex: s = 'java, C++, Python' => s = ["java", "C++", "Python"]
            s.split(','): => s = ["java", " C++", " Python"]
            s.split(''); => s = ["j", "a", "v", "a"]

        10. s.charAt(index): kí tự ở vị trí index - 1: nếu index >= s.length(): => ''
            s[index]: kí tự ở vị trí index - 1: nếu index >= s.length(): => undefined

        11. number.toString(): chuyển số thành xâu

        12. number.toFixed(): làm tròn số và chuyển số thành xâu
            number.toFixed(a): làm tròn đến số thập phân thứ a
*/
