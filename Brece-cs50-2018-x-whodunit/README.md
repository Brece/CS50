# Questions

## What's `stdint.h`?

it declares sets of integer types having specified widths, defines corresponding sets of macros

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

intN_t designates a signed integer type with width N (=bits)
uintN_t designates an unsignes integer type width N

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

BYTE = 1
DWORD = 4
LONG = 4
WORD = 2

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

First two bytes are file signatures, data used to identify or verify the content of a file
Hex:    0x424d
ASCII: BM (bitmap!)

## What's the difference between `bfSize` and `biSize`?

biSize is the size of BITMAPHEADER (40 bytes)
bfSize = bfOffBits (14+40) + biSizeImage

## What does it mean if `biHeight` is negative?

the device-independent bitmap (DIB) is top-down and its origin is upper-left corner

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

file doesn't exist or no permission to modify it

## Why is the third argument to `fread` always `1` in our code?

it reads the BITMAPFILEHEADER and BITMAPINFOHEADER once (because they are structures) to check if the file is in a specific format

## What value does line 65 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

3

## What does `fseek` do?

change the offset of the file pointer and allows you navigate through the file

## What is `SEEK_CUR`?

change the location of the pointer from its current location

## Whodunit?

TODO
