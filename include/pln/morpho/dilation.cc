#include <mln/core/image/ndbuffer_image.hpp>
#include <mln/core/image/ndimage.hpp>
#include <mln/morpho/dilation.hpp>
#include "dilation.hpp"

mln::ndbuffer_image pln::morpho::dilation(mln::ndbuffer_image input, se_t se)
{
    mln::image2d<uint8_t> *image = input.CastTo<2, uint8_t>();

    auto res = mln::morpho::dilation(image, se.get_se())

    mln::ndbuffer_image output = res;
    return output;
}