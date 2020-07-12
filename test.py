from skimage import data, io
from build import pylene as pln
from matplotlib import pyplot as plt

input = data.retina() # rgb-8 image

io.imshow(input)
plt.show()

out = pln.morpho.dilation(input, pln.se.rectangle(width=11, height=5))