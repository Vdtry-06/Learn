/* 
    Vòng lặp: Loop

    1. for - Lặp với điều kiện đúng
    2. for/in - Lặp qua key của đối tượng
    3. for/of - Lặp qua value của đối tượng 
    4. while - Lặp khi điều kiện đúng
    5. do/while - Lặp ít nhất 1 lần, sau đó lặp khi điều kiện đúng
*/

// FOR LOOP
// for(var i = 1; i <= 1000; ++i){
//     console.log(`${i}`);
// }

var myArray = [
    'JavaScript',
    'PHP',
    'Java',
    'Dart',
    'Ruby',
    'Python',
    'C++',
];

// for(var i = 0; i < myArray.length; ++i){
//     console.log(myArray[i]);
// }

// FOR IN: với key là chỉ số
// for(var key in myArray){
//     console.log(myArray[key]);
// }

var myString = 'JavaScript';
// for(var key in myString){
//     console.log(myString[key]);
// }

var myInfor = {
    name: 'Trong Vuong',
    age: 18,
    address: 'Nghe An, VN'
};
// for(var key in myInfor){
//     console.log(myInfor[key]);
// }

// FOR/OF LOOP: in ra giá trị

// for(var value of myArray){
//     console.log(value);
// }

// for(var value of myString){
//     console.log(value);
// }

// chuyển myInfor về dạng mảng mới in ra được
// for(var value of Object.values(myInfor)){ 
//     console.log(value);
// }

// Vòng lặp lồng nhau
var myArray2 = [
    [1, 2],
    [3, 4],
    [5, 6],
];

for(var i = 0; i < myArray2.length; ++i){
    for(var j = 0; j < myArray2[i].length; ++j){
        console.log(myArray2[i][j]);
    }
}