#QR code endocer/decode
import qrcode

data = "Never gonna give you up, never gonna let you down"
print(data)

img = qrcode.make(data)  #creates a QR code that connects to the variable data 

img.save("C:/Users/pujas/Documents/xPython Projects/qrcode.png")   #convert all slashes to forward slashes or it won't recognize them


