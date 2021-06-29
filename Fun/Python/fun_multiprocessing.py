# Topic: Multiprocessing with module 'multiprocessing' and 'concurrent.futures'
#
# Author: Xuhua Huang
# Last updated: Jun 29, 2021
# Created on: Jun 29, 2021

import time
import multiprocessing
import concurrent.futures


""" Function that does not ask for arguments """
def fn_no_args(void):
    print('[fn_no_args(void)]Sleeping for 1 seconds...')
    time.sleep(1)
    print('Done sleeping.')


""" Function that asks for an integer as argument """
def fn_with_args(seconds: int):
    print(f'[fn_with_args(seconds: int)]Sleeping for {seconds} second(s)...')
    time.sleep(seconds)
    print('Done sleeping.')


def main():
    """ Record the start time of the program """
    start_time = time.perf_counter()

    """ Create a list of processes with throw-away variables """
    processes = []  # initializing an empty list
    for _ in range(10):
        process = multiprocessing.Process(target=fn_no_args(void=True))
        process.start()  # start the process
        processes.append(process)  # add process to existing list

    """ Wait for all processes to finish and join the main process """
    for process in processes:
        process.join()

    """ With 'concurrent.futures' module and context manager """
    with concurrent.futures.ProcessPoolExecutor() as executor:
        exec_1 = executor.submit(fn_no_args(void=True))  # allow function to be scheduled and run
        exec_2 = executor.submit(fn_with_args(2))  # call function that asks for an argument
        """
        if the function has a return type, use the .result() method to retrieve, e.g,
        print(fn_1.result())
        """

        """ Using list comprehension """
        results = [executor.submit(fn_with_args(2)) for _ in range(10)]

    """ Print the execution time of the program """
    finish_time = time.perf_counter()
    print(f'Program finished in {round(finish_time - start_time, 2)} second(s)')


if __name__ == '__main__':
    main()
