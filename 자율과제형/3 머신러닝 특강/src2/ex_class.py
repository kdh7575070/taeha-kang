class CC:
    name='cal'

    def add(self, first, second):
        return first+second

    def sub(self, first, second):
        return first-second

class CCC:
    name='cal'
    cal_type='digital'

    def __init__(self, first, second):
        self.first = first
        self.second = second

    def add(self):
        return self.first+self.second

    def sub(self):
        return self.first-self.second

c1=CC()
print('{} + {} = {}'.format(10, 20, c1.add(10, 20)))
print('{} - {} = {}'.format(10, 20, c1.sub(10, 20)))

c2=CCC(100, 300)
print('{} + {} = {}'.format(c2.first, c2.second, c2.add()))
print('{} - {} = {}'.format(c2.first, c2.second, c2.sub()))
print(c2.name, c2.cal_type)