EXEC=$1
TMP_OUT=$2

echo "Parte 1: Contagem de Palavras"
for i in {1..18..1}; do
  testname=$(printf "%02d" $i)
  $EXEC < ./tests/part1/$testname.in > $TMP_OUT
  if ! diff -qwB ./tests/part1/$testname.out $TMP_OUT &>/dev/null; then
    diff -ywB ./tests/part1/$testname.out $TMP_OUT > ./output/diff_1_$i.log
    echo "Test $testname failed"
  else
    echo "Test $testname passed"
  fi
done

echo "Parte 2: Codigo de Huffman"
for i in {1..18..1}; do
  testname=$(printf "%02d" $i)
  $EXEC < ./tests/part2/$testname.in > $TMP_OUT
  if ! diff -qwB ./tests/part2/$testname.out $TMP_OUT &>/dev/null; then
    diff -ywB ./tests/part2/$testname.out $TMP_OUT > ./output/diff_2_$i.log
    echo "Test $testname failed"
  else
    echo "Test $testname passed"
  fi
done

rm $TMP_OUT
