#!/bin/zsh

# Assuming you're in the repository directory
# Replace SOURCE_DIR with the path to your 20 folders
SOURCE_DIR="/Users/ryan/Desktop/ntu/dsa/B12902014/"

# Loop through each folder in the source directory
for folder in "$SOURCE_DIR"/*; do
  if [ -d "$folder" ]; then
    folder_name=$(basename "$folder")
    
    # Check if main.c exists in this folder
    if [ -f "$folder/main.c" ]; then
      # Create a corresponding folder in the repo if it doesn't exist
      mkdir -p "$folder_name"
      
      # Copy the main.c file
      cp "$folder/main.c" "$folder_name/"
      
      echo "Copied main.c from $folder_name"
    fi
  fi
done

# Add the files to git
git add .

# Commit the changes
git commit -m "Add main.c files from 20 folders"

# Push to GitHub
git push origin main
