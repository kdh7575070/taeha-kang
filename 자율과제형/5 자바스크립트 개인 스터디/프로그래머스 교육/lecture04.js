var height=prompt("키를 입력해 주세요");
console.log(height, typeof(height)); //180입니다 라고 치면 정상동작 - 시작단어를 받아옴

var height_int = parseInt(height);
console.log(height_int, typeof(height_int));
//위에서 받은 문자열이 스트링으로 시작한다? 시작단어를 받아오기 때문에 정상동작X Nan으로 뜬다
//1/0; 이런 경우도 정상동작X Infinite로 뜬다

var height_float = parseFloat(height);
console.log(height_float, typeof(height_float));