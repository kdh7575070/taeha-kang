class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def show_point(self):
        print('Point ({}, {})'.format(self.x, self.y))