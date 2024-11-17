#!/bin/bash

# Move to the 'bin' directory
cd bin || exit 1  

# Run make in the 'bin' directory
make || exit 1  

# Check if MyShell is built and is executable
if [ ! -x "./MyShell" ]; then
    echo "MyShell is not an executable or not found..."
    exit 1
fi

# Open MyShell in a new terminal from within the 'bin' directory
gnome-terminal -- bash -c "./MyShell; exec bash"

