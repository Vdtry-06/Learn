/*
    đều in gán giá trị dữ liệu
    1. Var / Let, Const: Scope <phạm vi>, Hosting<>
    2. Const / Var, Let: Assignment <gán>
    
    Code Block: if, else, loop, {}, ....

    Code thuần: var
    Babel: const, let
    - Khi định nghĩa biến và không gán lại biến đó: const
    - Khi cần gán lại giá trị cho biến: let
*/
if(true) {
    let course = 'JavaScript Basic!';
    {
        {
            const course = 123;
            console.log(course);
        }
    }
}
