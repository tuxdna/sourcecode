function fun() {
    # for a in $@
    # do
    # 	echo $a
    # done
    echo $1
    echo $2
    echo $3
}

fun "$@"
