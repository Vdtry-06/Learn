// Chain

// var promise = new Promise(
//     // Executor
//     function(resolve, reject) {
//         // logic
//         resolve(); // successful
//         // reject(); // error
        
//     }
// );

// promise
//     .then(function() {
//         return new Promise((resolve, reject) => {
//             setTimeout(function() {

//             }, 3000);
//         });
//     })
//     .then(function(data) {
//         console.log(data);
//     })
//     .catch(function() {
//         console.log('Fulture!');
//     })
//     .finally(function() {
//         console.log('Done!');
//     })

function sleep(ms) {
    return new Promise(function(resolve) {
        setTimeout(resolve, ms);
    });
}

sleep(1000)
    .then(function() {
        console.log(1);
        return sleep(1000);
    })
    .then(function() {
        console.log(2);
        return new Promise((resolve, reject) => {
            reject();
        })
    })
    .then(function() {
        console.log(3);
        return sleep(1000);
    })
    .then(function() {
        console.log(4);
        return sleep(1000);
    })
    .catch(function() {
        console.log('Error!');
    })

    