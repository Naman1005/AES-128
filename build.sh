#!/bin/bash
# Simple build script for AES-128 CLI project
# Usage: bash build.sh

g++ -std=c++11 -Wall -Iinclude main.cpp src/aes.cpp src/file_utils.cpp -o aes_cli
