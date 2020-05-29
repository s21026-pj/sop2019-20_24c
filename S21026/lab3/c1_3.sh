#!/bin/bash 

if [[ $0 =~ (\.sh)$ ]]
then
	echo -e "Skrypt posiada właściwą nazwę"
else 
	mv $0 $0.sh
	echo -e "Skrypt nie posiadał właściwego rozszerzenia - dodano .sh"
fi

