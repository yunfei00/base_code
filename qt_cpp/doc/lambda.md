C++ 中的Lambda 表达式用于定义并创建匿名的函数对象，以简化变成工作。

基本构成：
[capture](parameters) mutable->return-type
{
	statement
}
[函数对象参数](操作符重载函数参数)mutable->返回值(函数体)

1. 函数对象参数：
[],标识一个lambda的开始。
[]:中括号为空，标识没有使用任何函数对象参数
[=]:表示函数体内可以使用Lambda所在作用域内所有可见的局部变量（包括Lambda所在类的this），并且是值传递方式
[&]:同=，但是这里是yin yong
2. 的


<!--stackedit_data:
eyJoaXN0b3J5IjpbLTE4NDY2Nzg5M119
-->