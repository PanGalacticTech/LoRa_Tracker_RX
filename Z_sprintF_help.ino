




/*

  [Specifier]

  d or i  Signed decimal integer  392
  u Unsigned decimal integer  7235
  o Unsigned octal  610
  x Unsigned hexadecimal integer  7fa
  X Unsigned hexadecimal integer (uppercase)  7FA
  f Decimal floating point, lowercase 392.65
  F Decimal floating point, uppercase 392.65
  e Scientific notation (mantissa/exponent), lowercase  3.9265e+2
  E Scientific notation (mantissa/exponent), uppercase  3.9265E+2
  g Use the shortest representation: %e or %f 392.65
  G Use the shortest representation: %E or %F 392.65
  a Hexadecimal floating point, lowercase -0xc.90fep-2
  A Hexadecimal floating point, uppercase -0XC.90FEP-2
  c Character a
  s String of characters  sample
  p Pointer address b8000000
  n Nothing printed.
  The corresponding argument must be a pointer to a signed int.
  The number of characters written so far is stored in the pointed location.
  % A % followed by another % character will write a single % to the stream.  %


  [Flags]

  - Left-Justify
  + Force sign (- or +)
  " " (space) No Sign
  # add leading zeros (in specific cases). with floats forces decimal point
  0 Left Pad with Zeros


  [Width]

  (number) Number of characters printed. Padded with spaces
        width is not specified but passed as an additional integer (no idea how this works)


  [Precision]

  .(number)  for integers number of digits, for floats number of digets after decimal  defaults to 1
  .*          precision not specified but passed as additional int value

  [Length]

  h short int
  I long int or unsigned int
  L Long Double (only floating points)

  % [Flags] [Width] [.Precision] [Length] [Specifier]



*/
