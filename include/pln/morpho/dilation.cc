#include <mln/core/image/ndbuffer_image.hpp>
#include <mln/core/image/ndimage.hpp>
#include <mln/morpho/dilation.hpp>
#include "dilation.hpp"
#include <mln/core/concepts/structuring_element.hpp>
#include "../core/se.hpp"

mln::ndbuffer_image pln::morpho::dilation(mln::ndbuffer_image input, se_t se)
{
    mln::image2d<uint8_t> *image = input.template cast_to<uint8_t, 2>();

    int type_id = se.get_type();
    
    switch (type_id)
    {
        case 0:
        {
            auto res = mln::morpho::dilation(*image, dynamic_cast<pln::se<mln::se::rect2d> *>(&se)->get_se());
            mln::ndbuffer_image output = res;
            return output;
        }
        
        default:
            return input;
    }
}