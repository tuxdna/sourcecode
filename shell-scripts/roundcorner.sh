IMAGE_NAME=$1
# convert ${IMAGE_NAME} ${IMAGE_NAME}.png
# IMAGE_PATH=$2

# # for gravity in  NorthWest SouthWest NorthEast SouthEast
# # do
# #     composite -compose Over -quality 100 -gravity ${gravity} ${IMAGE_PATH}/cornermask_${gravity}.png ${IMAGE_NAME}.png ${IMAGE_NAME}${gravity}
# # done

# composite -compose Over -quality 100 -gravity NorthWest ${IMAGE_PATH}/cornermask_upper_left.png ${IMAGE_NAME}.png ${IMAGE_NAME}nw
# composite -compose Over -quality 100 -gravity SouthWest ${IMAGE_PATH}/cornermask_lower_left.png ${IMAGE_NAME}nw ${IMAGE_NAME}sw
# composite -compose Over -quality 100 -gravity NorthEast $image_path/cornermask_upper_right.png ${IMAGE_NAME}sw ${IMAGE_NAME}ne
# composite -compose Over -quality 100 -gravity SouthEast $image_path/cornermask_lower_right.png ${IMAGE_NAME}ne ${IMAGE_NAME}mask

# convert ${IMAGE_NAME}mask -transparent \"#ff00f6\" ${IMAGE_NAME}.png


# convert $IMAGE_NAME \
#     \( +clone -crop 16x16+0+0  -fill white -colorize 100% \
#        -draw 'fill black circle 15,15 15,0' \
#        -background Red  -alpha shape \
#        \( +clone -flip \) \( +clone -flop \) \( +clone -flip \) \
#      \) -flatten  rounded_corners_red.png

convert $IMAGE_NAME \
          -format 'roundrectangle 1,1 %[fx:w+4],%[fx:h+4] 15,15'\
          info: > rounded_corner.mvg

convert $IMAGE_NAME -border 3 -alpha transparent \
          -background none -fill white -stroke none -strokewidth 0 \
          -draw "@rounded_corner.mvg"    rounded_corner_mask.png

convert $IMAGE_NAME -border 3 -alpha transparent \
          -background none -fill none -stroke black -strokewidth 3 \
          -draw "@rounded_corner.mvg"    rounded_corner_overlay.png

convert $IMAGE_NAME -matte -bordercolor none -border 3  \
          rounded_corner_mask.png -compose DstIn -composite \
          rounded_corner_overlay.png -compose Over -composite \
          rounded_border.png
