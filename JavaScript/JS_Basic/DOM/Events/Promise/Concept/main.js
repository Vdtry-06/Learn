// Promise: 
// 1. new Promise
// 2. Executor

// 3 trạng thái: 
    // 1. pending
    // 2. fulfilled
    // 3. rejected

// Memory leak
var promise = new Promise(
    // Executor
    function(resolve, reject) {
        // logic
        // resolve(); // successful
        // reject(); // error
        
        // Fake call API
        
        // resolve([
        //     {
        //         id: 1,
        //         name: 'JavaScript'
        //     }
        // ]);
        reject('Co loi!');
    }
);

promise
    // .then(function() {
    //     // successful status
    //     console.log('Successful!');
    // })
    .then(function(courses) {
        // successful status
        console.log(courses);
    })
    // .catch(function() {
    //     // error status
    //     console.log('Failure!');
    // })
    .catch(function(error) {
        // error status
        console.log(error);
    })
    .finally(function() {
        // done status
        console.log('Done');
    })
