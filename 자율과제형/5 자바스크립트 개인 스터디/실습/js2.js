var d = new Date();

var year=d.getFullYear(); // 2020
var month=d.getMonth()+1; // 9
var date=d.getDate(); // 14
var week=['일', '월', '화', '수', '목', '금', '토'];
var day=week[d.getDay()];

var last;
var r;

var mytable = document.getElementById('mytbody');  //행을 추가할 테이블

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

    r = parseInt( (firstDate.getDay()+last-1)/7 ); //추가할 행 수 - 몫구하려면 parseInt해야함

    mytable = document.getElementById('mytbody');  //행을 추가할 테이블

    var num = 1;

    //첫째줄
    var row = mytable.insertRow(-1); // 하단에 추가
    row.className="row100";

    for( var i = 0; i < firstDate.getDay() ; i++ ){
        var tb_cell = row.insertCell(i);

        // 수정
        tb_cell.className="column100";
        tb_cell.setAttribute("data-column","column"+2+i);
        tb_cell.innerHTML="";
        //tb_cell.innerHTML='<td class="column100 column'+2+i+'" data-column="column'+2+i+'"'+' id='+id+'"></td>';
        
        id++;
    }
    for(  ; i < 7 ; i++){
        var tb_cell = row.insertCell(i);

        // 수정
        tb_cell.className="column100";
        tb_cell.setAttribute("data-column","column"+2+i);
        tb_cell.value=id;
        tb_cell.onclick=function(){clic(this.value)};
        tb_cell.innerHTML=num;
        //tb_cell.innerHTML='<td class="column100 column'+2+i+'" data-column="column'+2+i+'"'+' id='+id+'>'+num+'</td>';
        
        num++; id++;
    }
    //나머지줄
    for (var j = 0; j < r ; j++){
        var row = mytable.insertRow(-1);
        row.className="row100";
        
        for( var i = 0; i < 7 ; i++){
            var tb_cell = row.insertCell(i);

            // 수정
            tb_cell.className="column100";
            tb_cell.setAttribute("data-column","column"+2+i);
            tb_cell.value=id;
            tb_cell.onclick=function(){clic(this.value)};
            tb_cell.innerHTML=num;
            //tb_cell.innerHTML='<td class="column100 column'+2+i+'" data-column="column'+2+i+'"'+' id='+id+' onclick="clic(this.id)">'+num+'</td>';
            
            num++; id++;
            if (num > last) break;
        };
    }
}

function reset(){

    for (var j = 0; j <= r ; j++){    
        mytable = document.getElementById('mytbody');
        mytable.deleteRow(-1);
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
        reset();
        today();
    }
    if(clicked_id=='left') {
        month--;
        if (month==0){
            year--;
            month=12;
        }
        var newDate = new Date(year, month-1, 1);
        var newDay = week[newDate.getDay()];
        day = week[(week.indexOf(newDay)+date-1)%7];
        reset();
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