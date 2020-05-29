#!/bin/bash 

if [ -e ./config.cfg ]
then
	./config.cfg
elif [ $# != 0 ] && [ -x ./$1 ] # Można tak ale [ jest synonimem komendy test, lepiej:
								#elif [[ $# != 0 && -x ./$1 ]] 
then
	./"$1"
else 
	echo -e "BŁĄD: \"Brak pliku config albo nie podano nazwy właściwego pliku\""
fi

