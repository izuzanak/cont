
# - compile examples -
for MFILE in $(find examples -name Makefile)
do
  cd ${MFILE%/*}
  make
  cd -
done

# - execute examples -
for EXEC in $(find examples -executable -a -type f)
do
  $EXEC
done

