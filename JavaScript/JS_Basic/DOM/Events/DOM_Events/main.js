// DOM events: nguoi dung co nhung hanh vi tac dung len website: events co the lang nghe
// 1. Attribute events: viet thang cac the attribute vao html
// 2. Assign event using the element node: gan cac su kien qua Element node

// var h1Element = document.querySelector('h1');
// console.log(h1Element);

// h1Element.onclick = function(e) {
//     console.log(e.target);
// };

var h1Elements = document.querySelectorAll('h1');
for(var i = 0; i < h1Elements.length; ++i) {
    h1Elements[i].onclick = function(e) {
        console.log(e.target);
    }
}
