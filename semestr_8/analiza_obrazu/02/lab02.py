#!/usr/bin/env python
import image_anal as image
img = image.ImageAnal()
img.load_image("tux.png")
img.progrowanie(method="local", otoczenie=25)
img.save("scale_down.png")
