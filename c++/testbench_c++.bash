#! /bin/bash

echo "inputed file name : $basename $1";
#echo "${1%.*}";
echo "argument $2 ";

echo "Compiling file";

g++ $3 $1 -o "${1%.*}" ;

echo "Testing the file";

a=0;
while [ "$a" -lt $2 ]
do
	./"${1%.*}" "$a" | tee -a output.txt
	a=`expr $a + 100`;
done
cp output.txt ${1%.*}.txt;

echo "running r to plot graph";
R < script.r --no-save;

echo "Clearing up the messes";

cp figure.png ${1%.*}.png;

rm output.txt;
rm figure.png;
