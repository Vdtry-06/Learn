// Callback ?
// là hàm (function) được truyền qua đối số
// khi gọi hàm khác

// 1. Là hàm
// 2. Được truyền qua đối số

function myFunction(param) {
    param('Hoc lap trinh');
}
function myCallback(value) {
    console.log('Value: ', value);
}
myFunction(myCallback);

// 3. Được gọi lại trong hàm là đối số
var course = [
    'JavaScript',
    'PHP',
    'Ruby',
];

course.map(function(course) {
    console.log(course);
});

