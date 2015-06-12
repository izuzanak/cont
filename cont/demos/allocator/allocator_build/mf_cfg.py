
import os;

C_ALLOCATOR_DIR = os.sep.join(os.getcwd().split(os.sep)[:-1] + ["allocator"])

index = 0
C_ALLOCATOR_PROG = index; index += 1

index = 0
CFG_NAME   = index; index += 1
CFG_TARGET = index; index += 1
CFG_DIR    = index; index += 1
CFG_MODULE = index; index += 1

c_cfg = [
    ["ALLOCATOR",True,C_ALLOCATOR_DIR,None],
]

