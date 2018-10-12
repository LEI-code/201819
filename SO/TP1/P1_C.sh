#!/bin/bash
find * -type d -printf "%p %T@\n" | awk -v from=$(date -d "$1" +"%s.%N") -v to=$(date -d "$2" +"%s.%N") '$2 >= from && $2 <= to { print $1 }'