// Constructor function: Đối tượng Validator
function Validator(options) {

    function getParent(element, selector) {
        while(element.parentElement) {
            if(element.parentElement.matches(selector)) {
                return element.parentElement;
            }
            element = element.parentElement;
        }
    }

    let selectorRules = {};
    // hàm thực hiện validate
    function validate(inputElement, rule) {
        // let errorElement = getParent(inputElement, '.form-group');
        let errorElement = getParent(inputElement, options.formGroupSelector).querySelector(options.errorSelector);
        let errorMessage;

        // lấy ra các rules của selector
        let rules = selectorRules[rule.selector];
        
        // console.log(rules);

        // lặp qua từng rule & kiểm tra 
        // nếu có lỗi thì dừng việc kiểm tra
        for(let i = 0; i < rules.length; ++i) {
            errorMessage = rules[i](inputElement.value);
            if(errorMessage) break;
        }
        
        if(errorMessage) {
            errorElement.innerText = errorMessage;
            getParent(inputElement, options.formGroupSelector).classList.add('invalid');
        }
        else {
            errorElement.innerText = '';
            getParent(inputElement, options.formGroupSelector).classList.remove('invalid');
        }
        return !errorMessage; // true: là có lỗi, false là ko có lỗi
    }

    function validateEmail(inputElement) {
        let errorElement = getParent(inputElement, options.formGroupSelector).querySelector(options.errorSelector);
        errorElement.innerText = '';
        inputElement.parentElement.classList.remove('invalid');
    }



    // lấy element của form cần validate
    let formElement = document.querySelector(options.form);
    // console.log(options.rules);
    if(formElement) {
        // khi submit form
        formElement.onsubmit = function(e) {
            // bỏ qua hành động mặc định của form
            e.preventDefault();

            let isFormValid = true;
            // lặp qua từng rules và validate
            options.rules.forEach(function(rule) {
                let inputElement = formElement.querySelector(rule.selector);
                let isValid = validate(inputElement, rule);
                if(!isValid) {
                    isFormValid = false;
                }
            });


            
            if(isFormValid) {
                // console.log('Không có lỗi');
                // trường hợp submit với javascript
                if(typeof options.onSubmit === 'function') {
                    // disabled không tương tác được [name]:not([disabled])
                    let enableInputs = formElement.querySelectorAll('[name]');
                    console.log(enableInputs.value);

                    let formValues = Array.from(enableInputs).reduce(function(values, input) {
                        // in ra values với điều kiện bên dưới
                        values[input.name] = input.value
                        return values;
                    }, {});
                    // console.log(formValues);
                    options.onSubmit(formValues);
                } 
                else { // trường hợp submit với hành vi mặc định
                    formElement.submit();
                }
            }
        }
        // lặp qua mỗi rule và xử lý (lắng nghe sự kiện blur, input, ...)
        options.rules.forEach(function(rule) {
            // lưu lại các rules cho mỗi input
            // selectorRules[rule.selector] = rule.test;
            if(Array.isArray(selectorRules[rule.selector])) {
                selectorRules[rule.selector].push(rule.test);
            } else {
                selectorRules[rule.selector] = [rule.test];
            }

            let inputElement = formElement.querySelector(rule.selector);

            if(inputElement) {
                // Xử lý trường hợp blur khỏi input
                inputElement.onblur = function() {
                    validate(inputElement, rule);

                    // console.log('blur' + rule.selector);
                    // console.log(inputElement.parentElement.querySelector('.form-message'));
                    // value: inputElement.value
                    // test func: rule.test
                }
                // Xử lý mỗi khi người dùng nhập vào input
                inputElement.oninput = function() {
                    // console.log(inputElement.value);
                    validateEmail(inputElement);
                }
            }
            // console.log(inputElement);
            // console.log(rule.selector);
        });
        // console.log(selectorRules);
        // console.log(formElement);
    }
    
}



// ---------- Định nghĩa các rules ----------- //
// Nguyên tắc của các rules:
// 1. Khi có lỗi => trả ra message lỗi
// 2. Khi hợp lệ => không trả ra gì cả (undefined)
Validator.isRequired = function(selector, message) {
    return {
        selector: selector,
        test: function(value) {
            return value.trim() ? undefined : message || 'Vui lòng nhập trường này'; 
        }
    };
}

Validator.isEmail = function(selector, message) {
    return {
        selector: selector,
        test: function(value) {
            let regex = /^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/;
            return regex.test(value) ? undefined : message || 'Trường này phải là email';
        }
    };
}

Validator.minlength = function(selector, min, message) {
    return {
        selector: selector,
        test: function(value) {
            return value.length >= min ? undefined : message || `Mật khẩu tối thiểu ${min} kí tự`;
        }
    };
}

Validator.isConfirmed = function(selector, getConfirmValue, message) {
    return  {
        selector: selector,
        test: function(value) {
            return value === getConfirmValue() ? undefined : message || 'Giá trị nhập vào không chính xác';
        }
    }
}