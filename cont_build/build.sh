#!/bin/sh

# - generate makefile -
python mf_gen.py > Makefile

# - compile container generator -
make -s -j 3

# - rename executable -
cp cont process
