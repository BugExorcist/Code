from PIL import Image, ImageFilter

# im1 = Image.open("1.png")
# # im1.show()
# print(im1.format,im1.mode,im1.size,im1.filename)

# im2 = Image.new("RGB",(300,200),(255,0,179))
# # im2.show()
# # im2.save("3.png")

# im3 = Image.open("2.jpg")
# print(im3.format,im3.mode,im3.size,im3.filename)
# #im3.save("3.png")

# im4 = Image.open("1.png")
# im5 = im4.convert("RGB")
# # im4.save("4.jpg")
# #im5.save("5.jpg")

# #im3.show()
# r,g,b = im3.split()
# im_merge = Image.merge("RGB", (g,r,b))
# im_merge.show()

#im1 = Image.open("2.jpg")
# image = Image.open("5.jpg")

# im2 = Image.resize(im1.size)

# def blend_im(im1,im2):
#     Image.blend(im1,im2,0.5).save('6.jpg')

# blend_im(im1,im2)

#im1.transpose(Image.ROTATE_90).show()

im = Image.open("2.jpg")
im_ft = im.filter(ImageFilter.EMBOSS)
im_ft.show()



