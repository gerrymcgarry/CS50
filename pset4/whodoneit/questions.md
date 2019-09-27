# Questions

## What's `stdint.h`?

library which defines a set of integer aliases with specific widths

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

 uint8_t is an unsigned int of 8 bits
 uint32_t is an unsigned long long
 int32_t is a signed long long
 uint16_t is an unsigned 16 bit int

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

1,4 ,8 ,2

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

BM

## What's the difference between `bfSize` and `biSize`?

bfSize is the size of the file biSize is the size of the bitmap data 

## What does it mean if `biHeight` is negative?

top-down DIB, biCompression must be either BI_RGB or BI_BITFIELDS. Top-down DIBs cannot be compressed.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in `copy.c`?

file dosn't exist

## Why is the third argument to `fread` always `1` in our code?

each file contains one bitmap

## What value does `copy.c` assign to `padding` if `bi.biWidth` is `3`?

3

## What does `fseek` do?

moves to an offset in the file

## What is `SEEK_CUR`?

Current position of the file pointer