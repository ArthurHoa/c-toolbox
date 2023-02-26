from matplotlib import pyplot as plt
from numpy import genfromtxt
import numpy as np
import time

def __main__():
    
    # List of matrix sizes
    sizes = []

    # List of pent time
    times = []

    # Numpy times
    numpy_times = []

    for i in range(71):
        size = 10 + i * 2
        sizes.append(size)

        matrix1 = np.ones((size, size))
        matrix2 = np.ones((size, size)) * 2
        matrixRes = np.zeros((size, size))
        
        # Measure spent time
        start = time.time()
        matrixMult(matrix1, matrix2, matrixRes, size)
        time_spent = time.time() - start

        # Append to time list
        times.append(time_spent)

        # Measure spent time
        start = time.time()
        matrixRes = np.matmul(matrix1, matrix2)
        time_spent = time.time() - start

        # Append to numpy time list
        numpy_times.append(time_spent)

    c_times = np.genfromtxt('c_times.csv', delimiter=',')[:]
    c_times[:,1] = c_times[:,1] / 1000000.0
    sizes = np.array(sizes)

    plt.title("Time spent by matrix size")
    plt.plot(c_times[:,0], c_times[:,1], label = 'C')
    plt.plot(sizes, times, label = 'Python')
    plt.plot(sizes, numpy_times, label = 'Python Numpy')
    plt.ylabel("Time (in s)")
    plt.xlabel("Size of matrices NxN")
    plt.legend()
    plt.show()

    plt.title("Time spent by matrix size")
    plt.plot(c_times[:,0], c_times[:,1], label = 'C')
    plt.plot(sizes, numpy_times, label = 'Python Numpy')
    plt.ylabel("Time (in s)")
    plt.xlabel("Size of matrices NxN")
    plt.legend()
    plt.show()

# Multiply m1 with m2 into res
def matrixMult(m1, m2, res, size):
    for i in range(size):
        for j in range(size):
            for k in range(size):
                res[i, j] += m1[i, k] * m2[k, j]
            

__main__()