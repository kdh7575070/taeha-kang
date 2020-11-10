from django.shortcuts import render
from .models import Animal

# Create your views here.
def home(request):
    animals = Animal.objects
    return render(request, 'home.html', {'animals':animals})