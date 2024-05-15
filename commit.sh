#! /usr/bin/bash
read -p "Enter Commit Message: " comMes
git add .
git commit -m "${comMes}"
git push -u origin kitBranch