import pyautogui
import time
import os


def PressIcon(icon):
    mypath = os.path.dirname(os.path.realpath(__file__))+"/"+icon+".png"
    isfind=None
    while isfind is None:
        isfind=pyautogui.locateOnScreen(mypath,confidence=0.7)
        image_x, image_y, image_width, image_height = isfind
        image_center_x = image_x + image_width / 2
        image_center_y = image_y + image_height / 2
        pyautogui.click(image_center_x, image_center_y)

pyautogui.hotkey('win')
time.sleep(1)
pyautogui.write('termina')
time.sleep(1)
PressIcon("terminal")
time.sleep(1)
pyautogui.write('code')
pyautogui.hotkey('enter')
time.sleep(1)
PressIcon("Extensions")
time.sleep(3)

pyautogui.write('clangd')
time.sleep(3)
PressIcon("clangd")
time.sleep(2)
PressIcon("install")

pyautogui.write('c++ testmate')
time.sleep(3)
PressIcon("c++ testmate")
time.sleep(2)
PressIcon("install")


pyautogui.write('c++ helper')
time.sleep(4)
PressIcon("c++ helper")
time.sleep(2)
PressIcon("install")

pyautogui.write('cmake')
time.sleep(4)
PressIcon("cmake")
time.sleep(2)
PressIcon("install")

pyautogui.write('cmake tools')
time.sleep(4)
PressIcon("cmake tools")
time.sleep(2)
PressIcon("install")