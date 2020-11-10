var tmp=0; //현재창의값
var fixtmp=0; //저장된값
var fixchar='x'; //저장된연산자

function input(clicked_id){
	var rlt=document.getElementById("result");

	//처음에 숫자대신 문자 들어오면 에러방지
	if (!tmp){ 
		if(clicked_id == "+" || clicked_id == "-" || clicked_id == "*" || clicked_id == "/" || clicked_id == "=" ) {
			alert('연산자 입력 오류');
			return;
		}
	}

	//연산자발생 +-*/
	if(clicked_id == "+" || clicked_id == "-" || clicked_id == "*" || clicked_id == "/"){
	
		//첫 연산자가 아니면 연산도 같이한다
		if(fixchar!='x'){
			cal();
		}
		//첫 연산자일때는 띄운다
		else {
			rlt.innerHTML=clicked_id;
			fixtmp=parseInt(tmp);
		}
		tmp = 0;
		fixchar=clicked_id;

		if (fixtmp<0 && clicked_id == "/"){
			alert("음수는 나눌 수 없습니다!");
			reset();
			clearresult();
		}
	}

	else if(clicked_id == "="){
		if(fixtmp) cal();
		reset();
	}

	else{ //숫자입력

		//연산자 누른 뒤에 숫자 입력이면 화면리셋먼저
		if(!tmp) rlt.innerHTML="";
		
		rlt.innerHTML+=clicked_id; //결과출력
		tmp+=clicked_id; //tmp보여주기
	}

	//tmp확인
	if( ! ( (fixchar=='x') && ( (clicked_id == "=") || (clicked_id == "/") ) ) ){
		var v=document.getElementById("vari");
		v.innerHTML+=clicked_id;
	}
}

function cal(){
	var rlt=document.getElementById("result"); //SCOPE!!

	//맨첫연산자는연산안함
	switch(fixchar){
		case "+": fixtmp += parseInt(tmp); break;
		case "-": fixtmp -= parseInt(tmp); break;
		case "*": fixtmp *= parseInt(tmp); break;
		case "/": fixtmp /= parseInt(tmp);
	}
	rlt.innerHTML=fixtmp;
}

function clearresult(){
	var rlt=document.getElementById("result"); //SCOPE!!

	tmp = 0;
	rlt.innerHTML="";
}

function reset(){
	fixtmp = 0;
	tmp = 0;
	fixchar='x';

	//확인창 reset
	var v=document.getElementById("vari");
	v.innerHTML="put =";
}