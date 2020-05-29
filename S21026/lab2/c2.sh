#!/bin/bash
n=$((${#1}-1))
echo -n  "$1 ma kota, a kot ma ${1:0:n}"

if [[ "${1:n}" == "a" ]] ; then 
echo  "ę"
else
echo "${1:n}a"
fi


