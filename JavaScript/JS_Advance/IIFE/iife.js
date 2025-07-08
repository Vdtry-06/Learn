
// (() => {
//     console.log("NOW");
// })()
// 1. IIFE trông như thế nào?
(function(message) {
    console.log("Message: ", message);
})('Hello word!')

// 2. Dùng dấu ; trước IIFE

let fullName = 'Vuong Trong';
(function() {

})()

// 3. IIFE là 1 hàm "private"

let i = 0;
(function myFunction(){
    ++i;
    console.log(i);
    if(i < 10) myFunction()
})();

// 4. Sử dụng IIFE khi nào : 
// khi đặt tên biến ở trong hàm để không bị trùng tên 

// 5. Các tạo ra 1 IIFE 
(function() {
    let fullName = "Vuong Trong";
    console.log(fullName);
})()

// 6. Ví dụ sử dụng IIFE
const app = (function() {
    // private: bảo toàn tính toàn vẹn dữ liệu,
    // không bị phá vỡ
    const cars = []
    return{
        get(index) {
            return cars[index]
        },
        add(car) {
            cars.push(car)
        },
        edit(index, car) {
            cars[index] = car
        },
        delete(index) {
            cars.splace(index, 1)
        }
    };
})();
