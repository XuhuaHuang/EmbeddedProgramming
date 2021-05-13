# This file contains an example for plotting a sine wave in Python
# Topic: plot graph
#
# Author: Xuhua Huang
# Created: May 13, 2021
# Last updated: May 13, 2021

import matplotlib.pyplot as plt
import numpy as np

# Define Sine Wave Property Variable
Fs = 8000
f = 5
sample = 8000


def __main__():
    x = np.arange(sample)
    y = np.sin(2 * np.pi * f * x / Fs)
    plt.plot(x, y)
    plt.xlabel('sample(n)')
    plt.ylabel('voltage(V)')
    plt.show()


if __name__ == '__main__()':
    __main__()
