import numpy as np
import cv2

video_capture_0 = cv2.VideoCapture(0)
video_capture_1 = cv2.VideoCapture("http://192.168.43.1:4747/mjpegfeed?1280x720")

while True:
    # Capture frame-by-frame
    ret0, frame0 = video_capture_0.read()
    ret1, frame1 = video_capture_1.read()

    #if (ret0):
        # Display the resulting frame
        #cv2.imshow('Cam 0', frame0)

    #if (ret1):
        # Display the resulting frame
        #cv2.imshow('Cam 1', frame1)

    #if cv2.waitKey(1) & 0xFF == ord('q'):
        #break
    hori = np.concatenate((frame0, frame1), axis=1)
    cv2.imshow("horizontal", hori);

# When everything is done, release the capture
video_capture_0.release()
video_capture_1.release()
cv2.destroyAllWindows()

