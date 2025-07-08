/*
    Các toán hạng: 
        +,  cộng
        -,  trừ
        *,  nhân
        /,  chia
        %,  mod
        ++, += 1
        --, -=1
        **, mũ

        ++a: 
            việc 1:  + 1 cho a => a = a + 1;
            việc 2:  trả về a sau khi được + 1
        a++:
            việc 1: "a copy" 
            việc 2: cộng 1 của a => a = a - 1;
            việc 3: trả về "a copy"
    
    Boolean:
        wrong: 
        0, 
        false, 
        "", '', 
        undefined,  có thể đại diện xâu không hợp lệ
        NaN,        có thể đại diện số không hợp lệ: 
            kiểm tra: NaN:  isNaN(tên biến) 
        null
    
    Symbol: 
        var id = Symbol('id');  // Unique: duy nhất
    
    ==: chỉ so sánh giá trị
    ====: so sánh kiểu dữ liệu sau đó so sánh giá trị
    &&: lấy giá trị cuối != wrong
    ||: lấy giá trị đầu != wrong
*/

var number = 6;

// var output = number++ + --number;
//               6        +     6
// var output = ++number * 2 - number-- * 2;
//                  7    * 2 -    7     * 2
// console.log('Output', output);

// Number type
var a = 1;
console.log(typeof a);

// String type
var fullName = 'Vuong Duc Trong';
console.log(typeof fullName);

// Boolean type
var isSuccess = true;
console.log(typeof isSuccess);

// Undifined type
var age;
console.log(typeof age);

// Null
var isNull = null;
console.log(typeof isNull);

// Symbol 
var id = Symbol('id');  // Unique: duy nhất
console.log(typeof isNull);


// Function
var myFunction = function(){
    alert('Hi. Xin chao cac ban!');
}
console.log(typeof myFunction);

// myFunction();

// Object types
var myObject = {
    name: 'Trong',
    age: 20,
    adress: 'Ha Noi',
    myFunction: function(){

    }
};
console.log(typeof myObject);

// console.log('myObject', myObject);

var myArray = [
    'JavaScript',
    'PHP',
    'Ruby'
];
console.log(typeof myArray);
// console.log('myArray', myArray);

var a = '1';
var b = 1;
console.log(a === b);