from django.shortcuts import render, get_object_or_404, redirect
from .models import Blog
from django.utils import timezone

# Create your views here.
def home(request):
    #blogs = Blog.objects #쿼리셋을 들고옴
    blogs = Blog.objects.all().order_by('-id') #최신순정렬
    return render(request, 'blog/home.html', {'blogs':blogs} ) #Blog의 모든 객체들을 쿼리셋 형식으로 템플릿에 넘겨준다
    #데이터의 양식인셈

def detail(request, blog_id): #아이디를 받아야지
    detail = get_object_or_404(Blog, pk=blog_id) #해당 id(프라이머리키)만 선별해서 가지고 온다!
    return render(request, 'blog/detail.html', {'detail':detail} ) #detail 객체들은 detail 퀴리셋으로 넘겨줘야한다

def new(request):
    return render(request, 'blog/new.html')
    
# create하는 함수
def create(request):
    blog = Blog() #새로 객체생성
    blog.title = request.GET['title']
    blog.pub_date = timezone.datetime.now() #장고에서 할 수 있는 기술 -> 글 쓰는 시간 자동으로 저장
    blog.body = request.GET['body']

    blog.save()

    #처음 만드는 페이지로 이동시키는 거라서 render말고 redirect라고 해줘야한다
    return redirect('/blog/'+str(blog.id)) #숫자를 문자열화해서 더해준다

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

def delete(request, blog_id):
    blog=get_object_or_404(Blog, pk=blog_id) #특정 객체 가져오기 (없으면 404에러)
    blog.delete()

    return redirect('home')