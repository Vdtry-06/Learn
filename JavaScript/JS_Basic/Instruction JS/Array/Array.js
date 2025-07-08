var languages = [
    'JavaScript',
    'PHP',
    'Ruby',
    'Dart',
    // null,
    // undefined,
    // function(){

    // },
    // {},
    // 123
];
// c2: var languages = new Array(... , ... , ...);
// console.log(languages);

// languages.isArray(): kiểm tra Array
// console.log(Array.isArray());

// languages.length: độ dài Array
// console.log(typeof languages.length);

// languages[i]: lấy giá trị trong Array
// console.log(languages[2]);

// 1. ToString: chuyển Array sang chuỗi
console.log(languages.toString());

// 2. Join: thêm kí tự cho từng chuỗi trong xâu
console.log(languages.join(' - '));

// 3. Pop: xóa giá trị cuối và in ra giá trị đó : rỗng in ra: undefined
console.log(languages.pop());

// 4. Push: thêm 1 or nhiều phần tử phần tử vào cuối mảng và trả về độ dài mảng
console.log(languages.push('Dart'));

// 5. Shift: xóa phần tử đầu mảng và in ra phần tử đó : rỗng in ra: undefined
console.log(languages.shift());

// 6. Unshift: thêm 1 or nhiều phần tử phần tử vào đầu mảng và trả về độ dài mảng
console.log(languages.unshift('JavaScript'));

// 7. Splicing: xóa or chèn
// languages.splice(start, delete_count); xóa delete_count phần tử bắt đầu từ vị trí start
languages.splice(1, 1);
// languages.splice(1, 0, 'Dart'); xóa 0 phần tử bắt đầu từ 1 và chèn 'Dart' vào vị trí 1
languages.splice(1, 0, 'Dart');
console.log(languages);

// 8. Concat: nối Array
var languages2 = [
    'C++',
    'Python',
];
console.log(languages.concat(languages2));

// 9. Slicing: lấy ra mảng con từ st -> end, xuôi ngược đều được. or copy mảng 
// cắt từ index = [start, end)
console.log(languages.slice(1, 2));

// index = [0) copy Array ban đầu
console.log(languages.slice(0));