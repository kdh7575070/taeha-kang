from django.shortcuts import render

# Create your views here.
def home(request):
    return render(request, 'home.html')
    # 클라이언트한테 보내줌

def about(request):
    return render(request, 'about.html')

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
