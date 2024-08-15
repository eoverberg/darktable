/*
    RawSpeed - RAW file decoder.

    Copyright (C) 2018 Roman Lebedev

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
*/

#include "bitstreams/BitStreamerLSB.h"
#include "bitstreams/BitStreamerTest.h"
#include <array>
#include <cstdint>
#include <gtest/gtest.h>

using rawspeed::BitStreamerLSB;

namespace rawspeed_test {

struct InvOnesTag;
struct OnesTag;

template <>
const std::array<uint8_t, 8> Pattern<BitStreamerLSB, OnesTag>::Data = {
    {/* [Byte0 Byte1 Byte2 Byte3] */
     /* Byte: [Bit7 .. Bit0] */
     0b01001011, 0b10000100, 0b00100000, 0b11110000}};
template <> uint32_t Pattern<BitStreamerLSB, OnesTag>::data(int index) {
  const auto set = GenOnesLE(0, -1);
  return set[index];
}

template <>
const std::array<uint8_t, 8> Pattern<BitStreamerLSB, InvOnesTag>::Data = {
    {0b00100101, 0b01000010, 0b00010000, 0b11111000}};
template <> uint32_t Pattern<BitStreamerLSB, InvOnesTag>::data(int index) {
  const auto set = GenOnesLE(1, 0);
  return set[index];
}

INSTANTIATE_TYPED_TEST_SUITE_P(LSB, BitStreamerTest, Patterns<BitStreamerLSB>);

} // namespace rawspeed_test
