#!/bin/bash
# Define arrays for submodule names and their corresponding URLs
submodules=(\
	"libft"\
	"libgc"\
	"minilibx"\
	)

urls=(\
	"https://github.com/jeportie/libft.git"\
	"https://github.com/jeportie/libgc.git"\
	"https://github.com/42Paris/minilibx-linux.git"\
	)

# Deinitialize, remove, and delete cached module information for each submodule
for module in "${submodules[@]}"; do
  echo "Deinitializing and removing submodule: $module"
  git submodule deinit -f "$module"
  git rm -f "$module"
  rm -rf "../.git/modules/lib/$module"
done

# Add each submodule using its corresponding URL
for i in "${!submodules[@]}"; do
  module="${submodules[$i]}"
  url="${urls[$i]}"
  echo "Adding submodule: $module from $url"
  git submodule add "$url" "$module"
done

