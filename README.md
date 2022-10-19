# fileZip

A programme for zipping together two files.

I can't think of a single use for this, except it's kinda funny to stitch files together.

It's not concatenation, files are zipped together character by character, zip a file against itself to double the occurence of each character.

file1 = "abc",
zip file1 file1 output => output = "aabbcc"

file1 = "abc"
file2 = "123"
zip file1 file2 output => output = "a1b2c3"

Usage: ./prog [file1] [file2] [outputFile]
