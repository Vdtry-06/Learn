// Ternary_Operator: toán tử ba ngôi

let course = {
    name: 'JavaScript',
    coin: 250
}

// if(course.coin > 0) {
//     console.log(`${course.coin} Coins`);
// }
// else {
//     console.log('Miễn phí');
// }

let res = course.coin > 0 ? `${course.coin} Coins` : 'Miễn phí';
console.log(res);