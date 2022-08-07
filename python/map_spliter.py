from PIL import Image

file = open("../python/map-info.txt", "w")

with Image.open("../maps/main.png") as img:
    for x in range(30):
        for y in range(16):
            if img.getpixel((x, y)) == 1:
                file.write(str(y) + "-" + str(x) + "-empty\n")
            else:
                file.write(str(y) + "-" + str(x) + "-block\n")

file.close()