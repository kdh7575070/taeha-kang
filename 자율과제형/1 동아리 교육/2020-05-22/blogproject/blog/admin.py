from django.contrib import admin
from .models import Blog
# 우리가 만든 모델을 등록해준다
# admin 은 django의 모델에 대한 디버깅용 프로그램인 셈 - 데이터꼬임처리

# Register your models here.
admin.site.register(Blog)
