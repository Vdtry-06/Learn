/*
    Tính chất của function:
        - Không thực thi khi định nghĩa
        - Sẽ thực thi khi được gọi
        - Có thể nhận tham số
        - Có thể trả về 1 giá trị
*/

// Tạo hàm đầu tiên

function showDialog(message, message2) {
    // message: tham số
    // alert('Hi xin chao cac ban');
    // console.log(message, message2);
    console.log(arguments);
    // đối tượng arguments: có thể truyền được nhiều biến
}

// showDialog('Test Message', 'Test2', 1234);
// Test Message: đối số
// Có thể truyền bất kì kiểu dữ liệu vào

function writeLog(){
    var myString = "";
    var d = 0;
    for(var param of arguments){
        ++d;
        myString += `${param}`;
        if(d != arguments.length) myString += ` - `;
    }
    console.log(myString);
}
// writeLog('Test Message', 'Test2', 1234)

// var isConfirm = confirm('Message?');
// console.log(isConfirm);

// Nếu hàm không trả về giá trị thì in ra undefined
function add(a, b) {
    return a + b, [a, b], a.toString() + b.toString();
}
var res = add(2, 8);
// console.log(res);

function showMessage() {
    function showMessage2(){
        console.log('Message 2');
    }
    showMessage2();
}
// showMessage();

/*
    Các loại function:
        1. Declaration function: gọi được trước khi định nghĩa
        2. Expression function
        3. Arrow function
*/

Message1();
function Message1() {
    console.log('Declaration Function');
}

var Message2 = function() {
    console.log('Expression Function');
}

