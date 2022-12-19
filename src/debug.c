// MIT License
//
// Copyright (c) 2022 Tiernan8r
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
#include "entry.h"
#include "debug.h"

board_t testBoard()
{
    // make a test 9*9 board:
    //   0   1   2   3   4   5   6   7   8
    // +---+---+---+---+---+---+---+---+---+
    // | 6 | 4 |   |   | 3 |   |   |   | 7 | 0
    // +---+---+---+---+---+---+---+---+---+
    // | 5 |   | 1 |   | 7 |   | 9 |   |   | 1
    // +---+---+---+---+---+---+---+---+---+
    // |   |   |   |   |   |   |   | 1 |   | 2
    // +---+---+---+---+---+---+---+---+---+
    // |   |   | 4 | 9 |   | 8 |   | 6 |   | 3
    // +---+---+---+---+---+---+---+---+---+
    // |   | 8 |   |   |   | 3 |   | 2 |   | 4
    // +---+---+---+---+---+---+---+---+---+
    // |   |   |   | 4 |   |   |   |   |   | 5
    // +---+---+---+---+---+---+---+---+---+
    // | 4 |   |   | 1 | 5 | 7 |   | 3 |   | 6
    // +---+---+---+---+---+---+---+---+---+
    // | 2 |   | 8 | 3 |   |   |   | 4 |   | 7
    // +---+---+---+---+---+---+---+---+---+
    // | 7 | 5 |   |   |   |   |   | 9 | 6 | 8
    // +---+---+---+---+---+---+---+---+---+
    board_t b = {
        {
            // row 0:
            {
                6,
                4,
                0,
                0,
                3,
                0,
                0,
                0,
                7,
            },
            // row 1:
            {
                5,
                0,
                1,
                0,
                7,
                0,
                9,
                0,
                0,
            },
            // row 2:
            {
                0,
                0,
                0,
                0,
                0,
                0,
                0,
                1,
                0,
            },
            // row 3
            {
                0,
                0,
                4,
                9,
                0,
                8,
                0,
                6,
                0,
            },
            // row 4
            {
                0,
                8,
                0,
                0,
                0,
                3,
                0,
                2,
                0,
            },
            // row 5
            {
                0,
                0,
                0,
                4,
                0,
                0,
                0,
                0,
                0,
            },
            // row 6:
            {
                4,
                0,
                0,
                1,
                5,
                7,
                0,
                3,
                0,
            },
            // row 7
            {
                2,
                0,
                8,
                3,
                0,
                0,
                0,
                4,
                0,
            },
            // row 8
            {
                7,
                5,
                0,
                0,
                0,
                0,
                0,
                9,
                6,
            },
        },
        9,
    };

    return b;
}