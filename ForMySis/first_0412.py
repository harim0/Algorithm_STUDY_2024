import cv2
import numpy as np
import time

# 무표정 얼굴 이미지 로드
neutral_face_img = cv2.imread('normal_fuck.jpeg')

# 비웃는 얼굴 이미지 로드
smile_face_img = cv2.imread('fuck_face.jpeg')

# 손 모양 이미지 로드
left_img = cv2.imread('left.png')
right_img = cv2.imread('right.png')

# 손 모양 이미지 크기 조정
left_hand = cv2.resize(left_img, (100, 150))
right_hand = cv2.resize(right_img, (100, 150))

# 윈도우 생성
cv2.namedWindow('Emotion Changer', cv2.WINDOW_NORMAL)

# 무표정 얼굴 표시
cv2.imshow('Emotion Changer', neutral_face_img)
cv2.waitKey(2000)  # 2초간 대기

# 비웃는 얼굴로 변경
cv2.imshow('Emotion Changer', smile_face_img)
cv2.waitKey(2000)  # 2초간 대기

# 손 모양 추가
smile_face_img[900:1050, 450:550] = left_hand
smile_face_img[900:1050, 650:750] = right_hand

# 손을 엿 모양으로 표시
cv2.imshow('Emotion Changer', smile_face_img)
cv2.waitKey(10000)  # 2초간 대기

# 창 닫기
cv2.destroyAllWindows()
