#!/bin/bash

ASTAR=./astar/solver
BREADTH=./breadth/solver
DEPTH=./depth/solver
GENERATOR=./generator/generator
RESET="\033[0m"
RED="\033[31m"
GREEN="\033[32m"
YELLOW="\033[33m"
BOLD="\033[1m"

function generate
{
    start=$(date +%s.%N)
    $GENERATOR $1 $1 > .perf_map$1
    genret=$?
    end=$(date +%s.%N)
    time=$(bc <<< $end-$start)
    if [ $genret -eq 0 ]
    then
	printf %.6s $time"s"
    else
        /bin/echo -en $RED"KO "$genret$GREEN
    fi
}

function solver
{
    start=$(date +%s.%N)
    $1 $2 >/dev/null
    ret=$?
    end=$(date +%s.%N)
    time=$(bc <<< $end-$start)
    if [ $ret -eq 0 ]
    then
	printf %.6s $time"s"
    else
        /bin/echo -en $RED"KO "$ret$GREEN
    fi
}

arglen=`expr $#`
if [ $arglen -lt 1 ]
then
    echo "Usage: "$0" limit [OPTION]"
    echo "Exemple: "$0" 3000 gen"
    echo "Note: You can add a file 'map' to test it"
    exit
fi

if [ -f $ASTAR ] && [ -f $BREADTH ] && [ -f $DEPTH ] && [ -f $GENERATOR ]
then
    /bin/echo -ne "\n"$GREEN$BOLD"\t\t"
    for i in `seq 1 58`;
    do
	/bin/echo -ne "="
    done
    /bin/echo ""
    /bin/echo -e "\t\t||\t\tgenerator\tastar\tbreadth\tdepth\t||"
    /bin/echo -e "\t\t||\t\t\t\t\t\t\t||"
    SIZE=1000
    genret=0
    if [ -f "map" ]
    then
	/bin/echo -ne "\t\t|| 'map' \t"
	/bin/echo -ne "DISABLED\t"
	solver $ASTAR map
	/bin/echo -ne "\t"
	solver $BREADTH map
	/bin/echo -ne "\t"
	solver $DEPTH map
	/bin/echo -e "\t||"
    fi
    while [ $genret -eq 0 ] && [ $SIZE -lt $(($1+1)) ];
    do
	/bin/echo -ne "\t\t|| "$SIZE" \t"
	if [ $arglen -eq 2 ]
	then
	    generate $SIZE
	    /bin/echo -ne "\t"
	else
	    /bin/echo -ne "DISABLED"
	fi
	/bin/echo -ne "\t"
	solver $ASTAR ".perf_map"$SIZE
	/bin/echo -ne "\t"
	solver $BREADTH ".perf_map"$SIZE
	/bin/echo -ne "\t"
	solver $DEPTH ".perf_map"$SIZE
	/bin/echo -e "\t||"
	SIZE=$(($SIZE+1000))
    done
    /bin/echo -e "\t\t||\t\t\t\t\t\t\t||"
    /bin/echo -ne "\t\t"
    for i in `seq 1 58`;
    do
	/bin/echo -ne "="
    done
    echo ""
else
    /bin/echo -e "\n"$RED$BOLD"Fatal error: binary not found.\n"
fi
