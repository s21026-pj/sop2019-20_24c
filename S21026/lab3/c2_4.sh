#!/bin/bash 

for word in $(ls -1)
do
	if [[ $word =~ (\.c)$ ]]
	then
	cc $word -o "${word%.*}"
	fi
done
