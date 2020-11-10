from src2.Point import Point

class DPoint(Point):
    def __init__(self,x,y,z):
        Point.__init__(self, x, y)
        self.z=z

    def show_point(self):
        print ( '3DPoint ({}, {}, {})'.format(self.x, self.y, self.z))