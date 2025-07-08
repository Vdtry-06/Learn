// Promise methods: resolve, reject, all

// 1. Promise.resolve : chỉ đúng
// 2. Promise.reject : chỉ sai
// 3. Promise.all : chạy song song khi không phụ thuộc nhau
    // nếu 1 trong 2... có lỗi sẽ ko chạy nữa chuyển sang catch

// Thư viện: output luôn luôn là 1 promise


// var promise = Promise.resolve('Success!'); // 1. Promise.resolve 
var promise = Promise.reject('Error!'); // 2. Promise.reject

promise
    .then(function(result) {
        console.log('result:', result);
    })
    .catch(function(err) {
        console.log('result:', err);
    })


// 3. Promise.all  
var promise1 = new Promise(function(resolve) {
    setTimeout(function() {
        resolve([1]);
    }, 1000);
}) 
var promise2 = new Promise(function(resolve) {
    setTimeout(function() {
        resolve([2, 3]);
    }, 2000);
})
Promise.all([promise1, promise2])
    .then(function(result) {
        var result1 = result[0];
        var result2 = result[1];
        console.log(result1.concat(result2)); // nối mảng
    })