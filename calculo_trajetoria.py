from math import cos, sin, pi, sqrt
v0 = 5
count = 1
m = 1
g = 9.8
dt = 0
dx = 0
k = (1.0/2.0)*m*(v0**2)
while count <= 5:
    v0y = v0*sin(pi/4)
    v0x = v0*cos(pi/4)
    y = (v0y**2)/(2*g)
    T = sqrt((2*y)/g)
    t = T/201
    k = k - ((k/100)*20)
    v0 = sqrt(2*k/m)
    y = 0
    while y >= 0:
        x = dx + (dt*v0x)
        y = (v0y*dt)-((1.0/2.0)*g*(dt**2))
        if y >= -0.0000000001:
            print("%.19f\t%.19f" %(x, y))
        dt += t
    count += 1
    dt = 0
    dx = x
