"""blogproject URL Configuration

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/3.0/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
from django.contrib import admin
from django.urls import path
import blog.views

urlpatterns = [
    path('admin/', admin.site.urls),
    path('', blog.views.home, name='home'),
    path('blog/<int:blog_id>', blog.views.detail, name='detail'), #객체를 생성하면 장고에서 자동으로 고유의 아이디를 부여해주어 object를 id로써 구분할 수 있게 해주는데
                                                                    #그 아이디를 인수로서 뷰함수에 전달 (즉 그 아이디가 있는 본문으로 가도록 한다)
    path('blog/new', blog.views.new, name='new'),
    path('blog/create', blog.views.create, name='create'),
    #즉 submit을 누르면 이 유알엘로 가서 create함수를 실행한 뒤에 다시 blog/num 으로 가서 html보여준다
    path('blog/edit/<int:blog_id>', blog.views.edit, name='edit'),
    path('blog/update/<int:blog_id>', blog.views.update, name='update'),
    path('blog/delete/<int:blog_id>', blog.views.delete, name='delete'),
]
