#!/bin/bash
dst_dir=$(basename $(pwd))
echo $dst_dir
if [ $# -ge 1 ]; then
	rsync -auv --exclude "**/.git" --exclude "**/.svn" --exclude "**/.vscode" --exclude "**/*.code-workspace"  . root@9.135.9.238:/root/$dst_dir 
	exit 0
fi

while true; do
	fswatch -r -1 -E -e "\.(git|svn|vscode)"  . 
	rsync -auv --exclude "**/.git" --exclude "**/.svn" --exclude "**/.vscode"  --exclude "**/*.code-workspace" . root@9.135.9.238:/root/$dst_dir 
done
