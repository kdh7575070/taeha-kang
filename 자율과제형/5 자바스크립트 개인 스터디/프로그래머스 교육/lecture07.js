var empty_obj={};
typeof(empty_obj);
//객체란? 속성의 집합

var man = {name: "홍길동", age:20, height:180 }; //속성의 이름 - 값 (모든자료형 object포함 가능)

//접근방법
man.name;
man["name"];

man["age"] = 15;

console.log(man);