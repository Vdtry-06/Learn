// 1. DOM Event / Event listener
// 2. JSON
// 3. Fetch
// 4. DOM location
// 5. Local storage
// 6. Session storage
// 7. Coding convention
// 8. Best Practices
// 9. Mistakes
// 10. Perfromance

// event listener
// 1. Xử lý nhiều việc khi 1 event xảy ra
// 2. Lắng nghe / Hủy bỏ lắng nghe

var btn = document.getElementById('btn');
console.log(btn);

// DOM event
btn.onclick = function() {
    // Viec 1
    console.log('Viec 1');

    // Viec 2
    console.log('Viec 2');

    // Viec 3
    alert('Viec 3');
}
setTimeout(function() {
    btn.onclick = function() {}
}, 3000);


// dom event: lang nghe su kien khong muon huy bo

// Event listener
// var btn = document.getElementById('btn');
// btn.addEventListener('click', function(e) {
//     console.log('Event 1');
// });
// btn.addEventListener('click', function(e) {
//     console.log('Event 2');
// });
// btn.addEventListener('click', function(e) {
//     console.log('Event 3');
// })

// function viec1() {
//     console.log('Viec 1');
// }
// function viec2() {
//     console.log('Viec 2');
// }
// btn.addEventListener('click', viec1);
// btn.addEventListener('click', viec2);
// setTimeout(function() {
//     btn.removeEventListener('click', viec1)
// }, 3000);