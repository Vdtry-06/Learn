// 1. khởi tạo hàm toast có các tiêu đề, tin nhắn, kiểu, thời gian
function toast({
    title = '', 
    message = '', 
    type = 'info', 
    duration = 3000
}) {
    // 2. lấy toast từ html để xử lý
    const main = document.getElementById('toast');

    // nếu đã lấy
    if(main) {
        // 3. tạo 1 thẻ div mới
        const toast = document.createElement('div');

        // thời gian ẩn toast tự động
        const autoRemoveId = setTimeout(function() {
            main.removeChild(toast);
        }, duration + 1000);

        // ẩn toast sau khi click
        toast.onclick = function(e) {
            if(e.target.closest('.toast__close')) {
                main.removeChild(toast);
                clearTimeout(autoRemoveId);
            }
        }

        // các icons theo từng kiểu tương ứng
        const icons = {
            success: 'fa-solid fa-circle-check',
            info: 'fa-solid fa-circle-info',
            warning: 'fa-solid fa-circle-exclamation',
            error: 'fa-solid fa-circle-exclamation',
        };

        // lấy ra icon từ đối tượng icons
        const icon = icons[type];

        // thời gian trễ để di chuyển toast message lên phía trên
        const delay = (duration / 1000).toFixed(2);

        // thêm kiểu toast vào danh sách
        toast.classList.add('toast', `toast--${type}`);

        // thêm hiệu ứng cho toast: lướt từ phải vào, hiện vài s và ẩn nó
        toast.style.animation = `slideInLeft ease 0.3s, fadeOut linear 1s ${delay}s forwards`;
        
        // 4. thêm thẻ div vào html
        toast.innerHTML = `
            <div class="toast__icon">
                <i class="${icon}"></i>
                
            </div>
            <div class="toast__body">
                <h3 class="toast__title">${title}</h3>
                <p class="toast__msg">${message}</p>
            </div>
            <div class="toast__close">
                <i class="fa-solid fa-circle-xmark"></i>
            </div>
        `;

        // thêm toast vào main để hiển thị giao diện khi đã xử lý ở trên
        main.appendChild(toast);
    }
}

// hiển thị thành công
function showSuccessToast() {
    toast({
        title: 'Success!',
        message: 'You have successfully created an account on our website.',
        type: 'success',
        duration: 3000
    });
}

// hiển thị lỗi
function showErrorToast() {
    toast({
        title: 'Error!',
        message: 'An error has occurred, please try again.',
        type: 'error',
        duration: 3000
    });
}