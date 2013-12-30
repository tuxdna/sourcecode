my_array[10]="this is some value"
echo -n "my_array[10] => "
echo ${my_array[10]}

echo ${#my_array[@]}


# index=0
# git log --decorate --format=oneline | \
#     egrep -o '\(.*tag:.*\)' | \
#     egrep -o 'tag: [^)]*' | \
#     while read tag_name
# do
#     revlist[index]=$tag_name
#     echo ${revlist[index]}
#     index=`expr $index + 1`
# done

# fetch a list of tags in reverse chronological order
# into an array
revlist=( $(git log --decorate --format=oneline | \
    egrep -o '\(.*tag:.*\)' | \
    egrep -o 'tag: [^)]*' | cut -f2 -d' ' | tr -d ',' ) \
    )

echo "Total tags:" ${#revlist[@]}

for i in $( seq 0 $(( ${#revlist[@]} -1 )) )
do
    echo ${revlist[i]}
done
