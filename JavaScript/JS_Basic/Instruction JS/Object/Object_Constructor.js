// Object constructor: xây dựng đối tượng
// Gồm có: String, Number, Array, Date,...

// Mô tả thiết kế
function User(firstName, lastName, avatar){
    // mô tả thuộc tính, phương thức khi tạo 
    // từ đối tượng từ Object constructor User
    this.firstName = firstName;
    this.lastName = lastName;
    this.avatar = avatar;

    // Phương thức
    this.getName = function() {
        return `${this.firstName} ${this.lastName}`;
    }
}

// Khởi tạo đối tượng người dùng
let author = new User('Trọng', 'Vương', 'Avatar');
let user = new User('Linh Anh', 'Nguyễn', 'Avatar');

// Xem lại bản thiết kế có trùng với Object không
// console.log(author.constructor === User); // in ra true
// console.log(user); // in ra doi tuong

// thêm thuộc tính title = 'Boss'
// author.title = 'Boss'; 
// user.comment = 'Hello Anh';
console.log(author.getName());
console.log(user.getName());