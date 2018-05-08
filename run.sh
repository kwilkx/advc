#!/bin/sh

#run
find build/ -type f  -executable -exec sh -c 'exec "$1"' _ {} \;

