

#include <gtest/gtest.h>

#include "Matrix/Matrix.hpp"


TEST(TEST1, access_init)
{
    Matrix m{};

    ASSERT_EQ(m.xx, 0.0);
    ASSERT_EQ(m.xy, 0.0);
    ASSERT_EQ(m.xz, 0.0);

    ASSERT_EQ(m.yx, 0.0);
    ASSERT_EQ(m.yy, 0.0);
    ASSERT_EQ(m.yz, 0.0);

    ASSERT_EQ(m.zx, 0.0);
    ASSERT_EQ(m.zy, 0.0);
    ASSERT_EQ(m.zz, 0.0);
}

TEST(TEST1, access_init_2)
{
    Matrix m{1,2,3,4,5,6,7,8,9};

    ASSERT_EQ(m.xx, 1.0);
    ASSERT_EQ(m.xy, 2.0);
    ASSERT_EQ(m.xz, 3.0);

    ASSERT_EQ(m.yx, 4.0);
    ASSERT_EQ(m.yy, 5.0);
    ASSERT_EQ(m.yz, 6.0);

    ASSERT_EQ(m.zx, 7.0);
    ASSERT_EQ(m.zy, 8.0);
    ASSERT_EQ(m.zz, 9.0);
}

TEST(TEST1, access_member_assignment)
{
    Matrix m{};
    ASSERT_EQ(m.xx, 0.0);
    
    m.xx = 1.0;
    ASSERT_EQ(m.xx, 1.0);

    m.xx = 2.0;
    ASSERT_EQ(m.xx, 2.0);

    m.yx = 2.0;
    ASSERT_EQ(m.yx, 2.0);
}
TEST(TEST1, access_class_assignment)
{
    Matrix m1{1,2,3,4,5,6,7,8,9};
    auto m2 = m1;

    ASSERT_EQ(m2.xx, 1.0);
    ASSERT_EQ(m2.xy, 2.0);
    ASSERT_EQ(m2.xz, 3.0);

    ASSERT_EQ(m2.yx, 4.0);
    ASSERT_EQ(m2.yy, 5.0);
    ASSERT_EQ(m2.yz, 6.0);

    ASSERT_EQ(m2.zx, 7.0);
    ASSERT_EQ(m2.zy, 8.0);
    ASSERT_EQ(m2.zz, 9.0);
}

TEST(TEST1, access_member_compare)
{
    Matrix m1{1,2,3,4,5,6,7,8,9};
    auto m2 = m1;

    ASSERT_EQ(m1.xx, m2.xx);
    ASSERT_EQ(m1.xy, m2.xy);
    ASSERT_EQ(m1.xz, m2.xz);

    ASSERT_EQ(m1.yx, m2.yx);
    ASSERT_EQ(m1.yy, m2.yy);
    ASSERT_EQ(m1.yz, m2.yz);

    ASSERT_EQ(m1.zx, m2.zx);
    ASSERT_EQ(m1.zy, m2.zy);
    ASSERT_EQ(m1.zz, m2.zz);
}

TEST(TEST1, access_class_equal)
{
    Matrix m1{1,2,3,4,5,6,7,8,9};
    auto m2 = m1;

    ASSERT_EQ(m1, m2);
}
TEST(TEST1, access_class_notequal)
{
    Matrix m{};
    Matrix m1{1,2,3,4,5,6,7,8,9};
    Matrix m2{1,2,3,4,5,6,7,8,12345};
    
    ASSERT_NE(m,m1);
    ASSERT_NE(m,m2);
    ASSERT_NE(m1,m2);
}

