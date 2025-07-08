/*
    JSON : // JavaScript Object Notation
        1. là 1 định dạng trao đổi dữ liệu nhẹ (chuỗi)
        2. không phụ thuộc vào ngôn ngữ *
        3. "tự mô tả" và dễ hiểu
        Json: Number, Boolean, Null, Array, String, Object

        Mã hóa / giải mã
        Encode / Decode
        + Stringify: Từ JavaScript types -> JSON
        + Parse: Từ Json -> JavaScript types
*/

var json = '["JavaScript", "PHP"]';
// var json = '{"name": "Vuong Trong", "age": 20}';

var a = '"abc"';
// console.log(typeof JSON.parse(a));
// console.log(JSON.parse(json));
// var object = JSON.parse(json);
// console.log(object);
console.log(JSON.stringify(json));