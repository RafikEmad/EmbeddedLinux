import pyautogui
import time
import os

pyautogui.hotkey('win')
# pyautogui.keyDown('win')
time.sleep(1)
# pyautogui.press('a')
# pyautogui.keyUp('win')
# time.sleep(1)
pyautogui.write('termina')
time.sleep(1)
#pyautogui.hotkey('enter')
mypath = os.path.dirname(os.path.realpath(__file__))+"/terminal.png"
isfind=None
while isfind is None:
    isfind=pyautogui.locateOnScreen(mypath,confidence=0.7)

print("I got the image")