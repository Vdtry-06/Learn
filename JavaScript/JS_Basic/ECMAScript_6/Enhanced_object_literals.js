// 1. Định nghĩa key: value cho object
// 2. Định nghĩa method cho object
// 3. Định nghĩa key cho object dưới dạng biến

// var name = 'JavaScript';
// var price = 1000;
// var course = {
//     name,
//     price,
//     getName() {
//         return name;
//     }
// };

// console.log(course.getName());

var fieldName = 'Name';
var fieldPrice = 'Price';
const course = {
    [fieldName]: 'JavaScript',
    [fieldPrice]: 1000
};

console.log(course);