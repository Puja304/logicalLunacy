from PIL import Image, ImageEnhance, ImageFilter  #import from the pillow library
import os   #idk why but imported
path = './images'  #the folder address. Every photo in this folder will be edited in the exact same way
pathOut = './edited_images'  #the resulting photos after being edited


for filename in os.listdir(path) : #for every file inside the path folder
    img  = Image.open(f"{path}/{filename}")   #opening the image as the object img
    edit = img.filter(ImageFilter.SHARPEN).convert('L')  #applies edit. the sharpen part sharpens and the convert to L part maeks it greyscale

    #to add some contrast
    factor = 1.5   #defien the factor by which you want to add contrast
    enhancer = ImageEnhance.Contrast(edit)  #create an object that enhances the current object 'edit'
    edit = enhancer.enhance(factor)  #redefine edit as that object, taking in the defined factor

    clean_name = os.path.splitext(filename)[0]  #creates a new location with the same name as the original image
    edit.save(f'./{pathOut}/{clean_name}_edited.jpg')   #saves edited image 

for filename in os.listdir(pathOut):   #for all files in the pathout folder
    with Image.open(f'{pathOut}/{filename}') as im: 
        im.show()  #show it. 