// Object Prototype: nguyên mẫu tạo nên 1 đối tượng
// Nguyên liệu ngôi nhà

function User(firstName, lastName, avatar){
    this.firstName = firstName;
    this.lastName = lastName;
    this.avatar = avatar;
    this.getName = function() {
        return `${this.firstName} ${this.lastName}`;
    }
}
// thêm được 1 thuộc tính ở bên ngoài hàm User
User.prototype.className = 'CNTT';
// thêm phương thức vào hàm User
User.prototype.getClassName = function() {
    return this.className;
}

var user1 = new User('Trọng', 'Vương', 'Avatar1');
var user2 = new User('Linh Anh', 'Nguyễn', 'Avatar2');
console.log(user1.className);
console.log(user2.getClassName());

// Những đối tượng được tạo ra từ User sẽ có những cái thuộc tính phương thức 

var date = new Date();
var year = date.getFullYear();
var month = date.getMonth() + 1; // 0 - 11 --> 1 - 12
var day = date.getDate();
console.log(`${day}/${month}/${year}`); 