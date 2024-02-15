#!/usr/bin/python3

""" A script that reads stdin and formats data """

import signal
import sys

# Variables initialisations
line_count = 0
file_size = 0
dict_status_code = {200:  0, 301: 0, 400: 0,
                    401: 0, 403: 0, 404: 0, 405: 0, 500: 0}


def signal_handler(sig, frame):
    """ Interception handler """
    print_stats()
    sys.exit(0)


def print_stats():
    """ Prints formatted output """
    print("File size: {}".format(file_size))
    for key in sorted(dict_status_code.keys()):
        if dict_status_code[key] != 0:
            print("{}: {}".format(key, dict_status_code[key]))


signal.signal(signal.SIGINT, signal_handler)


for line in sys.stdin:
    """ loop throught the file """
    line_count += 1
    input_to_array = line.split()
    if len(input_to_array) != 9:
        pass
    else:
        try:
            file_size += int(input_to_array[-1])
        except ValueError:
            pass

        try:
            status_code = int(input_to_array[-2])
            if status_code in dict_status_code:
                dict_status_code[status_code] += 1
        except:
            pass

    if line_count % 10 == 0:
        print_stats()

# if the file is empty
print_stats()
