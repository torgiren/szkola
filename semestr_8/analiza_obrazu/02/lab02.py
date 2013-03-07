#!/usr/bin/env python
import image_anal as image
img = image.ImageAnal()
img.load_image("tux.png")
img.scale(0.5)
img.scale(2.5)
img.save("scale_down.png")
