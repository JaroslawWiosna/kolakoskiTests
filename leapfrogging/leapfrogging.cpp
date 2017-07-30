/**
 * @file leapfrogging.cpp
 *
 * @author Jaroslaw Wiosna
 *
 * @par Licence
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include <gtest/gtest.h>
#include "leapfrogging.hpp"

TEST(Test, leapfrogging)
{
    std::vector<std::size_t> kolakoski
       = {1,2,2,1,1,2,1,2,2,1,2,2,1,1,2,1};

    auto kol1 = kolakoskiLeapfrogging();
    auto kol2 = kolakoskiLeapfrogging(kol1);
    auto kol3 = kolakoskiLeapfrogging(kol2);
    auto kol4 = kolakoskiLeapfrogging(kol3);
    auto kol5 = kolakoskiLeapfrogging(kol4);
    auto kol6 = kolakoskiLeapfrogging(kol5);

    ASSERT_EQ( 2, kol1.size());

    for (std::size_t i=0; i < kolakoski.size(); ++i) {
      ASSERT_EQ( kolakoski[i], kol5[i] );
    }
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
