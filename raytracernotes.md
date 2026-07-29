
# C++ Notes - Ray Tracer
<!-- Append-only. Ctrl-F to find things. Don't organize. -->
## Lookups:
const vec3& in a parameter — 2026-07-24, vec3.h
This reads: a refernce to a constant vec3 object
& to Pass by reference so it doesn't copy the object; const = can't modify it.
Language Correlation: In Java, objects are passed by reference. This is just the C++ way to get that with no mutate promise.

const correctness  - 2026-07-29,
"int* const" vs "const int"* 
^This reads "constant ptr to a regular int" vs "ptr  to a constant int"
const always takes what is to the left, unless there is nothing to the left.

## Errors Seen + Handled:
