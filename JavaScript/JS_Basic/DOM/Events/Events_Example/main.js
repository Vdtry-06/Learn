// DOM Events
// 1. Input / Select
// 2. Key up / Down

// var inputElement = document.querySelector('input[type="text"]');
// inputElement.oninput = function(e) {
//     console.log(e.target.value);
// };

// var inputElement = document.querySelector('input[type="checkbox"]');
// inputElement.onchange = function(e) { // thực thi khi 2 kí tự liên tiếp != 
//     console.log(e.target.checked);
// };

// var inputElement = document.querySelector('select');
// inputElement.onchange = function(e) {
//     console.log(e.target.value);
// };

// var inputElement = document.querySelector('input[type="text"]');
// inputElement.onkeyup = function(e) {
//     console.log(e.which);
//     switch(e.which) {
//         case 27:
//             console.log('Exit');
//             break;
//     }
// };

document.onkeydown = function(e) {
    // console.log(e.which);
    switch(e.which) {
        case 27:
            console.log('Exit');
            break;
        case 13:
            console.log('Send chat');
            break;
    }
};