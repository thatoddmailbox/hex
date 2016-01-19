#!/bin/sh
g++ -x c++ $1 -framework ApplicationServices -include hex.h -Wc++11-extensions -o $2
chmod +x $2