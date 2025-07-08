const obj = {
    name: 'Alice',
    cat: {
      name: 'Dinah',
      cat2: {
        name: 'Dinah 2',
        cat3: {
            name: 'Dinah 3',
          },
      },
    },
};
// Nghi ngờ ko tồn tại thi thêm ?
if(obj?.cat?.cat2?.cat3) console.log(obj.cat.cat2.cat3.name);

/*
    obj.val?.prop
    obj.val?.[expr]
    obj.func?.(args)
*/


const Obj = {
    getName(value) {
        console.log(value);
    }
}

Obj.getName?.(123);