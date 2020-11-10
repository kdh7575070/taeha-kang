var d = new Date(); //today는 onload로 먼저실행되니까 여기서 해줘도 되고 전역에서 해줘도 된다

var year=d.getFullYear(); // 2020
var month=d.getMonth()+1; // 9
var date=d.getDate(); // 14
var week=['일', '월', '화', '수', '목', '금', '토'];
var day=week[d.getDay()];

var r;
var last = 0;

function today(){

    var today = year+"."+month+"."+date+" "+day;
    var id = 1;

    document.getElementById("today").innerHTML= today;
    
    var firstDate = new Date(year, month-1, 1); //이달의 1일의 요일
    //var first = week[firstDate.getDay()]; //화
    var num = 1;
    
    mytable = document.getElementById('mytbody');  //행을 추가할 테이블

    //줄계산

    switch(month){
        // case 1,3,5,7,8,10,12: last += 31; break; 안됨... ㅡㅡ
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

    r = parseInt( (firstDate.getDay()+last-1)/7 ); //추가할 행 수 - 몫구하려면 parseInt해야함

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
    for (var j = 0; j < r ; j++){
        for( var i = 0 ; i < 7 ; i++){
            document.getElementById(id).innerHTML=num;
            id++; num++;
            if (num > last) break;
        }
    }
    
    //남는줄삭제
    if (firstDate.getDay()+last <= 35) mytable.deleteRow(-1);
    if (firstDate.getDay()+last == 28) mytable.deleteRow(-1);
    last = 0;
}

function inputs(clicked_id){

    var firstDate = new Date(year, month-1, 1);

    if(clicked_id=='right') {
        month++;
        if (month==13){
            year++;
            month=1; 
        }
        if (firstDate.getDay()+last <= 35) mytable.insertRow(-1);
        if (firstDate.getDay()+last == 28) mytable.insertRow(-1);
        today();
    }
    if(clicked_id=='left') {
        month--;
        if (month==0){
            year--;
            month=12; 
        }
        if (firstDate.getDay()+last <= 35) mytable.insertRow(-1);
        if (firstDate.getDay()+last == 28) mytable.insertRow(-1);
        today();
    }

    var doc=document.getElementById("today");
    doc.innerHTML=year+"."+month+"."+date+" "+day;
}

function clic(clicked_id){
    
    var firstDate = new Date(year, month-1, 1);
    date = parseInt(clicked_id) - firstDate.getDay();
    day=week[(parseInt(clicked_id) - firstDate.getDay() +1) % 7];

    today = year+"."+month+"."+date+" "+day;
    document.getElementById("today").innerHTML= today;
}