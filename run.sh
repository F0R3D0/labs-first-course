#!/bin/bash
 
# Поиск всех файлов типа makefile в подкаталогах
 
find . -type f -name "Makefile*" -exec sed -i 's/\//\\/g' {} \;