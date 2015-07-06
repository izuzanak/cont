#!/bin/bash

# Script will clone and compile container generators cont and cont_c.

# Usage example:
#   bash try_cont.sh

# PREREQUISITES: bash, git, python2.7

ROOT_DIR=$(pwd)

# - clone repositories -
if [ ! -d cont ]
then
  git clone https://github.com/izuzanak/cont.git
fi

if [ ! -d cont_c/cont ]
then
  mkdir -p cont_c
  cd cont_c
  git clone -b cont_c https://github.com/izuzanak/cont.git
  cd $ROOT_DIR
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

# - compile container generator cont_c -
cd cont_c/cont/cont_build
sh build.sh
mv process process_c

CONT_DIR=$(pwd)
if [[ ":$PATH:" != *":$CONT_DIR:"* ]]
then
    export PATH="${PATH:+"$PATH:"}$CONT_DIR"
fi

cd $ROOT_DIR

# - compile cont examples -
cd cont_c/cont/cont/examples
EXAMPLES_DIR=$(pwd)

for example in $(ls)
do
  cd $example
  echo "Compiling : example : $example"
  make -s
  cd $EXAMPLES_DIR
done

cd $ROOT_DIR

