// MIT License
//
// Copyright (c) 2020 Tiernan8r
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
#include <stdio.h>
#include <strings.h>
#include "entry.h"

const int SMALL_TABLE = 9;
const int BIG_TABLE = 16;

char *charVals = " 123456789ABCDEF0";
int numChars = 17;

char toChar(int e)
{
    char val = ' ';

    if (e <= 0 || e > numChars)
    {
        return val;
    }

    return charVals[e];
}

int fromChar(char c)
{
    for (int i = 0; i < numChars; i++)
    {
        if (charVals[i] == c)
        {
            return i;
        }
    }

    return 0;
}