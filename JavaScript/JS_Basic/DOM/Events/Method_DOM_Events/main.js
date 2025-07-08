// DOM Events
// 1. preventDefault: loai bo hanh vi cua trinh duyet tren 1 the html
// 2. stopPropagation: su kien noi bot

// 1
var aElement = document.querySelectorAll('a');
var aElement = document.anchors;
var aElement = document.links;
// console.log(aElement);
for(var i = 0; i < aElement.length; ++i){
    aElement[i].onclick = function(e) {
        // console.log(e.target.href);
        if(!e.target.href.startsWith('https://f8.edu.vn')) {
            e.preventDefault(); // ngan chan hanh vi mac dinh cua trinh duyet
        }
    }
}

// var ulElement = document.querySelector('ul');
// ulElement.onmousedown = function(e) {
//     e.preventDefault();
// }
// ulElement.onclick = function(e) {
//     console.log(e.target);
// }

// 2
// document.querySelector('div').onclick = function() {
//     console.log('DIV');
//     document.querySelector('button').onclick = function(e) {
//         e.stopPropagation();
//         console.log('Click me!');
//     }
// }