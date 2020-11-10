var year, month, date, day; // 함수 밖에 선언해야함! (전역 변수)

// 오늘의 날짜 정보 받기
function get_info(today_date){
    var week=new Array('일','월', '화', '수', '목', '금', '토');

    year=today_date.getFullYear();
    month=today_date.getMonth()+1;
    date=today_date.getDate();
    day=week[today_date.getDay()];
}

// 달력을 채워주는 함수
function calender(){
    var print_date=1; // 지금까지 출력한 날
    var max_date; // 각 달의 마지막 날을 나타내는 변수
    // 각 달의 마지막 날 알아내기
    switch(month){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            max_date=31;
            break;
        case 2:
            // 윤년
            if ((year % 4 ==0) && (year % 100 !=0) || (year % 400 ==0))
                max_date=29;
            else
                max_date=28;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            max_date=30;
            break;
    }

    // 달력 table 지우기 -> 다음 달, 이전 달 달력보기를 하면 지금 화면에 떠있는 달력은 지워줘야 함 (맨 마지막에 구현하면 됨)
    var tb=document.getElementById("tb");
    while(tb.rows.length > 2){
        tb.deleteRow(tb.rows.length-1);
    }

    // 달력 table에 날짜 추가하기
    var fday_month=new Date(year, month-1, 1); // 해당 달의 1일을 나타내는 변수
    var cnt=1;
    while(print_date<=max_date){
        var tb_row=tb.insertRow();
        for (var i=0; i<7 && print_date<=max_date; i++){
            // 행에 해당하는 열을 채우기 시작
            var tb_cell=tb_row.insertCell();
            // 첫 번째 주 채우기 -> 요일을 맞춰줘야함
            if (cnt==1 && i<fday_month.getDay()){ 
                tb_cell.innerHTML="";
            }
            else{
                tb_cell.innerHTML=print_date;
                print_date++;
            }
        }
        cnt++;
    }

}

// 이번 달 달력 보기
function this_month(){
    var today_date=new Date();
    get_info(today_date);

    var today=document.getElementById("today");
    today.innerText=year+'.'+month+'.'+date+'.'+day;

    calender();
}

// 지난 달 달력 보기
function last_month(){
    // Date 객체 생성 시 달은 0부터 시작
    // 8월을 나타내려면 7를 입력해야함
    // + get_info()에서 getMonth()한 값에 1을 더해줬으므로 1을 또 빼기
    var last=new Date(year, month-2);
    get_info(last);

    var today=document.getElementById("today");
    today.innerText=year+'.'+month;

    calender();
    
}

// 다음 달 달력 보기
function next_month(){
    var next=new Date(year, month);
    get_info(next);

    var today=document.getElementById("today");
    today.innerText=year+'.'+month;

    calender();
}