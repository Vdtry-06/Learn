// Promise: xử lý thao tác bất đồng bộ
/*
    Sync / Async
    đồng bộ / bất đồng bộ

    Bất đồng bộ: 
    // setTimeout, setInterval, fetch,
    // XMLHttpRequest, file reading, 
    // request animation frame

    // Callback
*/

// sleep 
// setTimeout(function() {
//     console.log(1);
// }, 1000);
// console.log(2);

// Pyramid of doom
// Callback hell <pain>
setTimeout(function() {
    console.log(1); // viec 1
    setTimeout(function() {
        console.log(2); // viec 2
        setTimeout(function() {
            console.log(3); // viec 3
            setTimeout(function() {
                console.log(4); // viec 4
            }, 1000);
        }, 1000);
    }, 1000);
}, 1000);
