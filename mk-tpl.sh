#!/usr/bin/env bash

problemId=$1

# wget 'https://leetcode.com/api/problems/all/'

question__title_slug=`cat problems.json \
    | jq ".stat_status_pairs[].stat | select ( .frontend_question_id == ${problemId} ) " \
    | jq -r ".question__title_slug"`

echo $question__title_slug
key="${problemId}-${question__title_slug}"

mkdir -p "src/${key}"
cp src/template.go "src/${key}/${key}_test.go"
