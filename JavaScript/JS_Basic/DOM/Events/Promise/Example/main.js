/*
    bài toán backend:
        user: image, name, comment
    
        Hiểu:
            1. Array
            2. Function, callBack
            3. Promise
            4. DOM
*/
var Users = [
    {
        id: 1,
        name: 'Hong Le',
    },
    {
        id: 2,
        name: 'Duc Trong',
    },
    {
        id: 3,
        name: 'Anh Tuan',
    }
];

var Comments = [
    {
        id: 1,
        user_id: 1,
        content: 'Khi mo kiem tro may dua',
    },
    {
        id: 2,
        user_id: 3,
        content: 'Chac may bua nua roi tinh',
    },
    {
        id: 3,
        user_id: 2,
        content: 'Cuoi tuan di duoc',
    }
];

// 1. Lấy ra comments
// 2. Từ comments lấy ra user_id, từ user_id lấy ra user tương ứng

// Fake API

function getComments() {
    return new Promise((resolve) => {
        setTimeout(function() {
            resolve(Comments);
        }, 1000);
    })
}

function getUsersByIds(userIds) {
    return new Promise(function(resolve) {
        var result = Users.filter(function(Users) { // tìm kiếm trả về tất cả phần tử trong Users
            return userIds.includes(Users.id); // Tìm kiếm có trong xâu ko
        })
        setTimeout(function() {
            resolve(result);
        }, 1000);
    })
}

getComments()
    .then(function(comments) {
        var userIds = comments.map(function(comment) {
            return comment.user_id;
        });
        return getUsersByIds(userIds)
            .then(function(users){
                return {
                    users: users,
                    comments: Comments,
                }
            });
    })
    .then(function(data) {
        var commentBlock = document.getElementById('comment-block');
        var html = "";
        data.comments.forEach(function(comment) {
            var user = data.users.find(function(user){
                return user.id === comment.user_id;
            });
            html += "<li>" + user.name + ": " + comment.content + "</li>";
        });
        commentBlock.innerHTML = html;
    });

// getUsersByIds([1, 2])
//     .then(function(users){
//         console.log(users);
//     });