import turtle
import time
import colorsys

screen = turtle.Screen()
screen.bgcolor("black")
screen.setup(width=800, height=800)
screen.title("Pookalam Pattern")

t = turtle.Turtle()
t.speed(0)
t.width(2)
t.hideturtle()
turtle.colormode(255)
screen.tracer(0, 0)  # Turn off auto screen updates for smooth animation

def draw_petal(radius, angle, color):
    t.fillcolor(color)
    t.begin_fill()
    t.circle(radius, angle)
    t.left(180 - angle)
    t.circle(radius, angle)
    t.left(180 - (360 - 2 * angle))
    t.end_fill()

def draw_pookalam_layer(num_petals, radius, petal_radius, hue_start):
    angle = 360 / num_petals
    for i in range(num_petals):
        # Calculate color using HSV for smooth gradient
        hue = (hue_start + i / num_petals) % 1.0
        r, g, b = colorsys.hsv_to_rgb(hue, 1, 1)
        color = (int(r*255), int(g*255), int(b*255))

        t.penup()
        t.goto(0, 0)
        t.setheading(angle * i)
        t.forward(radius)
        t.pendown()

        draw_petal(petal_radius, 60, color)

        # Update screen every few petals for animation
        if i % 4 == 0:
            screen.update()
            time.sleep(0.05)

# Clear screen and start drawing layers
t.clear()

layers = [
    (8, 100, 60, 0.0),
    (12, 160, 45, 0.2),
    (16, 210, 30, 0.4),
    (20, 260, 20, 0.6),
    (24, 300, 15, 0.8)
]

for petals, radius, petal_radius, hue_start in layers:
    draw_pookalam_layer(petals, radius, petal_radius, hue_start)

screen.update()
turtle.done()