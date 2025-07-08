var course = [
    {
        id: 1,
        name: 'JavaScript',
        coin: 250
    },
    {
        id: 2,
        name: 'HTML, CSS',
        coin: 90
    },
    {
        id: 3,
        name: 'Ruby',
        coin: 0
    },
    {
        id: 4,
        name: 'PHP',
        coin: 230
    },
    {
        id: 5,
        name: 'ReactJS',
        coin: 10
    },
    {
        id: 6,
        name: 'Ruby',
        coin: 10
    },
    {
        id: 7,
        name: 'Ruby',
        coin: 12
    }
];

/*
    Array Method:
        forEach(): in ra danh sách Array
        every(): & tất cả đk thỏa mãn in ra true
        some(): || chỉ cần 1 đk thỏa mãn in ra true 
        find(): tìm kiếm trả về 1ptu or undefined khi 0 có
        filter(): tìm kiếm trả về tất cả phần tử or [] khi 0 có
        map(): thêm được các thuộc tính <key, value>
        reduce(): tính tổng
*/

course.forEach(function(course, index) {
    console.log(course, index);
});

var isFree = course.every(function(course, index) {
    return course.coin === 0;
});

console.log(isFree);

var isFree2 = course.some(function(course, index) {
    return course.coin === 0;
});

console.log(isFree2);

var listcourse = course.filter(function(course, index) {
    return course.name === 'Ruby';
});

console.log(listcourse);

var newCourse = course.map(function(course, index) {
    return {
        id: course.id,
        name: `Khoa Hoc ${course.name}`,
        coin: `Gia ${course.coin}`,
        index: index,
        originArray: course,
    }
});

console.log(newCourse);

// 1. dễ hiểu
// 2. ngắn gọn
// 3. hiệu năng

// function coinHandler(accumulator, currentValue, currentIndex, originArray) {
//     return accumulator + currentValue.coin;
// }

// var totalCoin = course.reduce(function (accumulator, currentValue) {
//     return accumulator + currentValue.coin;
// }, 0); // initial value 

var totalCoin = course.reduce((s, a) => s + a.coin, 0); // initial value 

console.log(totalCoin);

// b1: Làm phẳng mảng từ depth array
var depthArray = [1, 2, [3, 4], 5, 6, [7, 8, 9]];
var flatArray = depthArray.reduce(function(flatOutput, depthItem) {
    return flatOutput.concat(depthItem);
}, []);

console.log(flatArray);