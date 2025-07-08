
 
// Expected results:
var arr = [
    ['name', 'Sơn Đặng'],
    ['age', 18],
];
function arrToObj(array) {
    var myString = array.join(', ');
    return myString;
}
console.log(arrToObj(arr)); // { name: 'Sơn Đặng', age: 18 }
