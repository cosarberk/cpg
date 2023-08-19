#!/bin/bash



clear && 
gcc example.c -o example  ./cpg/cpg.c -I ./cfg/libpq -lpq &&
sudo chmod +x example && ./example
