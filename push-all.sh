#!/bin/bash

echo "Pushing to main repository..."
git push || exit 1

echo "Pushing 4_algorithms to algorithms repository..."
git subtree push --prefix=4_algorithms algorithms main || echo "No new changes in algorithms"

echo "All push complete ✅"