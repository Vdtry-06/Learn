// const logger = (log) => {
//     console.log(log);
// }
// logger('Message...');

// const sum = (a, b) => ({ a: a, b: b}); // Object
// console.log(sum(2, 2));

// const logger = log => console.log(log);
// logger('Message...');

const course = {
    name: 'JavaScript Basic!',
    getName: function() {
        return this; // context
    }
};

console.log(course.getName());