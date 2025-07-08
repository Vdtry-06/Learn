// CallBack ?

// là hàm (function) được truyền qua đối số
// khi gọi hàm khác

// 1. là hàm
// 2. được truyền qua đối số
// 3. được gọi lại (trong hàm nhân đối số)

// function myFunction(param) {
//     console.log(typeof param);
// }
// function myCallBack() {

// }

// myFunction(myCallBack);

// CallBack 2

Array.prototype.map2 = function (callBack) {
  var output = [],
    arrayLength = this.length;
  for (var i = 0; i < arrayLength; ++i) {
    var res = callBack(this[i], i);
    output.push(res);
  }
  return output;
};
var courses = ["JavaScript", "PHP", "Ruby"];
var htmls = courses.map2(function (course) {
  return `<h2>${course}</h2>`;
});
console.log(htmls.join("\n"));

// courses.map2(function(courses, index) {
//     console.log(index, courses);
// });
// var htmls = courses.map(function(course){
//     return `<h2>${course}</h2>`;
// });

// console.log(htmls.join('\n'));
