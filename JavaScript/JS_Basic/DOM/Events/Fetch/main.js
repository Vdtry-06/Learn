// 1. Front-End: xây dựng giao diện người dùng
// 2. Back-End: xây dựng logic xử lý : Database

// API (URL): Application programing interface

// Cổng giao tiếp giữa các phần mềm

// Backend (OK) => API (URL) => Fetch => JSON / XML
// => JSON.prase => JavaScript types
// => Render ra giao diện với HTML


var postApi = 'https://jsonplaceholder.typicode.com/posts';
// Stream
fetch(postApi)
    .then(function(response) {
        return response.json();
        // JSON.parse: JSON -> JavaScript types
    })
    .then(function(posts) {
        var htmls = posts.map(function(post) {
            return `<li>
                <h2>${post.title}</h2>
                <p>${post.body}</p>
            </li>`;
        });
        var html = htmls.join('');
        document.getElementById('post-block').innerHTML = html;
    })
    .catch(function(err) {
        console.log('Error!');
    });