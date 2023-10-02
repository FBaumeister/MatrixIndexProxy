#ifndef M_MATRIX
#define M_MATRIX

#include <array>
#include <type_traits>

template<std::size_t i, typename ContainerType>
struct IndexProxy
{
    ContainerType& m_containerRef;
    // Get the underlying value type of the container
    using ValueType = std::remove_reference_t<decltype(*std::begin(std::declval<ContainerType&>()))>;

    constexpr IndexProxy(ContainerType& container, ValueType value)
        : m_containerRef(container)
    {
        *this = value; // Explicit assignment!
    }

    constexpr IndexProxy(ContainerType& container)
        : m_containerRef(container)
    {
    }

    constexpr IndexProxy(ValueType value)
    {
        m_containerRef[i] = value;
    }

    constexpr ValueType operator =(ValueType newValue)
    {
        m_containerRef[i] = newValue;
        return *this;
    }

    constexpr operator ValueType() const noexcept
    {
        return m_containerRef[i];
    }

    // TODO: WHY NOT? auto operator<=>(const IndexProxy<i, ContainerType>&) const = default;
};


class Matrix
{
private:

    using ArrayType = std::array<double, 3 * 3>;
    ArrayType m_data;

public:
    constexpr Matrix() = default;
    // Qnd for testing:
    constexpr Matrix(double xx, double xy, double xz, double yx, double yy, double yz, double zx, double zy, double zz)
        : xx(m_data, xx)
        , xy(m_data, xy)
        , xz(m_data, xz)
        , yx(m_data, yx)
        , yy(m_data, yy)
        , yz(m_data, yz)
        , zx(m_data, zx)
        , zy(m_data, zy)
        , zz(m_data, zz)
    {
    }
    IndexProxy<0, ArrayType> xx{m_data};
    IndexProxy<1, ArrayType> xy{m_data};
    IndexProxy<2, ArrayType> xz{m_data};

    IndexProxy<3, ArrayType> yx{m_data};
    IndexProxy<4, ArrayType> yy{m_data};
    IndexProxy<5, ArrayType> yz{m_data};

    IndexProxy<6, ArrayType> zx{m_data};
    IndexProxy<7, ArrayType> zy{m_data};
    IndexProxy<8, ArrayType> zz{m_data};


    constexpr ArrayType getData() const noexcept
    {
        return m_data;
    }

    auto operator<=>(const Matrix&) const = default;
};


#endif
