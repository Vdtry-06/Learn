// ClassList Property

// add : them class vao element
// contains : kiem tra class co nam trong element khong
// remove : xoa class trong element
// toggle : co thi bo khong co thi them


var boxElement = document.querySelector(".box");
console.log(boxElement.classList);
boxElement.classList.add('red', 'green', 'blue');
console.log(boxElement.classList.contains('red'));
boxElement.classList.remove('red');
boxElement.classList.toggle('red');