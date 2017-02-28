import cv2
import numpy as np
ex=-1
ey=-1
edge=[]

def draw_line(event,x,y,flags,param):
	global ex,ey
	if event==cv2.EVENT_LBUTTONDOWN:
		ex=x;ey=y
	elif event==cv2.EVENT_LBUTTONUP:
		cv2.line(img,(ex,ey),(x,y),(0,0,255),2)
		edge.append((ex,ey,x,y))


f=open("graph_points.txt","r")
l=f.readlines()

img = np.zeros((512,512,3), np.uint8)
cv2.namedWindow('image')
cv2.setMouseCallback('image',draw_line)
f.close()

for i in l:
	j=i.split()
	j=map(int,j)
	if len(j)==2:
		cv2.circle(img,(j[0],j[1]),3,(255,0,0),-1)




while(1):
    cv2.imshow('image',img)
    k = cv2.waitKey(20) & 0xFF
    if k == 27:
	f=open("graph_points.txt","a")
	for i in edge:
		f.write(str(i[0])+" "+str(i[1])+' '+str(i[2])+' '+str(i[3])+'\n')
	f.write("-99")
	f.close()
        break

cv2.destroyAllWindows()
