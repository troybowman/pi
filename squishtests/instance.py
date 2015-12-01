# -*- coding: utf-8 -*-

def main():
    startApplication("pi")
    type(waitForObject(":PiWin_PiWin"), "<n>")
    ctx = waitForApplicationLaunch()
    sendEvent("QCloseEvent", waitForObject(":PiWin_PiWin"))
