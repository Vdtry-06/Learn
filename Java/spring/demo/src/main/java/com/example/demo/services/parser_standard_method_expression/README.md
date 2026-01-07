### ExpressionParser

```commandline
Mục đích:
- Chuyển 1 string thành Expression Object
- Sau đó có thể evaluate (tính toán) dựa trên context
```

|Thành phần|	Mô tả|
|-|-|
|ExpressionParser|	Interface để parse biểu thức từ String|
|SpelExpressionParser|	Implementation phổ biến nhất|
|Expression|	Kết quả parse, có thể evaluate|
|EvaluationContext|	Nơi chứa biến, object để evaluate|