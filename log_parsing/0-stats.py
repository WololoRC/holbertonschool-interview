#!/usr/bin/python3
""" Wololo, Ayolo wololo! """
import sys
import re

cnt = 0
file_size = 0
status_codes = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
ocurrences = {}

try:
    for line in sys.stdin:
        try:
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
                print("Total file size: {}".format(file_size))
                for key in sorted(ocurrences.keys()):
                    value = ocurrences[key]
                    return_list.append("{}: {}".format(key, value))

                for item in return_list:
                    print(item)

        except KeyboardInterrupt:
            return_list = []

            print("Total file size: {}".format(file_size))
            for key in sorted(ocurrences.keys()):
                value = ocurrences[key]
                return_list.append("{}: {}".format(key, value))

            for item in return_list:
                print(item)

except KeyboardInterrupt:
    pass

