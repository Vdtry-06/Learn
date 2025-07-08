// Object: đối tượng

var SchoolKey = 'School';

var myInfor = {
    name: 'Vuong Duc Trong', // Property
    address: 'Nghe An, VN',
    age: 20,
    [SchoolKey]: 'PTIT', // thêm vào object
    getName: function() { // Method
        return this.name;
    }
};

// Function: --> Phương thức / Method
// Others:   --> Thuộc tính  / Property

// thêm key và value vào myInfor
myInfor['my-email'] = 'trongvuongduc24@gmail.com';
console.log(myInfor); // in ra đối tượng 

// lấy key ra
console.log(myInfor.address); // c1 in ra Nghe An, VN
console.log(myInfor['name']); // c2 Vuong Duc Trong

// // xóa key
delete myInfor.address;
console.log(myInfor); // in ra đối tượng

console.log(myInfor.getName()); // in ra Vuong Duc Trong
