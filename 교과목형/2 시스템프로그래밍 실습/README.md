# 실습 과제에 대한 간단한 소개
### 교재에 나오는 시스템 명령어 샘플을 직접 짜보고 교수님이 제시한 부분을 업그레이드 하는 것
1. 명령어 [more](https://github.com/kdh7575070/taeha-kang/tree/main/%EA%B5%90%EA%B3%BC%EB%AA%A9%ED%98%95/2%20%EC%8B%9C%EC%8A%A4%ED%85%9C%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D%20%EC%8B%A4%EC%8A%B5/ch01/more02.c)
2. 명령어 [who](https://github.com/kdh7575070/taeha-kang/tree/main/%EA%B5%90%EA%B3%BC%EB%AA%A9%ED%98%95/2%20%EC%8B%9C%EC%8A%A4%ED%85%9C%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D%20%EC%8B%A4%EC%8A%B5/ch02/who02.c)
3. 명령어 [ls](https://github.com/kdh7575070/taeha-kang/tree/main/%EA%B5%90%EA%B3%BC%EB%AA%A9%ED%98%95/2%20%EC%8B%9C%EC%8A%A4%ED%85%9C%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D%20%EC%8B%A4%EC%8A%B5/ch03/ls2.c), 함수 [fileinfo](https://github.com/kdh7575070/taeha-kang/tree/main/%EA%B5%90%EA%B3%BC%EB%AA%A9%ED%98%95/2%20%EC%8B%9C%EC%8A%A4%ED%85%9C%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D%20%EC%8B%A4%EC%8A%B5/ch03/fileinfo.c), [filesize](https://github.com/kdh7575070/taeha-kang/tree/main/%EA%B5%90%EA%B3%BC%EB%AA%A9%ED%98%95/2%20%EC%8B%9C%EC%8A%A4%ED%85%9C%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D%20%EC%8B%A4%EC%8A%B5/ch03/filesize.c)
4. 명령어 [pwd](https://github.com/kdh7575070/taeha-kang/tree/main/%EA%B5%90%EA%B3%BC%EB%AA%A9%ED%98%95/2%20%EC%8B%9C%EC%8A%A4%ED%85%9C%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D%20%EC%8B%A4%EC%8A%B5/ch04/spwd.c)
5. [stty에 관련된 함수들](https://github.com/kdh7575070/taeha-kang/tree/main/%EA%B5%90%EA%B3%BC%EB%AA%A9%ED%98%95/2%20%EC%8B%9C%EC%8A%A4%ED%85%9C%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D%20%EC%8B%A4%EC%8A%B5/ch05)
6. [ATM 응답 프로그램](https://github.com/kdh7575070/taeha-kang/tree/main/%EA%B5%90%EA%B3%BC%EB%AA%A9%ED%98%95/2%20%EC%8B%9C%EC%8A%A4%ED%85%9C%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D%20%EC%8B%A4%EC%8A%B5/ch06/play_again4.c) 만들기, 시그널처리
7. [간단한 게임 프로그램](https://github.com/kdh7575070/taeha-kang/tree/main/%EA%B5%90%EA%B3%BC%EB%AA%A9%ED%98%95/2%20%EC%8B%9C%EC%8A%A4%ED%85%9C%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D%20%EC%8B%A4%EC%8A%B5/ch07/bounce_aio.c.c) 만들기, 중복시그널처리

## 코드 뜯어보기 예시
### ch07 - [bounce01.c](https://github.com/kdh7575070/taeha-kang/tree/main/%EA%B5%90%EA%B3%BC%EB%AA%A9%ED%98%95/2%20%EC%8B%9C%EC%8A%A4%ED%85%9C%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D%20%EC%8B%A4%EC%8A%B5/ch07/bounce1d.c)
    while(1)			  /* the main loop */
    {
        ndelay = 0;
        c = getch();
        if (c == 'Q') break;
        if (c ==' ') dir = -dir;
        if (c =='f' && delay >2 ) ndelay = delay/2;
        if (c == 's') ndelay = delay *2;
        if (ndelay > 0)
            set_ticker(delay = ndelay);
    }    
	  endwin();
//while문 안에서 입력을 받아 입력에 따라 딜레이 속도가 조절된다. endwin은 을 종료하는 코드.


    void move_msg(int signum)
    {
        signal(SIGALRM, move_msg);
        move(row, col);
        addstr(BLANK);
        col += dir;
        move(row, col);
        addstr(MESSAGE);
        refresh();
        if (dir == -1 && col <= 0)
            dir = 1;
        else if (dir == 1 && col+strlen(MESSAGE)>= COLS)
            dir = -1;
    }
//hello 메세지를 움직이는 코드. 양쪽 벽에 부딪히면 튕겨서 반대방향으로 이동한다.\

<img width="800" alt="Screen Shot 2020-11-06 at 11 44 19 PM" src="https://user-images.githubusercontent.com/67677983/99944195-cad1a700-2db5-11eb-94c8-f322b9d38846.png"> \
수행결과 hello가 양옆으로 이동하면서 입력에 따라 속도가 증가/감소한다.
