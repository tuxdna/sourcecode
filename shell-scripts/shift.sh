# echo $*
# shift
# VM=$1
# echo $VM


read -r -d '' VM <<-'EOF'
This is some text
that spans multiple lines.
doesn't it?
:)
EOF


echo "$VM"
