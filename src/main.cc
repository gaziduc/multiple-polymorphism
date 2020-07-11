#include <pybind11/pybind11.h>
#include "convert.hh"

namespace py = pybind11;

PYBIND11_MODULE(pylene, m)
{
    m.def("numpy_to_ndbuffer_image", &numpy_to_ndbuffer_image,
          "Converts a numpy array to a mln::ndbuffer_image",
          py::arg("array"));
}


/*
int print_vectorize(int o)
{
    std::cout << o << '\n';
}

template <typename T>
class Matrix
{
public:
    Matrix(py::array_t<T> array)
    {
        py::buffer_info buf = array.request();
        num_dim_ = buf.ndim;

        if (num_dim_ > 3)
            throw std::runtime_error("Too many dimensions");

        std::vector<ssize_t> vec{1, 1, 1};

        for (size_t i = 0; i < num_dim_; i++)
            vec[i] = buf.shape[i];

        x_ = vec[0];
        y_ = vec[1];
        z_ = vec[2];

        data_ = new T[x_ * y_ * z_];

        T *ptr = (T *) buf.ptr;
        for (ssize_t k = 0; k < z_; k++)
            for (ssize_t j = 0; j < y_; j++)
                for (ssize_t i = 0; i < x_; i++)
                {
                    data_[k * y_ * x_ + j * x_ + i] = ptr[k * y_ * x_ + j * x_ + i];
                }
    }

    T *get_data()
    {
        return data_;
    }

    ssize_t get_x() const
    {
        return x_;
    }

    ssize_t get_y() const
    {
        return y_;
    }

    ssize_t get_z() const
    {
        return z_;
    }

    size_t get_num_dim() const
    {
        return num_dim_;
    }

    void print_matrix()
    {
        for (ssize_t k = 0; k < z_; k++)
        {
            for (ssize_t j = 0; j < y_; j++)
            {
                for (ssize_t i = 0; i < x_; i++)
                {
                    std::cout << data_[k * y_ * x_ + j * x_ + i] << ' ';
                }

                std::cout << '\n';
            }

            std::cout << "\n\n\n";
        }
    }

    mln::ndbuffer_image to_buffer_image()
    {
        switch (num_dim_)
        {
            case 1:
                return data_;

            default:
                return data_;
        }
    }

private:
    ssize_t x_;
    ssize_t y_;
    ssize_t z_;
    size_t num_dim_;

    T *data_;
};
*/
