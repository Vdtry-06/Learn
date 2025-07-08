// Global: toàn cục
var message = "Hoc ve scope";
function logger() {
    console.log(message);
}
logger()

// code block: {}
{
    const age = 20;
    // var: ko phải là code block nên khi khai báo var sẽ là biến global
}
console.log()

// Local Scope
function myFunction() {
    function logger2() {
        console.log("LOG 2");
    }
    logger2();
}
myFunction();