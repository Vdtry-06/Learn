var array = ['JavaScript', 'PHP', 'Ruby'];
// var [a, , c] = array;
// console.log(a, c);

// var [a, ...rest] = array; // toán tử còn lại
// console.log(rest);

function logger(...params) { // lấy ra phần còn lại
    console.log(params);
} // tạo ra mảng

console.log(logger(1, 2, 3, 4, 5, 6, 7, 8));