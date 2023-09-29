#!/usr/bin/python3
""" Wololo, Ayolo wololo! """
from sys import stdin
import re

cnt = 0
file_size = 0
status_codes = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
ocurrences = {}

for line in stdin:
    l_line = re.split(
        r'^(\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}) - \[([^\]]+)\] "GET \/projects\/260 HTTP\/1\.1" (\d+) (\d+)$',
        line
    )

    l_line.pop(0)
    l_line.pop()

    file_size += int(l_line[3])

    x = status_codes.get(int(l_line[2]))
    status_codes.update({int(l_line[2]): x + 1})
    ocurrences.update({int(l_line[2]): status_codes.get(int(l_line[2]))})

    cnt += 1

    if cnt == 10:
        return_list = []
        cnt = 0
        print("File size: {}".format(file_size))
        file_size = 0
        for key, value in ocurrences.items():
            return_list.append("{}: {}".format(key, value))
        
        return_list.sort()
        for item in return_list:
            print(item)

        ocurrences.clear()
