import {TYPE_LOG} from './constant.js';
function Modules_logger(log, type = TYPE_LOG) {
    console[type](log);
}
export default Modules_logger;