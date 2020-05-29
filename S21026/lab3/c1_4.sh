#!/bin/bash 

numberof=$(ls | wc | grep -o [[:digit:]] | head -n1)
if [[ $numberof > 5 ]]
then
	echo -e "W bieżącym katalogu jest więcej niż 5 plików"
else 
	echo -e "W bieżącym katalogu nie jest więcej niż 5 plików"
fi

