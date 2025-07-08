
function hightlight([first, ...string], ...value) {
    console.log(first);
    console.log(string);
    console.log(value);
}
var brand = 'VDT';
var course = 'JavaScript';
const html = hightlight`Học lập trình ${course} tại ${brand}!`;
console.log(html);