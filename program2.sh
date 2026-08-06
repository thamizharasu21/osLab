#!/bin/bash
echo"enter directory name:"
read dir
cp -r "$dir" "${dir}_backup"
echo "backup created successfully."