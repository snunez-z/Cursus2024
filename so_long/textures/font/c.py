#! /usr/bin/env python
import fontforge
F = fontforge.open("/usr/share/fonts/Ubuntu/UbuntuMono-Bold.ttf")
for name in F:
    filename = name + ".png"
    # print name
    F[name].export(filename, 32)
    # F[name].export(filename, 600)     # set height to 600 pixels
