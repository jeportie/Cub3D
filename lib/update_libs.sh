#!/bin/bash

git submodule deinit -f libft libgc -f minilibx
git rm -f libft libgc minilibx
rm -rf ../.git/modules/libft ../.git/modules/libgc ../.git/modules/minilibx

git submodule add https://github.com/jeportie/libft.git libft
git submodule add https://github.com/jeportie/libgc.git libgc
git submodule add https://github.com/42Paris/minilibx-linux.git minilibx
