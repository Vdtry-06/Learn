// Hợp nhất Array, Object

var array1 = ['JavaScript', 'PHP', 'Ruby'];
var array2 = ['ReactJS', 'Dart'];
var array3 = [...array1, ...array2];
console.log(array3);
console.log(...array3); // Spread

// var object1 = {
//     name: 'JavaScript'
// }
// var object2 = {
//     price: 1000
// }
// var object3 = {
//     ...object1, // Spread
//     ...object2  // Spread
// }
// console.log(object3);