# 동아리에서 교육을 받으며 작성한 코드들입니다.
## django를 사용하여 학습했습니다.
*7/13, 7/16 은 용량문제로 commit 과정에서 오류가 발생하여 알집하여 첨부했습니다.*

### [5/8](https://github.com/kdh7575070/taeha-kang/blob/main/%EC%9E%90%EC%9C%A8%EA%B3%BC%EC%A0%9C%ED%98%95/1%20%EB%8F%99%EC%95%84%EB%A6%AC%20%EA%B5%90%EC%9C%A1/2020-05-08/main.html) 프론트엔드 - HTML, CSS 사용해서 인스타그램 카드 만들기
#### 코드리뷰
    $("#heart").click(function(){
                if($("#heart").hasClass("liked")){
                    $("#heart").html('<i class="far fa-heart"></i>');
                    $("#heart").removeClass("liked");
                }else{
                    $("#heart").html('<i class="fas fa-heart"></i>');
                    $("#heart").addClass("liked");
                }
            });
    //부트스트랩 아이콘을 활용하여 좋아요 반응 프론트 구현
    
    <button id="message">
        <i class="far fa-paper-plane"></i>
    </button>
    // 버튼에 아이콘 부여
<img src="https://user-images.githubusercontent.com/67677983/99956937-3887ce00-2dca-11eb-8a27-013ed332e48f.PNG" width="400">
이런 화면입니다.

### [5/15](https://github.com/kdh7575070/taeha-kang/blob/main/%EC%9E%90%EC%9C%A8%EA%B3%BC%EC%A0%9C%ED%98%95/1%20%EB%8F%99%EC%95%84%EB%A6%AC%20%EA%B5%90%EC%9C%A1/2020-05-15/djangoproject/wordcount/templates/result.html) 웹으로 워드카운터 만들어보기
#### 코드리뷰
    <h1>당신이 입력한 텍스트는 {{total}}<!-- 템플릿변수--> 개로 구성되어 있습니다.</h1>

    <a href="{%url 'home' %}">Home</a>
    <h1>입력한 텍스트</h1>
    {{full}}

    <h2>단어 카운트: </h2>
    {% for word, num in dict %} <!-- 반복문 시작 -->
    {{word}} : {{num}}
    <br>
    {% endfor %} <!-- 반복문 닫기 -->
    //html에서 python코드를 실행하기 위해 템플릿 변수를 받아와서 결과를 보내줌

### [5/20]() 웹크롤링 프로그램 만들어보기
#### 코드리뷰

### [5/22]() crud 만들기, base만드는 팁
#### 코드리뷰

### [7/9]() 미디어 파일들 static으로 변환
#### 코드리뷰

### 7/13 전체복습, 앱을 두개로 나누고, url한번에 묶는 팁
#### 코드리뷰

### 7/16 권한부여, 좋아요 댓글 기능
#### 코드리뷰
