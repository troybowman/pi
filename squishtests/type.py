def main():
    startApplication("pi")
    win = waitForObject(":PiWin_PiWin")
    type(win, "<m>")
    clickButton(waitForObject(":message.OK_QPushButton"))
    sendEvent("QCloseEvent", win)
