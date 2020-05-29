#!/bin/bash

function setcolor {
	echo -e $(tput setaf $2)$1
}

setcolor $1 $2