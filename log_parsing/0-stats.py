#!/usr/bin/python3
""" Wololo, Ayolo wololo! """
from sys import stdin
import re

cnt = 0
file_size = 0
status_codes = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}

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

    cnt += 1

    try:
        if cnt == 10:
            cnt = 0
            print(f"File size: {file_size}")
            file_size = 0
            for key, value in status_codes.items():
                print(f"{key}: {value}")

    except KeyboardInterrupt:
        print(f"File size: {file_size}")
        file_size = 0
        for key, value in status_codes.items():
            print(f"{key}: {value}")
