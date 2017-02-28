import cv2
import time
import numpy as np

f=open("mst_points.txt","r")
l=f.readlines()
x=[]
for i in range(len(l)):
	l[i]=l[i].split()
	x.extend(l[i])
x=map(int,x)


img = np.zeros((512,512,3), np.uint8)
cv2.namedWindow('image')

for i in range(0,len(x),4):
    	cv2.line(img,(x[i],x[i+1]),(x[i+2],x[i+3]),(255,0,0),2)



while(1):
    cv2.imshow('image',img)
    k = cv2.waitKey(20) & 0xFF
    if k == 27:
        break

cv2.destroyAllWindows()
