#!/bin/bash

git submodule deinit -f lib/libft lib/libgc -f lib/minilibx
git rm -f lib/libft lib/libgc lib/minilibx
rm -rf .git/modules/lib/libft .git/modules/lib/libgc .git/modules/lib/minilibx

git submodule add https://github.com/jeportie/libft.git lib/libft
git submodule add https://github.com/jeportie/libgc.git lib/libgc
git submodule add https://github.com/jeportie/minilibx.git lib/minilibx
