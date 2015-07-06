#!/bin/bash

# Script will clone and compile container generator cont.

# Usage example:
#   bash try_cont.sh

# PREREQUISITES: bash, git, python2.7

ROOT_DIR=$(pwd)

# - clone repositories -
if [ ! -d cont ]
then
  git clone https://github.com/izuzanak/cont.git
fi

# - compile container generator -
cd cont/cont_build
sh build.sh

CONT_DIR=$(pwd)
if [[ ":$PATH:" != *":$CONT_DIR:"* ]]
then
    export PATH="${PATH:+"$PATH:"}$CONT_DIR"
fi

cd $ROOT_DIR

# - compile cont examples -
cd cont/cont/examples
EXAMPLES_DIR=$(pwd)

for example in $(ls)
do
  cd $example
  echo "Compiling : example : $example"
  make -s
  cd $EXAMPLES_DIR
done

cd $ROOT_DIR

# - compile demo allocator -
cd cont/cont/demos/allocator/allocator_build
python mf_gen.py > Makefile
make -s -j $(nproc) 2> /dev/null

cd $ROOT_DIR

# - compile demo xml_parser -
cd cont/cont/demos/xml_parser/xml_parser_build
python mf_gen.py > Makefile
make -s -j $(nproc) 2> /dev/null

cd $ROOT_DIR

