# Justin's Atari 2600 Public Noddy Source Code.

## Index

| Directory | Description |
|-----------|-------------|
| div15     | Divide value between 0 and 159 by 15 and return the result and the modulo (remainder). Enhanced some code examples to now to support nearly the full 0-254 range. Also a version that only does the division by 15 and passes the value and result in the A register for comparison to existing implementations. The code found in the DivisionRoutines(rev2).asm linked from here https://atariage.com/forums/blogs/entry/10805-unsigned-integer-division-routines/ will do the full range. My routine unfortunately does not do the extra addition found in the link via ADC of the carry bit if the original value was odd. Thanks to Omegamatrix for some great general purpose routines. My routine does meets my original goal but was proven to not be as general purpose as I had hoped. |


## Contact

Justin Lane (atari2600@jigglesoft.co.uk)


## License

Copyright (c) 2022 Justin Lane

Licensed under the MIT license

See the LICENSE file.

