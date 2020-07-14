from skimage import data, io
from build import pylene as pln

def print_and_make_dilation(input):
    io.imshow(input)
    io.show()

    out = pln.morpho.dilation(input, pln.se.rectangle(width=10, height=10))

    io.imshow(out)
    io.show()

print_and_make_dilation(data.camera())
print_and_make_dilation(data.clock())
#print_and_make_dilation(data.retina())
