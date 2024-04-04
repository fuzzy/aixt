// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2022-2024
// License: MIT
module pin

// setup macro configures a pin's input/output mode. This is expanded in this way:
//   pin.setup(a7, pin.input)
//     |
//	   +-->	pin.setup(A, 7, 1)
//	          |
//            +-->	TRISAbits.TRISA7 = 1
#define pin__setup_(PORT, PIN, ...)   TRIS##PORT##bits.TRIS##PORT##PIN = __VA_ARGS__

#define pin__setup(NAME, MODE)  pin__setup_(NAME, MODE)