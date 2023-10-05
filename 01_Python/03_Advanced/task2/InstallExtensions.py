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

def install_extension(extension_name):
    pyautogui.write(extension_name)
    time.sleep(3)
    PressIcon(extension_name)
    time.sleep(2)
    PressIcon("install")


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

extensions_to_install = [
    "clangd",
    "c++ testmate",
    "c++ helper",
    "cmake",
    "cmake tools"
]

for extension in extensions_to_install:
    install_extension(extension)
    time.sleep(4)