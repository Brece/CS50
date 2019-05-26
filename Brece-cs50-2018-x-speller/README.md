# Questions

## What is pneumonoultramicroscopicsilicovolcanoconiosis?

max defined length of a string; len(word) = 45

## According to its man page, what does `getrusage` do?

getrusage() returns resource usage measures

## Per that same man page, how many members are in a variable of type `struct rusage`?

16 members, unmaintained are set to zero

## Why do you think we pass `before` and `after` by reference (instead of by value) to `calculate`, even though we're not changing their contents?

TODO

## Explain as precisely as possible, in a paragraph or more, how `main` goes about reading words from a file. In other words, convince us that you indeed understand how that function's `for` loop works.

- it gets a single character of the file as long as it is not the EOF
- adds char to array word if it's alphabetical or a '\' and move word-index by one
- if the word exceedes the lenght of 45 the word-index will be set to zero
- if the char is number and not EOF the word-index will also be set to zero
- if the current line has no char to append and index < 0, this means that a whole word if found and append the end of the string with '\0' and increase word counter by one
- checks if the word is mispelled, if so is will be print out and increase mispelled counter by one, index is set to zero, records runtime

## Why do you think we used `fgetc` to read each word's characters one at a time rather than use `fscanf` with a format string like `"%s"` to read whole words at a time? Put another way, what problems might arise by relying on `fscanf` alone?

if the word exceeds the defined length or it contains a non alphabetical char the programm is going to waste resources and in the end increase runtime,
hence checking a single char is the most efficient way

## Why do you think we declared the parameters for `check` and `load` as `const` (which means "constant")?

declaring as constants make them unchangeable
