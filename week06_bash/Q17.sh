#! /bin/bash


file_wordcnt() {

	FILES=$(find . -name "*.txt")
	for FILE in $FILES; do
		RES=$(cat $FILE | wc -w)
		echo "$FILE 파일의 단어 개수는 $RES개 입니다."
	done
}

file_wordcnt
