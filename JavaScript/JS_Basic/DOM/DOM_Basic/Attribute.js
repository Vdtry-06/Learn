/*
    Attribute: thuoc tinh
        class:
        id:
        title:
        href:
*/

var headingElement = document.querySelector('h1');
// them cac the thuoc tinh vao cac element
// headingElement.title = 'heading'; 
// headingElement.id = 'heading';
// headingElement.className = 'heading';
// headingElement.href = 'heading';

// headingElement.setAttribute('class', 'heading'); // them thuoc tinh
// console.log(headingElement.getAttribute('class')); // goi thuoc tinh de in ra text

/*
    cach 1 : truy xuat truc tiep qua thuoc tinh: phai hop le
    cach 2 : truy xuat phuong thuc ham: khong can phai hop le
*/

headingElement.title = 'Title test';
alert(headingElement.title);
// alert(headingElement.setAttribute());