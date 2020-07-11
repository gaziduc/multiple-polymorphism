namespace pln
{
    template <typename T>
    class se : public se_t
    {
    public:
        se(const T& element);

        T get_se() const override;

    private:
        T element_;
    };
}