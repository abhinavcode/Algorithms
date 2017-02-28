import cv2
import numpy as np

ix,iy = -1,-1
ex=0
ey=0
l=[]
edge=[]
flag=False

# mouse callback function
def draw_circle(event,x,y,flags,param):
    global ix,iy,ex,ey,flag
    if event == cv2.EVENT_LBUTTONDBLCLK:
        cv2.circle(img,(x,y),3,(255,0,0),-1)
        ix,iy = x,y
	l.append((ix,iy))
	

# Create a black image, a window and bind the function to window
img = np.zeros((512,512,3), np.uint8)
cv2.namedWindow('image')
cv2.setMouseCallback('image',draw_circle)

while(1):
    cv2.imshow('image',img)
    k = cv2.waitKey(20) & 0xFF
    if k == 27:
	f=open("graph_points.txt","w")
	for i in l:
		f.write(str(i[0])+" "+str(i[1])+"\n")
	f.write("-99\n")
	f.close()
        break
    elif k == ord('a'):
        print l
cv2.destroyAllWindows()
