from skimage import data, io
from build import pylene as pln

# se = pln.se.dilation(5)

se = pln.se.rectangle(10, 10)
# se = pln.se.disc(10)


def print_and_make_dilation(input):
    io.imshow(input)
    io.show()

    out = pln.morpho.dilation(input, se)

    if out.size != 0:
        io.imshow(out)
        io.show()

def print_and_make_erosion(input):
    io.imshow(input)
    io.show()

    out = pln.morpho.erosion(input, se)

    if out.size != 0:
        io.imshow(out)
        io.show()

def print_and_make_opening(input):
    io.imshow(input)
    io.show()

    out = pln.morpho.opening(input, se)

    if out.size != 0:
        io.imshow(out)
        io.show()


def print_and_make_closing(input):
    io.imshow(input)
    io.show()

    out = pln.morpho.closing(input, se)

    if out.size != 0:
        io.imshow(out)
        io.show()

print_and_make_erosion(data.camera())
print_and_make_dilation(data.camera())
print_and_make_opening(data.camera())
print_and_make_closing(data.camera())
'''
print_and_make_dilation(data.clock())
print_and_make_dilation(data.retina())
'''
