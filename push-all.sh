#!/usr/bin
set -Eeuo pipefail

echo"Pushing to main repository..."
git push

echo"Pushing 4_algorithms to algorithms repository..."
git subtree push--prefix=4_algorithms algorithms main

echo"All push complete ✅"