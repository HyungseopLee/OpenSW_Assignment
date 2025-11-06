#! /bin/bash


file_wordcnt() {

	RES=$(cat $1 | wc -w)
	echo "$1 파일의 단어 개수는 $RES개 입니다."

}

read -p "Enter a file name: " FILE
file_wordcnt $FILE
