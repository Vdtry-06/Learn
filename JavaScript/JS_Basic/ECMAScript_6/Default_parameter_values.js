// function logger(log = 'Gia tri mac dinh!') {
//     console.log(log);
// }

// logger(undefined);

function logger(log, type = 'log') {
    console[type](log);
}

logger('Message...');