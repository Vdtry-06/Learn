
function createCounter() {
    let counter = 0;
    function increase() {
        return ++counter;
    }
    return increase;
}

const counter1 = createCounter();
console.log(counter1());
console.log(counter1());
console.log(counter1());
const counter2 = createCounter();
console.log(counter2());
console.log(counter2());
console.log(counter2());

function createLogger(namespace) {
    function logger(message) {
        console.log(`[${namespace}] ${message}`)
    }
    return logger
}

const inforLogger = createLogger('Infor');
inforLogger('Bắt đầu gửi mail');
inforLogger('Gửi mail lỗi lần 1, thử lại...');
inforLogger('Gửi mail thành công cho user xxx');

function createStorage(key) {
    const store = JSON.parse(localStorage.getItem(key)) ?? {}
    const save = () => {
        localStorage.setItem(key, JSON.stringify(store))
    }
    const storage = {
        get(key) {
            return store[key]
        },
        set(key, value) {
            store[key] = value
            save()
        },
        remove(key) {
            delete store[key];
            save();
        }
    }
    return storage;
}

// Profile.js
const profileSetting2 = createStorage('profile_setting_2')
// console.log(profileSetting.remove('fullName'))
profileSetting2.set('fullName', 'Vuong Trong')
profileSetting2.set('age', 20)
profileSetting2.set('address', 'Nghe An')