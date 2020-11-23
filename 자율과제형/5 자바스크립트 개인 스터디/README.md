# 방학 중 스터디 그룹을 결성해 js를 함께 공부하여 각자 실습 결과를 낸 내용입니다.

# 1. 프로그래머스 js 강의
강의를 독학하며 정리한 중요 내용들입니다.

### 코드 리뷰

    function a(){
        let v_a = "a";

        function b(){
            let v_b = "b";
            console.log("b: ", typeof(v),typeof(v_a), typeof(v_b));
        }
    
    b();
    console.log("a: ", typeof(v),typeof(v_a), typeof(v_b));
    }

    let v="v";

    a();
    console.log("o: ", typeof(v),typeof(v_a), typeof(v_b));
    
    //중요 개념인 scope를 이해하기 위해 함수의 안팍으로 콘솔 메시지를 띄워 출력값을 확인합니다.
[lecture12.js](https://github.com/kdh7575070/taeha-kang/blob/main/%EC%9E%90%EC%9C%A8%EA%B3%BC%EC%A0%9C%ED%98%95/5%20%EC%9E%90%EB%B0%94%EC%8A%A4%ED%81%AC%EB%A6%BD%ED%8A%B8%20%EA%B0%9C%EC%9D%B8%20%EC%8A%A4%ED%84%B0%EB%94%94/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4%20%EA%B5%90%EC%9C%A1/lecture12.js)

# 2. 실습과제
스스로 실습한 내용입니다. 위 기초강의에서 배운 내용을 모두 활용하여 계산기와 달력을 만들었습니다. \
최종적으로 구글링한 css 코드를 제 계산기, 달력에 맞추어 입혀 반응형 코드릏 만드는 것으로 실습을 마무리했습니다.\
해당 html파일을 브라우저로 열면 실제로 동작하여 확인하실 수 있습니다. \
코드리뷰에서는 함수마다 마지막줄에 설명을 주석으로 달아두었습니다.

<img src="https://user-images.githubusercontent.com/67677983/99970808-b5717280-2ddf-11eb-806e-2a8b48549664.PNG" width="1000">

[calc_perfect.html](https://github.com/kdh7575070/taeha-kang/blob/main/%EC%9E%90%EC%9C%A8%EA%B3%BC%EC%A0%9C%ED%98%95/5%20%EC%9E%90%EB%B0%94%EC%8A%A4%ED%81%AC%EB%A6%BD%ED%8A%B8%20%EA%B0%9C%EC%9D%B8%20%EC%8A%A4%ED%84%B0%EB%94%94/%EC%8B%A4%EC%8A%B5/calc_perfect.html)

<img src="https://user-images.githubusercontent.com/67677983/99970812-b6a29f80-2ddf-11eb-9a27-01d5a202c6d9.PNG" width="1000">

[cal_v2.html](https://github.com/kdh7575070/taeha-kang/blob/main/%EC%9E%90%EC%9C%A8%EA%B3%BC%EC%A0%9C%ED%98%95/5%20%EC%9E%90%EB%B0%94%EC%8A%A4%ED%81%AC%EB%A6%BD%ED%8A%B8%20%EA%B0%9C%EC%9D%B8%20%EC%8A%A4%ED%84%B0%EB%94%94/%EC%8B%A4%EC%8A%B5/cal_v2.html)

## 상세 실습내용 정리
### 실습 1: 계산기 프로그램 만들기
### 목표 : 더하기, 빼기, 곱하기, 나누기가 가능한 계산기 만들기
### 진행 순서
#### 1️⃣ HTML로 위의 사진과 같은 table 만들기 - colspan, rowspan이라는 property(속성)를 활용
#### 2️⃣ 계산기를 동작하도록 하는 JavaScript 코드 작성하기 - 숫자와 연산자를 누를 때마다 입력을 받는 함수, 계산을 수행하는 함수 등이 필요
#### 3️⃣ HTML 코드에 event 추가하기 - onclick 이벤트를 활용

### 코드리뷰 
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
    //계산기 숫자 버튼 클릭시 실행되는 함수
	
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
    //계산기 +-*/ 버튼 클릭시 실행되는 함수

    function clearresult(){
        var rlt=document.getElementById("result"); //SCOPE!!

        tmp = 0;
        rlt.innerHTML="";
    }
    //clear버튼 클릭시 실행되는 함수
    
    function reset(){
        fixtmp = 0;
        tmp = 0;
        fixchar='x';

        //확인창 reset
        var v=document.getElementById("vari");
        v.innerHTML="put =";
    }
    //계산기 =버튼 클릭시 실행창 및 리셋시키는 함수
[js.js](https://github.com/kdh7575070/taeha-kang/blob/main/%EC%9E%90%EC%9C%A8%EA%B3%BC%EC%A0%9C%ED%98%95/5%20%EC%9E%90%EB%B0%94%EC%8A%A4%ED%81%AC%EB%A6%BD%ED%8A%B8%20%EA%B0%9C%EC%9D%B8%20%EC%8A%A4%ED%84%B0%EB%94%94/%EC%8B%A4%EC%8A%B5/js.js)

### 실습 2: 달력 프로그램 만들기
### 목표 : 이번 달, 지난 달, 다음 달.. 등등의 날짜 정보를 보여줄 수 있는 달력 만들기
### 진행 순서
#### 1️⃣ HTML로 위의 사진과 같은 달력 table 만들기 - Entity의 escape를 활용해보기 (ex. &nbsp)
#### 2️⃣ JavaScript로 오늘의 년, 월, 일, 요일 데이터를 알아내기 - Date 객체를 사용하여 오늘 날짜에 대한 세부정보(년, 월, 일, 요일) 
#### 3️⃣ 이번 달 정보 알아내기 - 달력을 채우기 위해서는 각 달의 1일이 무슨 요일인지(달력의 시작 지점), 마지막 날(달력의 마지막 지점)이 며칠인지 new Date(년, 월, 1)을 활용하여 파악하기
#### *주의 ! 2월의 마지막 날은 특히 윤년 (4로 나누어 떨어지는 년도 / 4로 나누어 떨어지면서 100으로 나누어 떨어지지 않는 년도 / 400으로 나누어 떨어지는 년도)*
#### 4️⃣ 이번 달 달력 채우기 - 3번의 정보를 바탕으로 달력의 시작 지점을 주의해서 달력 채우기 - insertRow(), insertCell() 함수 활용
#### 5️⃣ HTML 코드에 event 추가하기 - onload 이벤트 활용
#### 6️⃣ 지난 달, 다음 달 달력 채우기 - new Date(년, 지난 달), new Date(년, 다음 달)을 통해 생성된 객체와 4번의 함수를 재활용하면 지난 달과 이번 달 달력도 쉽게 채울 수 있음
#### 7️⃣ HTML 코드에 <, > 버튼을 눌렀을 때 지난 달, 다음 달 달력으로 넘어가는 event 추가하기 - onclick 이벤트 활용
#### 8️⃣ 지난 달, 다음 달 달력을 볼 때 달력이 누적되지 않고 덮어쓰기 update가 되도록 수정하기- deleteRow() 함수와 rows.length(객체.rows.length로 사용) 속성 활용

### 코드리뷰 
    function today(){
    
        var today = year+"."+month+"."+date+" "+day;

        document.getElementById("today").innerHTML= today;

        var firstDate = new Date(year, month-1, 1); //이달의 1일정보

        var id = 1;

        //줄계산
        last = 0;

        switch(month){
            // case 1,3,5,7,8,10,12: last += 31; break;
            case 1: last += 31; break;
            case 2: {if( ( (year%4)==0 && (year%100)!=0 ) || (year%400)==0 ) last += 29; else last += 28;} break;
            //4로 나누어 떨어지면서 100으로 나누어 떨어지지 않는 년도 or 400으로 나누어 떨어지는 년도
            case 3: last += 31; break;
            case 4: last += 30; break;
            case 5: last += 31; break;
            case 6: last += 30; break;
            case 7: last += 31; break;
            case 8: last += 31; break;
            case 9: last += 30; break;
            case 10: last += 31; break;
            case 11: last += 30; break;
            case 12: last += 31;
        }

        mytable = document.getElementById('mytbody');  //행을 추가할 테이블

        var num = 1;

        //첫째줄
        for( var i=0; i < firstDate.getDay() ; i++ ){
            document.getElementById(id).innerHTML="";
            id++;
        }
        for(  ; i < 7 ; i++){
            document.getElementById(id).innerHTML=num;
            id++; num++;
        }

        //나머지줄
        for (var j = 0; j < 6 ; j++){
            for( var i = 0 ; i < 7 ; i++){
                if (num <= last) document.getElementById(id).innerHTML=num;
                id++; num++;
                if (num > last) document.getElementById(id).innerHTML="";
            }
        }
    }
    //오늘 기준 최초 달력을 생성하는 함수

    function inputs(clicked_id){

        if(clicked_id=='right') {
            month++;
            if (month==13){
                year++;
                month=1;
            }
            day = week[(week.indexOf(day)+last)%7];
            today();
        }
        if(clicked_id=='left') {
            month--;
            if (month==0){
                year--;
                month=12;
            }
            // if ( ( (year%4)==0 && (year%100)!=0 ) || (year%400)==0 ){
            //     day = week[( monthday_y[month-1] - week.indexOf(day) -1 ) % 7];
            // }
            // else day = week[(monthday[month-1] - week.indexOf(day) -1 ) % 7]; //헛짓
            var newDate = new Date(year, month-1, 1);
            var newDay = week[newDate.getDay()];
            day = week[(week.indexOf(newDay)+date-1)%7];
            today();
        }

        var doc=document.getElementById("today");
        doc.innerHTML=year+"."+month+"."+date+" "+day;
    }
    //이전월, 다음월로 이동하는 

    function clic(clicked_id){
        var firstDate = new Date(year, month-1, 1);
        date = parseInt(clicked_id) - firstDate.getDay();

        if (last>=date && date>0){
        day=week[ (parseInt(clicked_id) - 1) % 7];

        var clicday = year+"."+month+"."+date+" "+day;
        document.getElementById("today").innerHTML= clicday;
        }
    }
    //클릭한 일자의 날짜, 요일 정보를 주는 함수 
[js3.js](https://github.com/kdh7575070/taeha-kang/blob/main/%EC%9E%90%EC%9C%A8%EA%B3%BC%EC%A0%9C%ED%98%95/5%20%EC%9E%90%EB%B0%94%EC%8A%A4%ED%81%AC%EB%A6%BD%ED%8A%B8%20%EA%B0%9C%EC%9D%B8%20%EC%8A%A4%ED%84%B0%EB%94%94/%EC%8B%A4%EC%8A%B5/js3.js)
