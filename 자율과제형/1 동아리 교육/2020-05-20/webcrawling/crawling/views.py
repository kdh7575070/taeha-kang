from django.shortcuts import render
from bs4 import BeautifulSoup
import requests

# Create your views here.
def home(request):
    return render(request, 'home.html')

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

