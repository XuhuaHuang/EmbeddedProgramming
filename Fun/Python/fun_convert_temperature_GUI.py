# Topic: Convert Temperature with a Graphical User Interface
# with package Graphics
# Author: Xuhua Huang
#
# Last updated: Jun 7, 2021
# Created on: Jun 7, 2021

from graphics import *


def convert_temp(input):
    celsius = eval(input.getText())
    fahrenheit = 9.0 / 5.0 * celsius + 32
    return fahrenheit


def change_colour(win, input):
    color_num = eval(input.getText())
    colour_weight = color_num / 100
    new_window_colour = color_rgb(int(255 * colour_weight),
                                  int(66 + 150 * (1 - colour_weight)),
                                  int(255 * (1 - colour_weight)))
    win.setBackground(new_window_colour)


def main():
    win = GraphWin("Convert Celsius to Fahrenheit", 500, 400)
    win.setCoords(0.0, 0.0, 3.0, 4.0)
    # draw input elements
    Text(Point(1, 3),
         "Celsius Temperature:").draw(win)
    Text(Point(1.4, 2.7),
         "Please enter temperature reading in celsius").draw(win)
    Text(Point(1, 1),
         "Fahrenheit Temperature:").draw(win)
    input = Entry(Point(2, 3), 5)
    input.setText("0.0")
    input.draw(win)
    # determine output value and display
    output = Text(Point(2, 1), "")  # place holder for result
    output.draw(win)
    button = Text(Point(1.5, 2.0), "Click to Convert")
    button.draw(win)
    rect = Rectangle(Point(1, 1.5), Point(2, 2.5))
    rect.draw(win)
    # wait for mouse click
    win.getMouse()
    result = convert_temp(input)
    output.setText(result)
    # change window color
    change_colour(win, input)
    # change button content to quit
    button.setText("Quit")
    win.getMouse()
    win.close()


if __name__ == '__main__':
    main()
