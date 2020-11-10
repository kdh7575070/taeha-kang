from django.db import models

# Create your models here.
class Blog(models.Model):
    title = models.CharField(max_length=200)
    # 문자필드의 틀

    pub_date = models.DateTimeField('data published')
    # 시간필드의 틀
    
    body = models.TextField()
    # 텍스트 필드의 틀

    def __str__(self):
        return self.title #자기이름을 admin사이트 제목으로 보여주는 함수

#python manage.py makemigrations
#python manage.py migrate
#위 둘은 건드릴때 마다 해주는게 좋다

#python manage.py createsuperuser
#kth 1234
