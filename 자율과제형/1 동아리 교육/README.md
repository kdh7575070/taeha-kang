# 동아리에서 교육을 받으며 작성한 코드들입니다.
## django를 사용하여 학습했습니다.
python version == 3.8.6 \
django version == 3.1.0 \
*7/13, 7/16 은 용량문제로 commit 과정에서 오류가 발생하여 알집하여 첨부했습니다.*

## 실행 manual
myvenv가 있는 directory에서 가상환경 실행 source myvenv/Scripts/activate \
managy.py가 있는 directory에서 python manage.py runserver

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

### [5/15](https://github.com/kdh7575070/taeha-kang/blob/main/%EC%9E%90%EC%9C%A8%EA%B3%BC%EC%A0%9C%ED%98%95/1%20%EB%8F%99%EC%95%84%EB%A6%AC%20%EA%B5%90%EC%9C%A1/2020-05-15/djangoproject/wordcount/views.py) 웹으로 워드를 입력받아 특정 단어가 몇개 사용되었는지 출력하는 워드카운터 만들어보기
#### 코드리뷰
    <a href="{%url 'home' %}">Home</a>
    <h1>입력한 텍스트</h1>
    {{full}}
    <h2>당신이 입력한 텍스트는 {{total}} 개로 구성되어 있습니다.</h2>
    
    <h3>단어 카운트: </h3>
    {% for word, num in dict %} <!-- 반복문 시작 -->
    {{word}} : {{num}}
    {% endfor %} <!-- 반복문 닫기 -->
    
    //html에서 python코드를 실행하기 위해 템플릿 변수를 받아와서 결과를 보내줌
[result.html](https://github.com/kdh7575070/taeha-kang/blob/main/%EC%9E%90%EC%9C%A8%EA%B3%BC%EC%A0%9C%ED%98%95/1%20%EB%8F%99%EC%95%84%EB%A6%AC%20%EA%B5%90%EC%9C%A1/2020-05-15/djangoproject/wordcount/template/result.html)

    def result(request):
    text = request.GET['fulltext']
    # fulltext 우리가 Home.html에서 받아올 텍스트를 의미. 그 텍스트를 변수로 담아서 아래 렌더에 넘겨준다
    words = text.split()
    #words = text.split(" ")와 동일
    #text 문자열에 대해 / 공백 기준으로 잘라서 / 리스트를 만든다
    word_dict = {}
    for word in words:
        if word in word_dict:
            word_dict[word]+=1
        else:
            word_dict[word]=1
    return render(request, 'result.html', {'full':text, 'total':len(words), 'dict':word_dict.items()})
    
    //특정 단어를 counting해서 그 결과를 html으로 보내주는 함수
[views.py](https://github.com/kdh7575070/taeha-kang/blob/main/%EC%9E%90%EC%9C%A8%EA%B3%BC%EC%A0%9C%ED%98%95/1%20%EB%8F%99%EC%95%84%EB%A6%AC%20%EA%B5%90%EC%9C%A1/2020-05-15/djangoproject/wordcount/views.py)

### [5/20](https://github.com/kdh7575070/taeha-kang/blob/main/%EC%9E%90%EC%9C%A8%EA%B3%BC%EC%A0%9C%ED%98%95/1%20%EB%8F%99%EC%95%84%EB%A6%AC%20%EA%B5%90%EC%9C%A1/2020-05-20/webcrawling/crawling/views.py) 네이버 뉴스에서 특정 키워드가 등장하는 기사를 웹크롤링하는 프로그램 만들어보기
#### 코드리뷰
    <h1>결과</h1>
    {% for title, url in data %}
    <h5>뉴스제목</h5>
    {{title}}
    <h5>뉴스url</h5>
    {{url}}
    {% endfor %}
    
    //html 특정 키워드가 포함된 뉴스결과를 url로 출력해줌
[result.html](https://github.com/kdh7575070/taeha-kang/blob/main/%EC%9E%90%EC%9C%A8%EA%B3%BC%EC%A0%9C%ED%98%95/1%20%EB%8F%99%EC%95%84%EB%A6%AC%20%EA%B5%90%EC%9C%A1/2020-05-20/webcrawling/crawling/template/result.html)

    def crawling(request):
    search_word=request.GET['news_keyword']
    url='https://search.naver.com/search.naver?where=news&sm=tab_jum&query={}'.format(search_word)
    req=requests.get(url)
    html=req.text # req받은 링크에서 html 속성을 가져온다
    soup = BeautifulSoup(html, 'html.parser')
    news_titles=soup.select(
        # '#sp_nws1 > dl > dt > a'\ css path
        'ul.type01 > li > dl > dt > a'
    )
    
    data = {} # key는 news title, value는 뉴스 링크
    for title in news_titles:
        data[title.text] = title.get('href')
 
    #text = request.GET['fulltext'] 데이터를 받아올거이므로 이 문장은 필요없다
    
    word_dict = {} #딕셔너리 만들기
    
    for title in data.keys(): #딕셔너리에 키만 가지고 오겠다 
        words = title.split()
        for word in words:
            if word in word_dict:
                word_dict[word]+=1
            else:
                word_dict[word]=1
    return render(request, 'result.html', {'data':data.items(), 'total':len(words), 'dict':word_dict.items()})
    
    //특정 키워드를 검색 질의로 넣어 출력된 결과들을 data화 해서 html으로 보내주는 함수  
[views.py](https://github.com/kdh7575070/taeha-kang/blob/main/%EC%9E%90%EC%9C%A8%EA%B3%BC%EC%A0%9C%ED%98%95/1%20%EB%8F%99%EC%95%84%EB%A6%AC%20%EA%B5%90%EC%9C%A1/2020-05-20/webcrawling/crawling/views.py)

### [5/22](https://github.com/kdh7575070/taeha-kang/blob/main/%EC%9E%90%EC%9C%A8%EA%B3%BC%EC%A0%9C%ED%98%95/1%20%EB%8F%99%EC%95%84%EB%A6%AC%20%EA%B5%90%EC%9C%A1/2020-05-22/blogproject/blog/views.py) crud 만들기 base.html 지정 - 게시물을 읽고 쓰고 수정 삭제하는 기능
#### 코드리뷰
    class Blog(models.Model):
    title = models.CharField(max_length=200) //제목
    pub_date = models.DateTimeField('data published') //날짜
    body = models.TextField() //내용

    def __str__(self):
        return self.title #자기이름을 admin사이트 제목으로 보여주는 함수
    
    //Blog class를 만들어 게시물 data를 database에 삽입할 양식을 지정하는 과정 - makemigrations, migrate 명령어로 sqlite db를 생성한다.
[models.py](https://github.com/kdh7575070/taeha-kang/blob/main/%EC%9E%90%EC%9C%A8%EA%B3%BC%EC%A0%9C%ED%98%95/1%20%EB%8F%99%EC%95%84%EB%A6%AC%20%EA%B5%90%EC%9C%A1/2020-05-22/blogproject/blog/models.py)

    # create하는 함수
    def create(request):
        blog = Blog() #새로 객체생성
        blog.title = request.GET['title']
        blog.pub_date = timezone.datetime.now() #장고에서 할 수 있는 기술 -> 글 쓰는 시간 자동으로 저장
        blog.body = request.GET['body']

        blog.save()

        #처음 만드는 페이지로 이동시키는 거라서 render말고 redirect라고 해줘야한다
        return redirect('/blog/'+str(blog.id)) #숫자를 문자열화해서 더해준다
        
    # Update하는 함수
    def edit(request, blog_id):
        blog=get_object_or_404(Blog, pk=blog_id) #특정 객체 가져오기 (없으면 404에러)
        
        return render(request, 'blog/edit.html', {'blog':blog})

    def update(request, blog_id):

        blog=get_object_or_404(Blog, pk=blog_id) #특정 객체 가져오기 (없으면 404에러)
        blog.title = request.GET['title']
        blog.pub_date = timezone.datetime.now()
        blog.body = request.GET['body']

        blog.save()
        return redirect('/blog/'+str(blog.id))

    # Delete 하는 함수
    def delete(request, blog_id):
        blog=get_object_or_404(Blog, pk=blog_id) #특정 객체 가져오기 (없으면 404에러)
        blog.delete()

        return redirect('home')
        
    //CRUD를 수행하는 함수들
[views.py](https://github.com/kdh7575070/taeha-kang/blob/main/%EC%9E%90%EC%9C%A8%EA%B3%BC%EC%A0%9C%ED%98%95/1%20%EB%8F%99%EC%95%84%EB%A6%AC%20%EA%B5%90%EC%9C%A1/2020-05-22/blogproject/blog/views.py)

### [7/9](https://github.com/kdh7575070/taeha-kang/blob/main/%EC%9E%90%EC%9C%A8%EA%B3%BC%EC%A0%9C%ED%98%95/1%20%EB%8F%99%EC%95%84%EB%A6%AC%20%EA%B5%90%EC%9C%A1/2020-07-09/static/staticproject/staticproject/settings.py) 미디어 파일들 static으로 변환
#### 코드리뷰
    # Static files (CSS, JavaScript, Images)
    # https://docs.djangoproject.com/en/3.0/howto/static-files/
    STATIC_URL = '/static/'
    MEDIA_URL = '/media/' #보여주기식

    STATICFILES_DIRS=[
        os.path.join(BASE_DIR, 'staticapp', 'static'),
    ] #가져올 위치
    
    STATIC_ROOT = os.path.join(BASE_DIR, 'static')
    MEDIA_ROOT = os.path.join(BASE_DIR, 'media')
    #모아줄 위치
    
    //Setting.py를 위와같이 수정 후 collectstatic 를 이용해서 static파일을 한꺼번에 모아 static 폴더를 생성한다 - 배포를 위한 작업임
    
### 7/13 CRUD복습, 앱을 두개로 나누고 url을 한 파일에 묶는 팁

### 7/16 권한부여, 좋아요 댓글 기능
