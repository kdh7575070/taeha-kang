var d = new Date();

var year=d.getFullYear(); // 2020
var month=d.getMonth()+1; // 9
var date=d.getDate(); // 14
// var monthday=[31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
// var monthday_y=[31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]; //헛짓
var week=['일', '월', '화', '수', '목', '금', '토'];
var day=week[d.getDay()];

var last;

function today(){

    var today = year+"."+month+"."+date+" "+day;

    document.getElementById("today").innerHTML= today;

    var firstDate = new Date(year, month-1, 1); //이달의 1일정보
    
    var id = 1;

    //줄계산
    last = 0;

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

function clic(clicked_id){
    var firstDate = new Date(year, month-1, 1);
    date = parseInt(clicked_id) - firstDate.getDay();

    if (last>=date && date>0){
    day=week[ (parseInt(clicked_id) - 1) % 7];
    
    var clicday = year+"."+month+"."+date+" "+day;
    document.getElementById("today").innerHTML= clicday;
    }
}