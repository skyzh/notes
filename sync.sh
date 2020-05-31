#!/bin/bash

set -e

if [ $# -eq 0 ]; then
    echo "empty commit message"
    exit
fi

rsync -am --progress --include="*.pdf" --include='*/' --exclude='*' ../notes-private/Notes ./
cp -a "../notes-private/Notes/Bridging Theory and Practice" ./Notes/
git --no-pager diff
read -p "Press [ENTER] to continue"

rm -rf .git
git init
git remote add origin https://github.com/skyzh/notes

cat >> CHANGELOG.md <<EOF
* $(date)       $1
EOF

git add -A
echo "Commit message:" $1
git commit -m "$1"
read -p "Press [ENTER] to push"
git push origin master -uf
