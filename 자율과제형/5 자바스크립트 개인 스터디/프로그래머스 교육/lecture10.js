console.log("Menu");
console.log("1. Ice Americano");
console.log("2. Cafe Latte");
console.log("3. Cappuccino");

var count = 0;

while(count<3){

    var choice = parseInt(prompt("메뉴를 선택해줘."));
    console.log(choice+"번 메뉴를 선택하셨습니다.");

    switch(choice){
        case 1:
            console.log("아이스 아메리카노 1500원 입니다.");
            break;
        case 2:
            console.log("카페라떼 2000원 입니다.");
            break;
        case 3:
            console.log("카푸치노 1500원 입니다.");
            break;
    }
    cnt++;
}

console.log("안녕히 가십시오.");