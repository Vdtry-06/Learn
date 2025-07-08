
/*  Element: 
        1.ID : getElementById() : tra ve 1 doi tuong
        2.class : getElementsByClassName() : tra ve nhieu doi tuong giong Array: []
        3.tag : getElementsByTagName() : tra ve nhieu doi tuong giong Array: []
        4.CSS selector : querySelector() : tra ve 1 doi tuong
                         querySelectorAll() : tra ve nhieu doi tuong
        5.HTML collection : 
*/
// var headingNode = document.getElementById('heading');                    // tra ve doi tuong do
// var headingNodes = document.getElementsByClassName('heading');           // tra ve query collection giong mang
// var headingNodes = document.getElementsByTagName('h1');                  // tuong tu class name
// var headingNode = document.querySelector('.box .heading-2:nth-child(2)');// 2: 1.lay thang qua class truyen vao 
                                                                               // 2. lay toan bo doi tuong class truyen vao 
// var headingNodes = document.querySelectorAll('.box .heading-2');            // NodeList
// console.log(headingNodes[0]);

// console.log(document.forms['form-1']); // HTML collection

// document.write('Hello guys!'); // ghi vao trinh duyet web


// innerHTML: lay duoc Element, Attribute, Text node: o ben trong
// outerHTML: tuong tu, lay duoc element ben ngoai, thay doi duoc element ben ngoai

var boxElement = document.querySelector('.box');
boxElement.innerHTML = '<h1 title="heading">New Heading</h1>';
// console.log(document.querySelector('h1').innerText);
console.log(boxElement.innerHTML);
console.log(boxElement.outerHTML);