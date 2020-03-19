#!/usr/bin/env bash

problemId=$1

# wget https://leetcode.com/api/problems/all/

question__title_slug=`cat problems.json \
    | jq ".stat_status_pairs[].stat | select ( .frontend_question_id == ${problemId} ) " \
    | jq -r ".question__title_slug"`

echo $problemId-$question__title_slug
key="${problemId}-${question__title_slug}"

idLength=${#problemId}
subDirs=("1+" "10+" "100+" "1000+")
subDir="${subDirs[idLength - 1]}"
dirBase="src/${subDir}"

mkdir -p "${dirBase}/${key}"

if [ "$2" == "cpp" ]; then
  newFile="${dirBase}/${key}/${key}_test.cpp"
  cp src/template.cpp "$newFile"
  sed -i '' "s/p_/p${problemId}/g" $newFile
else # Golang
  cp src/template.go "${dirBase}/${key}/${key}_test.go"
fi
