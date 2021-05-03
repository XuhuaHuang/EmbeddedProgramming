from turtle import *

def tree(plist, l, a, f):
    """plist is a list of pens
    l is length of the branch
    a is a half of the angle between 2 branches
    f is factor by which branch is shortened
    """
    if l > 5:
        lst = []
        for p in plist:
            p .forward(1)
            q = p.clone()
            p.left(a)
            q.right(a)
            lst.append(p)
            lst.append(q)
        tree(lst, l*f, a, f)


def main():
    t = Turtle()
    t.color("green")
    t.pensize(15)
    t.hideturtle()
    # FINISHED INITIALIZING
    t.getscreen().tracer(30,0)
    t.left(90)
    t.penup()
    t.goto(60, 60)
    t.pendown()
    p = tree([t], 110, 65, 0.6375)


main()