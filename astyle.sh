#!/bin/sh
file_name=$1
astyle --style=kr --indent=spaces=4 --indent-switches --suffix=none $file_name
