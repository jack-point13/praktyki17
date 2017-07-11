#!/bin/bash
g++ -Wall -std=c++11 -I `root-config --incdir` -o analysis LHEF.C `root-config --libs`