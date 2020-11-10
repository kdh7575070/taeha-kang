from django.db import models

# Create your models here.
class Animal(models.Model):
    title = models.CharField(max_length=25, null=True)
    image = models.ImageField(upload_to='images/') #이미지,css,js중복방지 하위폴더로
    description = models.CharField(max_length=500, null=True)

    def __str__(self):
        return self.title

