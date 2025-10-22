import turtle
import colorsys
import time

screen = turtle.Screen()
screen.bgcolor("black")
screen.colormode(1.0)

t = turtle.Turtle()
t.speed(0)
t.width(2)
t.hideturtle()
turtle.tracer(0, 0)

num_lines = 100
length = 200

while True:
    t.clear()
    for i in range(num_lines):
        hue = i / num_lines
        r, g, b = colorsys.hsv_to_rgb(hue, 1, 1)
        t.pencolor(r, g, b)

        t.penup()
        t.goto(0, 0)
        t.setheading(i * (360 / num_lines))
        t.pendown()
        t.forward(length)
        
        turtle.update()
        time.sleep(0.03)
